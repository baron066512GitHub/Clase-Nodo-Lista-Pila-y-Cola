#ifndef NODO_H
#define NODO_H

template <class Element>
class Nodo{
    private:
        Element info;
        Nodo<Element> *next;
    public:
        Nodo();
        Nodo(Element info, Nodo<Element> *next);
        // Getters
        Element getInfo();
        Nodo<Element>* getNext();
    
        // Setters
        void setInfo(Element info);
        void setNext(Nodo<Element>* next);
};

template <class Element>
Nodo<Element>::Nodo(){
    this->next = NULL;
    this->info = Element();

}

template <class Element>
Nodo<Element>::Nodo(Element info, Nodo<Element> *next){
    this->next = next;
    this->info = info;

}

template <class Element>
Element Nodo<Element>::getInfo(){
    return this->info;
}

template <class Element>
Nodo<Element>* Nodo<Element>::getNext(){
    return this->next;
}

template <class Element>
void Nodo<Element>::setInfo(Element info){
    this->info = info;
}

template <class Element>
void Nodo<Element>::setNext(Nodo<Element>* next){
    this->next = next;
}


#endif