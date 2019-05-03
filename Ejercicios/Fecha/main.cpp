#include <iostream>
#include <stdlib.h>

using namespace std;

class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha(int d, int m, int a);

    void set_dia(int d) { dia = d; }

    void set_mes(int m) { mes = m; }

    void set_anio(int a) { anio = a; }

    int get_dia() { return dia; }

    int get_mes() { return mes; }

    int get_anio() { return anio; }

    void imprimir();

    void suma(int);
};

/**
 * Imprimir muestra en pantalla la fecha.
 */
void Fecha::imprimir() {
    cout << "La fecha es: " << endl;
    cout << get_dia() << "/" << get_mes() << "/" << get_anio() << endl;

}

/**
 * Constructur de un objeto fecha
 * @param d dias
 * @param m meses
 * @param a años
 */
Fecha::Fecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

/**
 * suma modifica un objeto de la clase fecha.
 * @param n dias que se quieren sumar a fecha.
 */
void Fecha::suma(int n) {
    cout<<"Se prodece a sumar por la cantidad de "<<n<<" dias"<<endl;
    int temp = n + get_dia();
    while (true) {
        if (temp > 28 && get_mes() == 2) {

            set_mes(get_mes() + 1);
            set_dia(temp = temp - 28);

        }
        if (temp > 30) {
            int mes = get_mes();
            if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
                set_mes(mes + 1);
                set_dia(temp = temp - 30);
            }
        }
        if (temp > 31) {
            int mes = get_mes();
            if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
                set_mes(mes + 1);
                set_dia(temp = temp - 31);
            }
        } else {
            set_dia(temp);
        }
        if (get_mes() > 12) {
            set_anio(get_anio() + 1);
            set_mes(1);
        }
        if (get_dia() <= 31) {
            break;
        }
    }
}

int main() {
    Fecha *f = new Fecha(2, 4, 2015);
    f->imprimir();
    int n;
    cout<<"Ingrese la cantidad de dias a sumar: ";cin>>n;
    f->suma(n);
    f->imprimir();
    return 0;
}