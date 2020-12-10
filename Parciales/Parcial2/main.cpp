#include <iostream>
#include <cstdlib>
#include <fstream>
#include "CombinedStructure.h"

using namespace std;

int main() {
    auto *l = new CombinedStructure();
    fstream input;
    string line;
    string tmp;
    int r = 0;
    input.open("texto");

    tmp = "--> Se procede a leer el texto, se imprimiran por pantalla en el orden que se van leyendo desde el texto: \n\n";
    cout << tmp;
    /* Se arma la estrucutra combinada */
    while (input >> line) {
        /* Paso el string a minuscula */
        for (int i = 0; i < line.length(); i++) {
            line[i] = tolower(line[i]);
            if (line[i] == '.' || line[i] == ',' || line[i] == '!' || line[i] == '?') {
                line[i] = ' ';
            }
        }
        /* Agrego la palabra a la estructura */
        cout << line + " ";
        r++;
        if (r == 30) {
            r = 0;
            cout << endl;
        }
        l->AddPal(line);
    }

    input.close();

    tmp = "\n\n-->Por ultimo se genera un nuevo texto con las palabras ordenaras alfabeticamente y por repeticiones\n";
    cout << tmp;

    /* Llamo al metodo QuickSort */
    l->OrdenaQS();

    /* Creo el texto con las palabras ordenadas alfabeticamente y por numero de repeticiones */
    ofstream fs("Texto-Ordenado.txt");
    fs << "-Alfabeticamente:" << endl;
    for (int i = 0; i < l->GetSizeStruct(); i++) {
        fs << l->GetNodoAlf(i)->GetDataPal() << " ";
    }
    fs << endl;
    fs << "-Repeticiones:" << endl;
    for (int j = 0; j < l->GetSizeStruct(); ++j) {
        fs << l->GetNodoSwap(j)->GetDataPal() << " ";
    }
    fs << endl;
    fs << "-Comparaciones: \nInsercion por lista: " << l->compLIST << " / Insercsion ABB: " << l->compABB
       << " / Quicksort: " << l->compQS << endl;
    fs.close();

    tmp = "-Comparaciones: \nInsercion por lista: " + to_string(l->compLIST) + " / Insercsion ABB: " +
          to_string(l->compABB) + " / Quicksort: " +
          to_string(l->compQS);
    cout << tmp;

    return EXIT_SUCCESS;
}