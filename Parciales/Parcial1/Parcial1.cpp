#include <iostream>
#include <sstream>

using namespace std;

typedef long int tipolista;
const int n = 100;

class Pila {

private:
    tipolista arreglo[n];
    int pos;

public:
    Pila() { pos = -1;  };

    void apilar(tipolista x);

    tipolista tope();

    void desapilar();

    bool pilavacia();
    void imprimir();
};

void Pila::imprimir() {

    if(pilavacia()){
        cout<<"Pila vacia, nada que imprimir"<<endl;
        return;
    }else{
        for(int i = pos; i>=0; i--){
            cout<<arreglo[i]<<" - ";
        }
        cout<<endl;
    }
}
void Pila::apilar(tipolista x) {
    if(pos != n) {
        pos++;
        arreglo[pos] = x;
    }else{
        cout<<"La pila esta llena"<<endl;
    }
}

tipolista Pila::tope() {

    /* Recordar que es de tipo LIFO */
    return arreglo[pos];
}

void Pila::desapilar() {
    if (pilavacia()) {
        cout<<"Error, pila vacia" << endl;
    } else {
        pos--;
    }
}

bool Pila::pilavacia() {
    return pos == -1;
}

int main() {
    string cadena, pf;
    Pila *p = new Pila();
    int n = 0;
    tipolista num;
    cout << endl << "Ingrese 3 numeros= ";
    while(n < 4){
        cin>>num;
        p->apilar(num);
        n++;
    }
    cout<<"Se almaceno como: ";p->imprimir();
    cout<<"El ultimo que ingreso fue: "<<p->tope()<<endl;
    cout<<"Ahora se borra uno"<<endl; p->desapilar();
    cout<<"El tope sera ahora: "<<p->tope()<<endl;
    cout<<"La pila quedo: ";p->imprimir();


    cout << endl;
    system("PAUSE");
    return 0;
}

