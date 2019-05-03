#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/*
Dado un arreglo de n valores desordenados obtenga otro arreglo (no debe modificar el original) con los datos ordenados.

Para ello deberá usar el siguiente algoritmo

1) Tome el primer elemento del arreglo original e insertelo en el arreglo de resultado

2) Tome el siguiente elemento del original e insertelo en el arreglo de resultado en la posición correcta (antes del primer elemento si es menor o despues si es mayor)

3) Repita el paso 2 hasta que termine con todos los valores

Plante dos soluciones, la primera como una función iterativa y la segunda usando recursión
 */