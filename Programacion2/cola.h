#ifndef COLA_H
#define COLA_H

#include "lista.h"

template <class Element>
class Cola : public Lista<Element> {
    public: //Methods
    Cola() : Lista<Element>(){};

    void encolar(Element element);
    void desencolar();
    Element getFrente();
    bool esVacia();
    void vaciar();
    void invertir();

};

template <class Element>
void Cola<Element>::encolar(Element element) {
    this->insertar(element, this->getLength());
}

template <class Element>
void Cola<Element>::desencolar() {  
    this->eliminar(0);
}

template <class Element>
Element Cola<Element>::getFrente() {    
    return this->consultar(0);
}   

template <class Element>
bool Cola<Element>::esVacia() {
    return this->Lista<Element>::esVacia();
}   

template <class Element>    
void Cola<Element>::vaciar() {
    this->Lista<Element>::vaciar();
}

template <class Element>
void Cola<Element>::invertir() {    
    this->Lista<Element>::invertir();
}

#endif