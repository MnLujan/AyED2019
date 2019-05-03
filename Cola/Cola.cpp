#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;
const int n = 100;

class Cola {
private:
    /* arreglo que se utilizara para almacenar datos */
    int arreglo[n];

    /* Se utilizan para saber el primero y el ultimo dentro de la cola */
    int ult;
    int pri;
public:
    Cola() { ult= -1; pri = -1;};

    int tope();

    bool colavacia();

    void encolar(int a);

    void desencolar();

    int ultimo();

    void imprimir();
};

//-------- Metodos de Cola --------------------

int Cola::tope() {
    return arreglo[pri];
}

void Cola::encolar(int a) {

/* Se checkea que la cola no se encuentre llena */
    if((pri == 0 && ult == n-1) || (ult == (pri-1)%(n-1))){
        cout<<"Cola llena"<<endl;
        return;

        /* Se verifica si es el primer elemento a encolar */
    }else if(pri == -1){
        pri = ult = 0;
        arreglo[ult] = a;

        /* Se verifica que ult no se ecuentre al final de la cola y pri en otro lugar, lo cual indica q hay lugar */
    }else if(ult == n-1 && pri != 0){
        ult = 0;
        arreglo[ult];

        /* Nada de lo anterior se cumple, se incrementa ult y agrega el dato */
    }else{
        ult++;
        arreglo[ult] = a;
    }

}

void Cola::desencolar() {

    if(pri == -1){
        cout<<"Cola vacia, nada que borrar"<<endl;
        return;

        /* La cola esta vacia, se resetean los valores */
    }else if(pri == ult){
        pri = -1;
        ult = -1;

        /* Si pri esta al fondo de la cola, se la vuelve al principio eliminando el dato */
    }else if(pri == n-1){
        pri = 0;

        /* Caso contrario se incrementa el valor y el primerio se pierde */
    }else{
        pri++;
    }
}

int Cola::ultimo() {
    if(ult == -1){
        cout<<"Cola vacia"<<endl;
        return EXIT_FAILURE;
    }else{
        return arreglo[ult];
    }
}

bool Cola::colavacia() {
    return pri == -1;
}

void Cola::imprimir() {

    if(colavacia()){
        cout<<"Cola vacia, nada q imprimir"<<endl;
        return;
    }else{
        int i = pri;
        for(i; i<= ult ; i++){
            cout<<arreglo[i]<<" - ";
        }
        cout<<" >>>"<<endl;
    }

}

//------------------------------------------------------
int main() {
    Cola *c = new Cola();
    if (c->colavacia()) cout << endl << "La cola esta VACIA" << endl << endl;
    c->encolar(15);
    c->encolar(2);
    c->encolar(3);
    c->imprimir();
    cout << "en cola:" << c->tope() << endl;
    cout << "ultimo ingresado= " << c->ultimo() << endl;
    cout<<"Desencolar"<<endl;
    if (!c->colavacia())c->desencolar();

    cout << "en cola:" << c->tope() << endl;
    c->imprimir();
    cout<<"Desencolar"<<endl;
    if (!c->colavacia())c->desencolar();

    cout << "en cola:" << c->tope() << endl;
    c->imprimir();
    cout<<"Desencolar"<<endl;
    if (!c->colavacia())c->desencolar();
    cout << "en cola:" << c->tope() << endl;
    c->imprimir();

    c->encolar(44);
    cout << "en cola:" << c->tope() << endl;
    c->imprimir();
    cout<<"Desencolar"<<endl;
    if (!c->colavacia())c->desencolar();
    c->imprimir();

    system("PAUSE");
    return EXIT_SUCCESS;

}