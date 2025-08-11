#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lista.h"
#include "pila.h"
#include "cola.h"

int main() {
    srand(time(0)); // Inicializa la semilla aleatoria ( por si necesitas números aleatorios)
    // Crear una instancia de la lista
    Cola<int> cola;

    cola.encolar(1);
    cola.encolar(2);    
    cola.encolar(3);
    cola.encolar(4);    
    cola.encolar(5);

    Cola<Cola<int>> colaDeColas;
    colaDeColas.encolar(cola);
    colaDeColas.encolar(cola);
    colaDeColas.encolar(cola);

    colaDeColas.mostrar();

    return 0;
}

