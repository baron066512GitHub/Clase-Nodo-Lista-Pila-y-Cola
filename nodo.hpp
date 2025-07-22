#ifndef NODO_HPP
#define NODO_HPP
#include <iostream>


template <class Element>
class Nodo{
    private:
        Element info;
        Nodo<Element> *next;
    public:
        Nodo();
        Nodo(Element info, Nodo<Element> *next);
        ~Nodo();
        // Getters
        Element getInfo();
        Nodo<Element>* getNext();
    
        // Setters
        void setInfo(Element info);
        void setNext(Nodo<Element>* next);


};

#include "nodo.cpp"

#endif