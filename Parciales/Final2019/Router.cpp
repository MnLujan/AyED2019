//
// Created by mlujan on 4/3/20.
//

#include <libzvbi.h>
#include "Router.h"

using namespace std;

/**
 * @brief Inicializa las variables, contrsuctor sin parametros. (Constructor 1)
 */
Router::Router() {
    IPRouter = 0;
    N_R = 0;
    this->log = nullptr;
}

/**
 * @brief Se inicializan las variables con los parametros pasados. (Constructor 2).
 */
Router::Router(uint16_t ip, uint8_t nr, Logger *l) {
    IPRouter = ip;
    N_R = nr;

    ///@brief Lista de router vecinos
    this->Rvecinos = new Lista<Router *>;

    ///@brief Lista de Maquinas conectadas
    this->Maqui = new Lista<Maquina *>;

    ///@brief Lista de Input a enviar
    this->Input = new Lista<Packages *>;

    ///@brief Lista de paginas armadas para las maquinas
    this->Pag = new Lista<Pagina *>;

    ///@brief Lista de colas de salida del router
    this->BuffersSalida = new Lista<Buffer *>;

    ///@brief Lista de Listas de paquetes a compaginar para armar las paginas a entregar
    this->package2pag = new Lista<Lista<Packages *> *>;

    ///@brief Puntero al objeto log, necesario para escribir en el txt.
    this->log = l;
}

/**
 * @brief Metodo encargado de retornar el numero de Ip del router.
 * @return uint8_t IPRouter
 */
uint16_t Router::getIpRouter() const {
    return IPRouter;
}


/**
 * @brief Metodo encargado de retornar el el puntero a la lista donde se encuentran
 * almacenado los Input.
 * @return Puntero de tipo lista. Input.
 */
Lista<Packages *> *Router::getInputList() {
    if (Input != nullptr) {
        return Input;
    } else {
        return nullptr;
    }
}

/**
 * @brief Metodo encargado de devolver el puntero a una lista que almacena las maquinas
 * que se encuentran conectadas al router
 * @return puntero de Lista, Maqui.
 */
Lista<Maquina *> *Router::getMaquiList() {
    if (Maqui != nullptr) {
        return Maqui;
    } else {
        return nullptr;
    }
}

/**
 * @brief  Metodo encargado de devolver el numero del router.
 * @return entero de 8 bits que indica el numero del router. N_R.
 */
uint8_t Router::getN_R() const {
    return N_R;
}

/**
 * @brief Metodo encargado de recibir la pagina y desarmarla en los Input necesarrios para transimitir.
 * Estos los coloca en la cola de entrada del router.
 **/
void Router::toRecivePag(Pagina *p) {
    string data = p->getDato();
    for (int i = 0; i < data.size(); i++) {
        char dataAux = data[i];
        auto auxPackage = new Packages(dataAux, p->getOrigen(), p->getDestino(), i, data.size(), p->getIDpag());

        /* Lo agrego a la cola de entrada del router */
        this->Input->Add(auxPackage);
    }

}

/**
 * @brief Metodo encargado de conectar un nuevo router vecino
 * @param R Router a conectar
 */
void Router::linkRouter(Router *R) {
    this->Rvecinos->Add(R);
}

/**
 * @brief Metodo encargado de conectar una maquina al router actual.
 * @param M maquina a conectar
 */
void Router::linkMachine(Maquina *M) {
    this->Maqui->Add(M);
}

/**
 * @brief Metodo encargado de consultar si hay elementos en la cola de entrada.
 * @return True en caso de que la cola este vacia, False, caso contrario
 */
bool Router::StateInput() {
    return this->getInputList()->esvacia();
}

/**
 * @brief Metodo encargado de recibir un paquete proveniente de otro Router, identificar para quien es y
 * colocarlo en la cola correspondiente. En caso de que no pertenezca a ninguna maquina hija, se coloca en la cola
 * de entrada del Router, para despues ver que hacer.
 */
void Router::toRecivePackage(Packages *newPack) {
    for (int i = 0; i < this->getMaquiList()->get_size(); i++) {
        /* Verifico si el paquete recibido es para alguna de las maquinas conectadas */
        if (this->getMaquiList()->get_nodo(i)->getdato()->getIP() == newPack->getDestino()) {
            encolar(newPack, 0);
            string msj =
                    "\nLlegada | R" + to_string(this->getN_R()) + " | N°Paquete: " + to_string(newPack->getFrame()) +
                    " Pag N°" + to_string(newPack->getIdPag()) + " | Dato: " + newPack->getletra() +
                    " | Destino: " +
                    to_string(newPack->getDestino());

            cout << msj << endl;

            this->log->write(msj);

            return;
        }
    }
    /* En caso de que no sea para alguna maquina hija se envia a la cola de entrada */
    encolar(newPack, newPack->getDestino());
}

/**
 * @brief Metodo encargado de buscar y colocar el paquete en la cola de paquetes a compaginar o colocar el
 * paquete en la cola de entrada.
 * @param newPackage Puntero al paquete a encolar
 * @param ip direccion del paquete.
 */
void Router::encolar(Packages *newPackage, int ip) {
    if (ip == 0) {
        bool match = false;
        for (int i = 0; i < this->package2pag->get_size(); i++) {
            /* Nodo temporal para realizar las consultas */
            auto *temp = this->package2pag->get_nodo(i)->getdato()->get_dato();
            /* Verifico que el IDpag, origen y destino correspondan con alguno de los paquetes. Los tres deben coincidir */
            if (temp->getIdPag() == newPackage->getIdPag() &&
                temp->getDestino() == newPackage->getDestino() &&
                temp->getOrigen() == newPackage->getOrigen()) {
                this->package2pag->get_nodo(i)->getdato()->Add(newPackage);
                match = true;
            }
        }
        if (!match) {
            /* En caso de no haber encontrado el paquete en la lista, lo agrego */
            auto listNew = new Lista<Packages *>;
            listNew->Add(newPackage);
            this->package2pag->Add(listNew);
        }
    } else {
        /* En caso de q no sea para mi, lo mando a la cola de entrada y verifico para quien es, para redireccionar */
        this->getInputList()->Add(newPackage);
    }
}

/**
 * @brief Metodo encargado de agregar un Buffer de conexion en el router.
 */
void Router::agreeBuffer(Buffer *newB) {
    this->BuffersSalida->Add(newB);
}

/**
 * @brief Metodo encargado de consultar la cola de salida para la direccion de ip pasada por parametro.
 * @param ip direccion de ip que corresponde al router asociado
 * @return numero entero con el tamaño de la cola
 */
int Router::getSizeQueueOut(uint16_t ip) {
    if (!this->BuffersSalida->esvacia()) {/* Busco en todos los buffers del router */
        for (int i = 0; i <
                        this->BuffersSalida->get_size(); i++) { /* Verifico si el buffer corresponde a la direccion de IP recibida */
            if (this->BuffersSalida->get_nodo(i)->getdato()->getID() == ip) {
                if (!this->BuffersSalida->get_nodo(
                        i)->getdato()->getLista()->esvacia()) { /* Si corresponde y no esta vacio, pregunto el largo */
                    return this->BuffersSalida->get_nodo(i)->getdato()->getLista()->get_size();
                } else {
                    return 0;
                }
            }
        }
    } else {
        return 0;
    }
    return 0;
}

/**
 * @brief Metodo encargado de devolver la lista de lista de paquetes a compaginar
 * @return puntero a lista de lista
 */
Lista<Lista<Packages *> *> *
Router::getListPackages() {
    return this->package2pag;
}

/**
 * @brief Metodo encargado de devolver la lista de paquetes correspondientes al buffer con
 * la direccion Ip pasada como paramatero
 * @param ip direccion Ip del buffer
 * @return puntero a la lista de paquetes.
 */
Buffer *Router::getQueueOut(uint16_t ip) {
    if (!this->BuffersSalida->esvacia()) {
        auto *temp = this->BuffersSalida->getCabeza();
        for (int i = 0; i < this->BuffersSalida->get_size(); ++i) {
            if (temp->getdato()->getID() == ip) {
                return temp->getdato();
            } else {
                temp = temp->getnext();
            }
        }
    } else {
        return nullptr;
    }
    return nullptr;
}

/**
 * @brief Metodo encargado de devolver la lista de buffer del router
 * @return puntero a lista de buffers
 */
Lista<Buffer *> *Router::getListQueue() {
    return this->BuffersSalida;
}

/**
 * @brief Metodo encargado de recibir una lista de paqutes y ordenarlos para posteriormente
 * armar una pagina
 * @param paquetes lista de paquetes a ordenar
 * @return lista de paquetes ordendos
 */
Lista<Packages *> *Router::Order(Lista<Packages *> *paquetes) {
    auto *aux = paquetes;
    bool change = true;
    while (change) {
        change = false;
        for (int i = 0; i < aux->get_size() - 1; ++i) {
            Packages *pack1 = aux->get_nodo(i)->getdato();
            Packages *pack2 = aux->get_nodo(i + 1)->getdato();
            if (pack1->getFrame() > pack2->getFrame()) {
                aux->Swap(i, i + 1);
                change = true;
            }
        }
    }
    return aux;
}

/**
 * @brief Metodo encargado de obtener todos los paqutes necesarios para la generacion de una pagina.
 * @param paquetes lista de paquetes a compaginar
 */
void Router::packToPag(Lista<Packages *> *paquetes) {
    //Obtengo la lista de paquetes ordenados
    auto packOrder = this->Order(paquetes);
    string auxPag;
    auto *aux = packOrder->get_nodo(0)->getdato();
    uint16_t Ip_origen = aux->getOrigen();
    uint16_t Ip_Dest = aux->getDestino();
    uint8_t numPag = aux->getIdPag();

    for (int i = 0; i < packOrder->get_size(); ++i) {
        auxPag += packOrder->get_nodo(i)->getdato()->getletra();
    }

    auto *PagGen = new Pagina(auxPag, Ip_origen, Ip_Dest, numPag);
    /* Envio la paquina a la maquina correspondiente */
    this->getMachine(PagGen->getDestino())->toReceive(PagGen);

    this->Pag->Add(PagGen);

}

/**
 * @brief Metodo encargado de buscar entre las maquinas hijas.
 * @param ip de la maquina buscada
 * @return puntero a la maquina buscada
 */
Maquina *Router::getMachine(uint16_t ip) {
    for (int i = 0; i < this->getMaquiList()->get_size(); ++i) {
        if (this->getMaquiList()->get_nodo(i)->getdato()->getIP() == ip) {
            return this->getMaquiList()->get_nodo(i)->getdato();
        }
    }
    return nullptr;
}