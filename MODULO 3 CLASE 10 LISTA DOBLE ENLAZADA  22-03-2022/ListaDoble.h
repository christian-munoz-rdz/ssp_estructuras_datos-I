#include "NodoDoble.h"

template<typename T>
class ListaDoble{
public:
    T contador;
    NodoDoble<T>* Cabecera;
    NodoDoble<T>* Cola;
    
    ListaDoble();

    void InsertarInicio();
    void InsertarFinal();
    void InsertarMedio(T);

    void RemoverInicio();
    void RemoverFinal();
    bool RemoverMedio(T);
    void VaciarLista();

    T Buscar(T);
    T BuscarIndice(T);
    T Primero();
    T Ultimo();

    T Tamanho();
    void MostrarLista();
    void MostrarReversa();

    void AscSort();
    void DescSort();
};

template<typename T>
ListaDoble<T>::ListaDoble(){
    contador = 0;
    Cabecera = NULL;
    Cola = NULL;
}

template<typename T>
void ListaDoble<T>::InsertarInicio(){
    NodoDoble<T>* nuevoNodo = new NodoDoble<T>();

    nuevoNodo->Siguiente = Cabecera;

    if(Cabecera != NULL)
        Cabecera->Anterior = nuevoNodo;

    Cabecera = nuevoNodo;

    if(contador == 0)
        Cola = Cabecera;

    contador++;
}

template<typename T>
void ListaDoble<T>::InsertarFinal(){
    if(contador == 0){
        InsertarInicio();
    }
    else{
        NodoDoble<T>* nuevoNodo = new NodoDoble<T>();
        Cola->Siguiente = nuevoNodo;
        nuevoNodo->Anterior = Cola;
        Cola = nuevoNodo;
        contador++;
    }
}

template<typename T>
void ListaDoble<T>::InsertarMedio(T indice){
    if(indice < 0 || indice > contador){
        cout<<"Indice fuera de rango"<<endl;
        system("pause");
    }
    else if(indice == 0)
        InsertarInicio();
    else if(indice == contador)
        InsertarFinal();
    else{
        NodoDoble<T>* nodoAnterior = Cabecera;

        for(int i = 0; i < indice-1; i++){
            nodoAnterior = nodoAnterior->Siguiente;
        }

        NodoDoble<T>* nodoSiguiente = nodoAnterior->Siguiente;

        NodoDoble<T>* nuevoNodo = new NodoDoble<T>();

        nuevoNodo->Siguiente = nodoSiguiente;
        nuevoNodo->Anterior = nodoAnterior;
        nodoAnterior->Siguiente = nuevoNodo;
        nodoSiguiente->Anterior = nuevoNodo;

        contador++;
    }
}

template<typename T>
void ListaDoble<T>::RemoverInicio(){
    if(contador == 0)
        cout<<"Lista vacia..."<<endl;
    else{
        NodoDoble<T>* nodo = Cabecera;

        Cabecera = Cabecera->Siguiente;

        delete nodo;

        if(Cabecera != NULL)
            Cabecera->Anterior = NULL;

        contador--;
    }
}

template<typename T>
void ListaDoble<T>::RemoverFinal(){
    if(contador == 0)
        cout<<"Lista Vacia..."<<endl;
    if(contador == 1)
        RemoverInicio();
    else{
        NodoDoble<T>* nodo = Cola;

        Cola = Cola->Anterior;

        Cola->Siguiente = NULL;

        delete nodo;

        contador--;
    }
}

template<typename T>
bool ListaDoble<T>::RemoverMedio(T indice){
    if(contador == 0)
        return false;

    if(indice < 0 || indice >= contador)
        return false;

    if(indice == 0){
        RemoverInicio();
        return true;
    }
    else if(indice == contador - 1){
        RemoverFinal();
        return true;
    }
    
    NodoDoble<T>* nodoAnterior = Cabecera;

    for(int i = 0; i < indice-1; i++){
        nodoAnterior = nodoAnterior->Siguiente;
    }

    NodoDoble<T>* nodo = nodoAnterior->Siguiente;

    NodoDoble<T>* nodoSiguiente = nodo->Siguiente;

    nodoAnterior->Siguiente = nodoSiguiente;
    nodoSiguiente->Anterior = nodoAnterior;

    delete nodo;

    contador--;
    return true;
}

template<typename T>
void ListaDoble<T>::VaciarLista(){
    int aux = contador;

    for(int i=1;i<=aux;i++){
        RemoverInicio();
    }

    cout << "Lista vaciada con exito" << endl;
}

template<typename T>
T ListaDoble<T>::Buscar(T indice){
    if(indice < 0 || indice > contador)
        return -1;

    NodoDoble<T>* nodo = Cabecera;

    for(int i=0;i < indice;i++){
        nodo = nodo->Siguiente;
    }

    return nodo->num;
}

template<typename T>
T ListaDoble<T>::BuscarIndice(T num){
    if(contador == 0)
        return -1;

    int indice = 0;

    NodoDoble<T>* nodo = Cabecera;

    while(nodo->num != num)
    {
        indice++;
        nodo = nodo->Siguiente;

        if(nodo == NULL){
            return -1;
        }
    }

    return indice;
}

template<typename T>
T ListaDoble<T>::Primero(){
    return Cabecera->num;
}

template<typename T>
T ListaDoble<T>::Ultimo(){
    return Cola->num;
}

template<typename T>
T ListaDoble<T>::Tamanho(){
    return contador;
}

template<typename T>
void ListaDoble<T>::MostrarLista(){
    NodoDoble<T>* nodo = Cabecera;

    while(nodo != NULL){
        cout<<nodo->num<<" -> ";
        nodo = nodo->Siguiente;
    }

    cout <<"Fin" << endl;
}

template<typename T>
void ListaDoble<T>::MostrarReversa(){
    NodoDoble<T>* nodo = Cola;

    while(nodo != NULL){
        cout<<nodo->num<<" -> ";
        nodo = nodo->Anterior;
    }

    cout <<"Fin" << endl;
}

template<typename T>
void ListaDoble<T>::AscSort(){
    NodoDoble<T>* start = Cabecera;
	int swapped;
	NodoDoble<T>* ptr1;
	NodoDoble<T>* lptr = NULL;

	if (start == NULL)
		return;

	do{
		swapped = 0;
		ptr1 = start;

		while (ptr1->Siguiente != lptr){
			if (ptr1->num > ptr1->Siguiente->num){
                int temp = ptr1->num;
                ptr1->num = ptr1->Siguiente->num;
                ptr1->Siguiente->num = temp;
				swapped = 1;
			}
			ptr1 = ptr1->Siguiente;
		}
		lptr = ptr1;
	}
	while (swapped);
}

template<typename T>
void ListaDoble<T>::DescSort(){
    NodoDoble<T>* start = Cabecera;
	int swapped;
	NodoDoble<T>* ptr1;
	NodoDoble<T>* lptr = NULL;

	if (start == NULL)
		return;

	do{
		swapped = 0;
		ptr1 = start;

		while (ptr1->Siguiente != lptr){
			if (ptr1->num < ptr1->Siguiente->num){
                int temp = ptr1->num;
                ptr1->num = ptr1->Siguiente->num;
                ptr1->Siguiente->num = temp;
				swapped = 1;
			}
			ptr1 = ptr1->Siguiente;
		}
		lptr = ptr1;
	}
	while (swapped);
}