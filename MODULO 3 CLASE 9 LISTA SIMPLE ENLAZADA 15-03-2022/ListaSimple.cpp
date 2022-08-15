#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Contacto{
public:
    T id;
    T nombre;

    Contacto(T,T);
    ~Contacto();
    void Mostrar();
    void Modificar(T);
};

template<typename T>
Contacto<T>::Contacto(T _id,T _nombre){
        id = _id;
    nombre = _nombre;
}

template<typename T>
Contacto<T>::~Contacto(){}

template<typename T>
void Contacto<T>::Mostrar(){
    cout<<"-------------" << endl
    << "ID: " << id << endl
    <<"Nombre: " << nombre << endl
    <<"-------------" << endl;
}

template<typename T>
void Contacto<T>::Modificar(T _nombre){
    nombre = _nombre;
}
////////////////////////////////////////////////////////////////////////////

template <typename T>
class Nodo{
public:
    Contacto<T>* c;
    Nodo<T>* siguiente;
    Nodo();
    ~Nodo();
};

template<typename T>
Nodo<T>::Nodo(){
    T _id;
    T _nombre;
    cout<<"Ingrese ID >> "; cin>> _id;
    cout<<"Ingrese Nombre >> "; cin>> _nombre;
    c = new Contacto<T>(_id,_nombre);
    siguiente = NULL;
}

template<typename T>
Nodo<T>::~Nodo(){}
//////////////////////////////////////////////////////////////////////////////////

template <typename T>
class ListaEnlazada{
public:
    int contador;
    Nodo<T>* Cabecera;

    ListaEnlazada();

    void AgregarContacto();//
    Nodo<T>* BuscarId(T);//
    Nodo<T>* BuscarPos(int);//
    Nodo<T>* BuscarNombre(T);//
    void Eliminar(int);//
    void Invertir();//
    //void AlphaSort();
    void ImprimirLista();//
    void Modificar(int);//
    void VaciarLista();//
};

template <typename T>
ListaEnlazada<T>::ListaEnlazada(){
    contador = 0;
    Cabecera = NULL;
}

template <typename T>
void ListaEnlazada<T>::AgregarContacto(){

    Nodo<T>* nuevo = new Nodo<T>();

    if (contador==0){
        Cabecera=nuevo;
    }
    else{
        Nodo<T>* anterior = Cabecera;

        for(int i=1;i<contador;i++)
            anterior = anterior->siguiente;

        anterior->siguiente = nuevo;
    }
    contador++;
}

template <typename T>
Nodo<T>* ListaEnlazada<T>::BuscarId(T id){
    if(contador == 0)
        return NULL;

    Nodo<T>* nodo = Cabecera;

    while(nodo->c->id != id)
    {
        nodo = nodo->siguiente;

        if(nodo == NULL)
        {
            return NULL;
        }
    }

    return nodo;
}

template <typename T>
Nodo<T>* ListaEnlazada<T>::BuscarPos(int indice){
    if (contador==0){
        return NULL;
    }
    else{
        Nodo<T>* nodo = Cabecera;
        for(int i=1;i<indice;i++)
            nodo = nodo->siguiente;
        return nodo;
    }
}

template <typename T>
Nodo<T>* ListaEnlazada<T>::BuscarNombre(T nombre){
    if(contador == 0)
        return NULL;

    Nodo<T>* nodo = Cabecera;

    while(nodo->c->nombre != nombre)
    {
        nodo = nodo->siguiente;

        if(nodo == NULL)
        {
            return NULL;
        }
    }

    return nodo;
}

template<typename T>
void ListaEnlazada<T>::Eliminar(int indice){
    if (indice==1){
        Nodo<T>* Eliminar = Cabecera;

        Cabecera = Cabecera->siguiente;
        delete Eliminar;
    }
    else{
        Nodo<T>* nodoAnterior = Cabecera;

        for(int i =1; i<indice-1; ++i){
            nodoAnterior = nodoAnterior->siguiente;
        }

        Nodo<T>* Eliminar = nodoAnterior->siguiente;
        Nodo<T>* nodoSiguiente = Eliminar->siguiente;
        nodoAnterior->siguiente = nodoSiguiente;

        delete Eliminar;
    }
    contador--;   
}

template <typename T>
void ListaEnlazada<T>::Invertir(){

    Contacto<T> contactos[];

    while(begin!=NULL)
        aux = begin->c;
        begin->c = last->c;
        begin = begin->siguiente;
    }
}

template <typename T>
void ListaEnlazada<T>::ImprimirLista(){
    Nodo<T>* nodo = Cabecera;

    while(nodo != NULL)
    {
        nodo->c->Mostrar();
        nodo = nodo->siguiente;
    }
}

template <typename T>
void ListaEnlazada<T>::Modificar(int indice){
    T _nombre;
    Nodo<T>* nodo = Cabecera;
    for(int i=1;i<indice;i++)
        nodo = nodo->siguiente;
    cout<<"Ingrese Nuevo nombre >> ";
    cin>>_nombre;
    nodo->c->Modificar(_nombre);
}

template<typename T>
void ListaEnlazada<T>::VaciarLista(){
    int aux = contador;

    for(int i=1;i<=aux;i++){
        Nodo<T>* Eliminar = Cabecera;

        Cabecera = Cabecera->siguiente;
        delete Eliminar;
        contador--; 
    }
    cout << "Lista vaciada con exito" << endl;
}

void opciones(int);
ListaEnlazada<string>* lista = new ListaEnlazada<string>();

int main(){
    int opc;
    do{
        system("cls");
        cout<<"1)Agregar contacto"<<endl
        <<"2)Buscar contacto por ID" <<endl
        <<"3)Buscar contacto por posicion"<<endl
        <<"4)Buscar contacto por nombre"<<endl
        <<"5)Eliminar contacto"<<endl
        <<"6)Invertir el orden de la lista"<<endl
        <<"7)Ordenar lista alfabeticamente"<<endl
        <<"8)Imprimir la lista"<<endl
        <<"9)Modificar contacto"<<endl
        <<"10)Vaciar la lista" << endl
        <<"0)Salir" << endl
        <<"Elija una opcion >>>>>";
        cin>>opc;
        opciones(opc);
    }while(opc!=0);
    return 0;
}

void opciones(int opc){
    string search;
    Nodo<string>* find;
    int pos;
    switch (opc)
    {
    case 1:
        system("cls");
        cout << "AGREGAR CONTACTO" << endl << endl;
        lista->AgregarContacto();
        system("pause");
        break;

    case 2:
        system("cls");
        cout << "BUSCAR CONTACTO POR ID" << endl << endl;
        cout << "Ingrese ID >> ";
        cin>> search;
        find = lista->BuscarId(search);
        if (!find)
            cout << "No se encontro el elemento..."<<endl;
        else
            find->c->Mostrar();        
        system("pause");
        break;

    case 3:
        system("cls");
        cout << "BUSCAR CONTACTO POR POSICION" << endl << endl;
        cout << "Ingrese posicion >> ";
        cin>> pos;
        if ((pos<0||pos>lista->contador)||(lista->contador==0))
            cout<<"Fuera de rango"<<endl;
        else{
            find = lista->BuscarPos(pos);
            find->c->Mostrar();
        }
        system("pause");
        break;
    
    case 4:
        system("cls");
        cout << "BUSCAR CONTACTO POR NOMBRE" << endl << endl;
        cout << "Ingrese nombre >> ";
        cin>> search;
        find = lista->BuscarNombre(search);
        if (!find)
            cout << "No se encontro el elemento..."<<endl;
        else
            find->c->Mostrar();        
        system("pause");
        break;

    case 5:
        system("cls");
        cout << "ELIMINAR CONTACTO" << endl << endl;
        cout << "Ingrese posicion >> ";
        cin>> pos;
        if ((pos<0||pos>lista->contador)||(lista->contador==0))
            cout<<"Fuera de rango"<<endl;
        else
            lista->Eliminar(pos);
        cout<<"Eliminado satisfactoriamente..."<<endl;
        system("pause");
        break;
        
    case 6:
        system("cls"); //Corregir
        cout << "INVERTIR EL ORDEN DE LA LISTA" << endl << endl;
        if(lista->contador==0)
            cout << "La lista esta vacia..."<< endl;
        else{
            lista->Invertir();
            cout<<"Se ha invertido la lista"<<endl;
        }
        system("pause");
        break;

    case 7:
        system("cls");
        system("pause");
        break;

    case 8:
        system("cls");
        cout << "IMPRIMIR LA LISTA" << endl << endl;
        if (lista->contador==0)
            cout << "La lista esta vacia..."<< endl;
        else
            lista->ImprimirLista();
        system("pause");
        break;

    case 9:
        system("cls");
        cout << "MODIFICAR CONTACTO" << endl << endl;
        cout << "Ingrese posicion >> ";
        cin>> pos;
        if ((pos<0||pos>lista->contador)||(lista->contador==0))
            cout<<"Fuera de rango"<<endl;
        else
            lista->Modificar(pos);
        system("pause");
        break;
    
    case 10:
        system("cls");
        cout << "VACIAR LA LISTA" << endl <<endl;
        if (lista->contador==0)
            cout<<"La lista esta vacia..."<<endl;
        else
            lista->VaciarLista();
        system("pause");
        break;
    
    case 0:
        system("cls");
        system("pause");
        break;

    default:
        system("cls");
        cout<<"Opcion Invalida..."<<endl;
        system("pause");
        break;
    }
}