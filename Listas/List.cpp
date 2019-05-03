#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

class Nodo {
private:
    int dato;
    Nodo *next;
public:
    Nodo() { next = NULL; };

    Nodo(int a) {
        dato = a;
        next = NULL;
    };

    void set_dato(int a) { dato = a; };

    void set_next(Nodo *n) { next = n; };

    int get_dato() { return dato; };

    Nodo *get_next() { return next; };

    bool es_vacio() { return next == NULL; }
};

class Lista {
private:
    Nodo *czo;
public:
    Lista() { czo = new Nodo(); }; //Crea un nodo, corre el constructor Nodo() de la calse nodo. New cumple la misma funcion que malloc.
    Lista(Nodo *n) { czo = n; };

    //~Lista(void);
    void add(int d);

    bool esvacia(void); //el void se puede obviar, es lo mismo poner esvacia()
    int cabeza(void); //devuelve el primer elemento de la lista
    Lista *resto(void); //devuelve un puntero al resto de la lista despues de la cabeza
    string toPrint(string p);

    int suma(int i);

    int size();

    void borrar_last();

    void borrar_cabeza();

    void concatenar(Lista *l); //Terminar

    Lista *copy(); //Terminar
};

Lista *Lista::copy() {
    Lista *copy = new Lista;
    copy->concatenar(this);
    return copy;
}

/*Corregido, faltaba el return despues de llegar al fondo de la lista*/
void Lista::concatenar(Lista *l) {

    if (l->esvacia()) {
        return;
    } else {
        this->concatenar(l->resto());
        this->add(l->cabeza());
    }

}

void Lista::borrar_cabeza() {

    Nodo *temp = czo;
    if (esvacia()) {
        cout << "Error, la lista se encuentra vacia" << endl;
        return;
    } else {

        czo = czo->get_next();
        delete (temp);

    }
}

void Lista::borrar_last() {

    if (!this->esvacia()) {
        if (czo->get_next()->get_next() == NULL) { //get_next()->get_next() == NULL
            delete (czo->get_next());
            czo->set_next(NULL);
            return;
        } else {
            this->resto()->borrar_last();

        }

    } else { return; }
}

int Lista::size() {

    if (this->esvacia()) {
        return 0;
    } else {
        return 1 + this->resto()->size();
    }
}

void Lista::add(int d) {
    Nodo *nuevo = new Nodo(d);
    nuevo->set_next(czo);
    czo = nuevo;
}

bool Lista::esvacia(void) {
    return czo->es_vacio();
}

int Lista::cabeza(void) {
    if (esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        return -1;
    }
    return czo->get_dato();
}

Lista *Lista::resto(void) //me devuelve el resto de la lista despues de la cabeza.
{
    Lista *l = new Lista(czo->get_next()); //genera un puntero local, q crea una sub lista.
    return (l);
}

string Lista::toPrint(string p) {
    if (this->esvacia()) {
        return p;
    } else {
        std::ostringstream stm; //stm puede ser cualquier numero. En esta linea se define un buffer, sera util para mandarle info. Actua igual q un cout.
        stm << this->cabeza() << "-" << this->resto()->toPrint(p);
        //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
        return stm.str();
    }
}

int Lista::suma(int i) {
    cout << " i al entrar= " << i << endl;
    if (this->esvacia()) {
        return i;
    } else {

        cout << "this->cabeza()= " << this->cabeza() << endl;
        return this->resto()->suma(i + this->cabeza());
    }
}

int main() {
    Lista *l = new Lista();
    Lista *r = new Lista();
    Lista *l2;
    l->add(11);
    l->add(22);
    l->add(33);
    l->add(44);
    l->add(55);
    r->add(4);
    r->add(6);
    r->add(1);
    r->add(2);
    cout << l->toPrint("fin") << endl;
    //cout << "suma:" << l->suma(0) << endl;
    cout << "size: " << l->size() << endl;
    cout << "Se borra el ultimo elemento de la lista." << endl;
    l->borrar_last();
    cout << "Queda: " << l->toPrint("fin") << endl;
    cout << "size: " << l->size() << endl;
    cout << "Borro la cabeza" << endl;
    l->borrar_cabeza();
    cout << "Vuelvo a imprimir para corroborar: " << endl;
    cout << l->toPrint("fin") << endl;
    cout << "size: " << l->size() << endl;
    cout << "Metodo concatenar: " << endl;
    r->concatenar(l);
    cout << r->toPrint("fin") << endl;
    cout<<"Metodo Copiar: Se copio L en L2"<<endl;
    l2 = l->copy();
    cout << l2->toPrint("fin");

    //system("PAUSE");
    return EXIT_SUCCESS;
}
