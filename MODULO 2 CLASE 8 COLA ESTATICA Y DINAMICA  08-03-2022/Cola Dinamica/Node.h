#include <iostream>

class Nodo{
public:
    int valor;
    Nodo* siguiente;

    Nodo(int);
};

Nodo::Nodo(int valor){
    this->valor=valor;
    siguiente = NULL;
}
