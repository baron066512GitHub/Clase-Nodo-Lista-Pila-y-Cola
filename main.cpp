#include "nodo.hpp"
#include <iostream>

int main() {
    // Uso del nodo con int
    Nodo<int> nodo1(42, nullptr);
    Nodo<int> nodo2(100, &nodo1);

    std::cout << "Info nodo2: " << nodo2.getInfo() << "\n";
    std::cout << "Next nodo2: " << nodo2.getNext()  << "\n";

    return 0;
}