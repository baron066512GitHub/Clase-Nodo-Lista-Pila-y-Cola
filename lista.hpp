#ifndef LISTA_HPP
#define LISTA_HPP
#include <iostream>
#include "nodo.hpp"


template <class Element>
class Lista{
    private:
        int length;
        Nodo<Element> *head, *tail;

    public:
        // Constructores
        Lista();
        Lista(int length, Nodo<Element> *head, Nodo<Element> *tail);
        Lista(const Lista<Element>& target);

        // Destructor
        ~Lista();

        // Getters
        Nodo<Element>* getHead();
        Nodo<Element>* getTail();
        int getLength();
    
        // Setters
        void setHead(Nodo<Element> *head);
        void setTail(Nodo<Element> *tail);
        void setLength(int length);

        // Metodos
        void insertar(Element element, int pos);
        void mostrar();
        void eliminar(int pos);
        void invertir();
        Element consultar(int pos);
        void intercambiar(int pos1, int pos2);
        int buscar(Element element);
        void vaciar();
        void copiar(const Lista<Element>& target);
        bool esVacia();
        int longitud();
        void mergeSort();

        // OPERADORES
        
        // Operador de asignación
        Lista<Element>& operator=(const Lista<Element>& otra);
        
        // Operadores de comparación
        bool operator==(const Lista<Element>& otra) const;
        bool operator!=(const Lista<Element>& otra) const;
        
        // Operador de concatenación
        Lista<Element> operator+(const Lista<Element>& otra) const;
        
        // Operador de acceso
        Element& operator[](int pos);
        Element operator[](int pos) const;  // Devuelve por valor en versión const

        

        // Operador de flujo de salida
        friend std::ostream& operator<<(std::ostream& os, const Lista<Element>& lista) {
            Nodo<Element>* actual = lista.head;
            os << "[";
            while (actual != NULL) {
                os << actual->getInfo();
                if (actual->getNext() != NULL) {
                    os << " -> ";
                }
                actual = actual->getNext();
            }
            os << "]";
            return os;
        }

};

#include "lista.cpp"

#endif
