#ifndef PILA_H
#define PILA_H

#include "lista.h"

template <class Element>
class Pila : public Lista<Element>{
    public:
        Pila() : Lista<Element>(){}
        void apilar(Element element);
        void desapilar();
        Element getTope();
        void vaciar();
        bool esVacia();
};

template <class Element>
void Pila<Element>::apilar(Element element){
    this->insertar(element,0);
}

template <class Element>
void Pila<Element>::desapilar(){
    this->eliminar(0);
}

template <class Element>
Element Pila<Element>::getTope(){
    return this->consultar(0);
}

template <class Element>
void Pila<Element>::vaciar(){      
    Lista<Element>::vaciar();
}

template <class Element>
bool Pila<Element>::esVacia(){
    return (Lista<Element>::esVacia());
}

#endif