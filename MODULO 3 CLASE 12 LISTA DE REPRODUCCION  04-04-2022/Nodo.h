#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void gotoxy(int,int);

struct Cancion{
    int id;
    string titulo;
    string artista;
    string genero;
    string ruta;
};

class Nodo{
public:
    int id;
    Cancion cancion;
    Nodo* siguiente;
    Nodo* anterior;
    Nodo(Cancion,int);
    ~Nodo();
    void Modificar();
    void Mostrar(int,int);
};

Nodo::Nodo(Cancion c,int id_){
    cancion = c;
    siguiente = NULL;
    anterior = NULL;
    id = id_;
}

Nodo::~Nodo(){
    cout<<"Nodo eliminado"<<endl;
}

void Nodo::Mostrar(int x,int y){
    gotoxy(x,y);cout<<"------------------------" <<endl;
    gotoxy(x,y+1);cout <<"Titulo: " <<cancion.titulo<< endl;
    gotoxy(x,y+2);cout<<"Artista: " <<cancion.artista << endl;
    gotoxy(x,y+3);cout<<"Genero: " <<cancion.genero << endl;
    gotoxy(x,y+4);cout<<"------------------------" <<endl;
}

void Nodo::Modificar(){
    cout<<"Ingrese titulo: ";
    cin>>cancion.titulo;
    cout<<"Ingrese artista: ";
    cin>>cancion.artista;
    cout<<"Ingrese genero: ";
    cin>>cancion.genero;

}

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}