#include "lista.hpp"
#include <iostream>
using namespace std;

template <class Element>
Lista<Element>::Lista(){
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}

template <class Element>
Lista<Element>::Lista(int length, Nodo<Element> *head, Nodo<Element> *tail){
    this->head = head;
    this->tail = tail;
    this->length = length;
}

template <class Element>
Lista<Element>::Lista(const Lista<Element>& target){
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;

    if(target.head != NULL){
        Nodo<Element> *actual = target.head;
        Nodo<Element> *newNodo = new Nodo<Element>(actual->getInfo(), NULL);
        this->head = newNodo;
        this->tail = newNodo;
        this->length++;
        actual = actual->getNext();

        while(actual != NULL){
            newNodo = new Nodo<Element>(actual->getInfo(), NULL);
            this->tail->setNext(newNodo);
            this->tail = newNodo;
            this->length++;
            actual = actual->getNext();
        }
    }
}

template <class Element>
Lista<Element>::~Lista(){
    Nodo<Element>* actual = this->head;
    while(actual != NULL){
        Nodo<Element>* siguiente = actual->getNext();
        delete actual;
        actual = siguiente;
    }
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}

template <class Element>
Nodo<Element>* Lista<Element>::getTail(){
    return this->tail;
}

template <class Element>
Nodo<Element>* Lista<Element>::getHead(){
    return this->head;
}

template <class Element>
int Lista<Element>::getLength(){
    return this->length;
}

template <class Element>
void Lista<Element>::setHead(Nodo<Element> *head){
    this->head = head;
}

template <class Element>
void Lista<Element>::setTail(Nodo<Element> *tail){
    this->tail = tail;
}

template <class Element>
void Lista<Element>::setLength(int length){
    this->length = length;
}

template <class Element>
void Lista<Element>::insertar(Element element, int pos){
    Nodo<Element> *newNodo =  new Nodo<Element>(element, NULL);                      // CREO EL NODO NUEVO, CONSTRUYO Y LE DOY SUS VALORES CORRESPONDIENTES
    Nodo<Element> *aux;
    int i;

    if(pos == 0){
        newNodo->setNext(this->head);
        this->head = newNodo;
        if (this->tail == NULL) { // Si la lista estaba vacía
            this->tail = newNodo;
        }

    }else{

        if(pos == this->length){
            this->tail->setNext(newNodo);
            this->tail = newNodo;

        }else{
            aux = this->head;
            for ( i = 0; i < pos; i++){
                aux = aux->getNext();
            }

            newNodo->setNext(aux->getNext());
            aux->setNext(newNodo);
        }
    }
    this->length++;
}

template <class Element>
void Lista<Element>::mostrar(){
    Nodo<Element> *aux;

    if (this->length > 0){
        aux = this->head;
        while(aux != NULL){    
            cout << aux->getInfo() << " -> ";
            aux = aux->getNext();
        }
        cout << "NULL" << endl; 

    }else{
        cout << "Lista vacia" << endl;
    }
}

template <class Element>
void Lista<Element>::eliminar(int pos){
    Nodo<Element> *actual, *anterior;

    actual = this->head;
    anterior = NULL;

    if (this->length > 0){
        if(pos < this->length){
            if(pos == 0){
                this->head = actual->getNext();
                delete actual;

                if(this->head == NULL){
                    this->tail = NULL;
                }
                
            }else{

                for (int i = 0; i < pos; ++i) {
                    anterior = actual;
                    actual = actual->getNext();
                }

                anterior->setNext(actual->getNext());

                if (actual == this->tail) {
                    this->tail = anterior;
                }
        
                delete actual;
            
            }
            this->length--;
        }else{
            cout << "Posicion invalida para Borrar" << endl;
        }
    }else{
        cout << "Lista vacia no se puede borrar" << endl;
    }
}

template <class Element>
void Lista<Element>::invertir(){

    if(this->length > 0){
        Nodo<Element>* anterior = NULL;
        Nodo<Element>* actual = this->head;
        Nodo<Element>* siguiente = NULL;

        while (actual != NULL) {
            siguiente = actual->getNext();
            actual->setNext(anterior);
            anterior = actual;
            actual = siguiente;
        }
        this->tail = this->head;
        this->head = anterior;
    }
    
}

template <class Element>
Element Lista<Element>::consultar(int pos){
    if(pos >= 0 && this->length > 0){
        Nodo<Element> *aux;
        aux = this->head;
       
        for (int i = 0; i < pos; i++){
            aux = aux->getNext();
        }
        return aux->getInfo();
    }
}

template <class Element>
void Lista<Element>::intercambiar(int pos1, int pos2){

    if (this->length <= 1) {
        cout << "No se puede intercambiar, lista muy corta" << endl;
        return;
    }

    if(this->length > 0){
        if(pos1 >= 0 && pos1 < this->length && pos2 >= 0 && pos2 < this->length && pos1 != pos2){
            Nodo<Element> *ptrPos1, *ptrPos2, *anterior1, *anterior2;
            ptrPos1 = this->head;
            ptrPos2 = this->head;
            anterior1 = NULL;
            anterior2 = NULL;

            for (int i = 0; i < pos1; i++){
                anterior1 = ptrPos1;
                ptrPos1 = ptrPos1->getNext();
            }

            for (int i = 0; i < pos2; i++){
                anterior2 = ptrPos2;
                ptrPos2 = ptrPos2->getNext();
            }

            if (pos2 == pos1 + 1) {

                if (anterior1 != NULL) {
                    anterior1->setNext(ptrPos2);
                }else{
                    this->head = ptrPos2;
                }

                ptrPos1->setNext(ptrPos2->getNext());
                ptrPos2->setNext(ptrPos1);

            }else{ 

                if (anterior1 != NULL) {
                    anterior1->setNext(ptrPos2);
                } else {
                    this->head = ptrPos2;
                }

                if (anterior2 != NULL) {
                    anterior2->setNext(ptrPos1);
                } else {
                    this->head = ptrPos1;
                }

                Nodo<Element> *temp = ptrPos1->getNext();
                ptrPos1->setNext(ptrPos2->getNext());
                ptrPos2->setNext(temp);

            }
        }
    }
}

template <class Element>
int Lista<Element>::buscar(Element element){
    if(this->length > 0){
        Nodo<Element> *aux;
        int contador = 0, encontrado = 0;

        aux = this->head;
        
        while(!encontrado){
            if(element == aux->getInfo()){
                encontrado = 1;
            }else{
                aux = aux->getNext();
                contador++;    
            }

            if (aux == NULL){
                contador = -1;
                encontrado = 1;
            }
        }
        return contador;
    }
    
}

template <class Element>
void Lista<Element>::vaciar(){
    Nodo<Element>* actual = this->head;
    while(actual != NULL){
        Nodo<Element>* siguiente = actual->getNext();
        delete actual;
        actual = siguiente;
    }
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}

template <class Element>
void Lista<Element>::copiar(const Lista<Element>& target){
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;

    if(target.head != NULL){
        Nodo<Element> *actual = target.head;
        Nodo<Element> *newNodo = new Nodo<Element>(actual->getInfo(), NULL);
        this->head = newNodo;
        this->tail = newNodo;
        this->length++;
        actual = actual->getNext();

        while(actual != NULL){
            newNodo = new Nodo<Element>(actual->getInfo(), NULL);
            this->tail->setNext(newNodo);
            this->tail = newNodo;
            this->length++;
            actual = actual->getNext();
        }
    }
}

template <class Element>
bool Lista<Element>::esVacia(){
    return this->length == 0;
}

template<class Element>
int Lista<Element>::longitud(){
    return this->length;
}

template <class Element>
void Lista<Element>::mergeSort() {
    // Verificamos si necesitamos ordenar (más de 1 elemento)
    if (this->length > 1) {
        // Paso 1: Dividir la lista en dos mitades
        Nodo<Element>* anterior = NULL;
        Nodo<Element>* lento = this->head;
        Nodo<Element>* rapido = this->head;

        while (rapido != NULL && rapido->getNext() != NULL) {
            anterior = lento;
            lento = lento->getNext();
            rapido = rapido->getNext()->getNext();
        }

        // Dividir la lista
        anterior->setNext(NULL);
        Nodo<Element>* mitad = lento;

        // Paso 2: Ordenar cada mitad
        int longitudIzq = this->length / 2;
        int longitudDer = this->length - longitudIzq;

        // Ordenar primera mitad
        Lista<Element> listaTemporalIzq;
        listaTemporalIzq.setHead(this->head);
        listaTemporalIzq.setLength(longitudIzq);
        listaTemporalIzq.mergeSort();

        // Ordenar segunda mitad
        Lista<Element> listaTemporalDer;
        listaTemporalDer.setHead(mitad);
        listaTemporalDer.setLength(longitudDer);
        listaTemporalDer.mergeSort();

        // Paso 3: Mezclar las listas ordenadas
        Nodo<Element>* nuevaCabeza = NULL;
        Nodo<Element>* cola = NULL;
        Nodo<Element>* actualIzq = listaTemporalIzq.getHead();
        Nodo<Element>* actualDer = listaTemporalDer.getHead();

        while (actualIzq != NULL && actualDer != NULL) {
            Nodo<Element>* menor = NULL;

            if (actualIzq->getInfo() <= actualDer->getInfo()) {
                menor = actualIzq;
                actualIzq = actualIzq->getNext();
            } else {
                menor = actualDer;
                actualDer = actualDer->getNext();
            }

            if (nuevaCabeza == NULL) {
                nuevaCabeza = menor;
                cola = menor;
            } else {
                cola->setNext(menor);
                cola = menor;
            }
        }

        // Agregar elementos restantes
        if (actualIzq != NULL) {
            cola->setNext(actualIzq);
            while (actualIzq->getNext() != NULL) {
                actualIzq = actualIzq->getNext();
            }
            cola = actualIzq;
        } else if (actualDer != NULL) {
            cola->setNext(actualDer);
            while (actualDer->getNext() != NULL) {
                actualDer = actualDer->getNext();
            }
            cola = actualDer;
        }

        // Actualizar la lista principal
        this->head = nuevaCabeza;
        this->tail = cola;

        // Prevenir que las listas temporales eliminen los nodos
        listaTemporalIzq.setHead(NULL);
        listaTemporalIzq.setTail(NULL);
        listaTemporalIzq.setLength(0);

        listaTemporalDer.setHead(NULL);
        listaTemporalDer.setTail(NULL);
        listaTemporalDer.setLength(0);
    }
    // Si length <= 1, no hacemos nada (lista ya está ordenada)
}


// OPERADORES

// Operador de asignación
template <class Element>
Lista<Element>& Lista<Element>::operator=(const Lista<Element>& otra) {
    if (this != &otra) {
        this->vaciar();
        
        Nodo<Element>* actual = otra.head;
        while (actual != NULL) {
            this->insertar(actual->getInfo(), this->length);
            actual = actual->getNext();
        }
    }
    return *this;
}

// Operador de igualdad
template <class Element>
bool Lista<Element>::operator==(const Lista<Element>& otra) const {
    if (this->length != otra.length) return false;
    
    Nodo<Element>* actual1 = this->head;
    Nodo<Element>* actual2 = otra.head;
    
    while (actual1 != NULL && actual2 != NULL) {
        if (actual1->getInfo() != actual2->getInfo()) {
            return false;
        }
        actual1 = actual1->getNext();
        actual2 = actual2->getNext();
    }
    
    return true;
}

// Operador de desigualdad
template <class Element>
bool Lista<Element>::operator!=(const Lista<Element>& otra) const {
    return !(*this == otra);
}

// Operador de concatenación
template <class Element>
Lista<Element> Lista<Element>::operator+(const Lista<Element>& otra) const {
    Lista<Element> resultado;
    
    // Copiar elementos de la lista actual
    Nodo<Element>* actual = this->head;
    while (actual != NULL) {
        resultado.insertar(actual->getInfo(), resultado.longitud());
        actual = actual->getNext();
    }
    
    // Copiar elementos de la otra lista
    actual = otra.head;
    while (actual != NULL) {
        resultado.insertar(actual->getInfo(), resultado.longitud());
        actual = actual->getNext();
    }
    
    return resultado;
}

// Operador de acceso (versión modificable)
template <class Element>
Element& Lista<Element>::operator[](int pos) {
    if (pos < 0 || pos >= this->length) {
        throw std::out_of_range("Posición inválida");
    }
    
    Nodo<Element>* actual = this->head;
    for (int i = 0; i < pos; ++i) {
        actual = actual->getNext();
    }
    
    // Solución: Almacenar en una variable miembro temporal si getInfo() devuelve por valor
    static Element temp;  // Variable estática para mantener la referencia
    temp = actual->getInfo();
    return temp;
}

// Operador de acceso (versión constante)
template <class Element>
Element Lista<Element>::operator[](int pos) const {
    if (pos < 0 || pos >= this->length) {
        throw std::out_of_range("Posición inválida");
    }
    
    Nodo<Element>* actual = this->head;
    for (int i = 0; i < pos; ++i) {
        actual = actual->getNext();
    }
    
    return actual->getInfo();  // Devuelve por valor
}

