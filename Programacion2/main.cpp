#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lista.h"
#include "pila.h"
#include "cola.h"
#include "extras.h"

using namespace std;

int main() {
    srand(time(0)); // Inicializa la semilla aleatoria ( por si necesitas números aleatorios)
    //cd /mnt/c/Users/windows/OneDrive/Desktop/Programacion2
    Lista<Lista<string>> contenedor;
    contenedor = leerListasVertical();
    mostrarColumnas(contenedor);

    Lista<string> nombres;
    nombres = obtenerColumna(contenedor, 3); // Para la columna 1 (índice 0)
    nombres.mostrar();

    


    return 0;
}

