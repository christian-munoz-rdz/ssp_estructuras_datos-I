#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

void hideCursor(){
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle,&cursor);
}

using namespace std;

class Pasajero{
public:
    string nombre;
    int id;
    int boleto;
    int maletas;
    Pasajero* siguiente;
    
    Pasajero(string,int);
    void setBoleto();
    void setMaletas();
    void mostrarDatos();
};

Pasajero::Pasajero(string nombre, int contador){
    this->nombre = nombre;
    this->id = contador+1;
    setBoleto();
    siguiente = NULL;
}

void Pasajero::setBoleto(){
    boleto = rand() % 100000000000 + 1234567;
}

void Pasajero::setMaletas(){
    maletas = rand() % 5 + 1;
}
 
void Pasajero::mostrarDatos(){
    gotoxy((id-1)*20,0);cout<<"----------"<<endl;
    gotoxy((id-1)*20,1);cout <<"Nombre: "<<nombre<< endl;
    gotoxy((id-1)*20,2);cout <<"Id: "<<id<<endl;
    gotoxy((id-1)*20,3);cout<<"Boleto: "<<boleto<<endl;
    gotoxy((id-1)*20,4);cout<<"----------"<<endl;
}

void avion(){
    for(int y=0;y<9;y+=3){
        for (int x=0;x<200;x++){
            gotoxy(x,0+y);cout<<"            ______"<<endl;
            gotoxy(x,1+y);cout<<"             _\\ _~-\\___"<<endl;
            gotoxy(x,2+y);cout<<"     =  = ==(____AA____D"<<endl;
            gotoxy(x,3+y);cout<<"                 \\_____\\___________________,-~~~~~~~`-.._"<<endl;
            gotoxy(x,4+y);cout<<"                 /     o O o o o o O O o o o o o o O o  |\\_"<<endl;
            gotoxy(x,5+y);cout<<"                 `~-.__        ___..----..                  )"<<endl;
            gotoxy(x,6+y);cout<<"                       `---~~\\___________/------------`````"<<endl;
            gotoxy(x,7+y);cout<<"                       =  ===(_________D"<<endl;
            Sleep(20);        
        }
    system("cls");
    }
}
