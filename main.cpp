#include <iostream>
#include "lista.hpp"

template <class Element>
void quicksort(Lista<Element>& lista, int low, int high);

template <class Element>
int partition(Lista<Element>& lista, int low, int high);

int main() {
    // Crear una instancia de la lista
    Lista<int> miLista;
    
    // Insertar algunos elementos
    miLista.insertar(5, 0);
    miLista.insertar(2, 1);
    miLista.insertar(8, 2);
    miLista.insertar(1, 3);
    miLista.insertar(9, 4);
    miLista.insertar(4, 5);
    
    // Mostrar la lista original
    cout << "Lista original: ";
    miLista.mostrar();
    
    // Llamar a quicksort para ordenar la lista
    quicksort(miLista, 0, miLista.longitud() - 1);
    
    // Mostrar la lista ordenada
    cout << "Lista ordenada: ";
    miLista.mostrar();
    
    return 0;
}

// Función principal de Quicksort
template <class Element>
void quicksort(Lista<Element>& lista, int low, int high) {
    if (low < high) {
        int pi = partition(lista, low, high);
        
        quicksort(lista, low, pi - 1);
        quicksort(lista, pi + 1, high);
    }
}

// Función de partición
template <class Element>
int partition(Lista<Element>& lista, int low, int high) {
    Element pivot = lista.consultar(high);
    int i = low - 1;
    
    for (int j = low; j < high; ++j) {
        if (lista.consultar(j) <= pivot) {
            i++;
            lista.intercambiar(i, j);
        }
    }
    lista.intercambiar(i + 1, high);
    return i + 1;
}
