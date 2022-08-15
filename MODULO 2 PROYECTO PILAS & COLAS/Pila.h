#include "Cola.h"

class Pila{
private:
    int Contador;
    Pasajero* Top;

public:
    Pila();
    void Push(Pasajero*);
    Pasajero* Pop();
	bool Vacia();
	void Abordar();
    int getCount();
};

Pila::Pila(){
    Contador = 0;
    Top = NULL;
}

void Pila::Push(Pasajero* Nuevo){
    system("cls");
    Nuevo->siguiente = Top;
    Top = Nuevo;
    Contador++;
    gotoxy(70,5);cout<<"-----ABORDAJE-----"<<endl;
    gotoxy(70,8);cout<<"Aborda " << Nuevo->nombre<<"..."<<endl;
    gotoxy(70,10);cout<<"................."<<endl;
    gotoxy(70,11);cout<<":   :   :   :   :"<<endl;
    gotoxy(70,12);cout<<"................."<<endl;
    gotoxy(70,13);cout<<":   :   :   :   :"<<endl;
    gotoxy(70,14);cout<<"................."<<endl;
    gotoxy(70,15);cout<<":   :   :   :   :"<<endl;
    gotoxy(70,16);cout<<"................."<<endl;
    gotoxy(70,17);cout<<":   :   :   :   :"<<endl;
    gotoxy(70,18);cout<<"................."<<endl;
    gotoxy(70,19);cout<<":   :   :   :   :"<<endl;
    gotoxy(70,20);cout<<"................."<<endl;
    gotoxy(70,21);cout<<":   :   :   :   :"<<endl;
    gotoxy(70,22);cout<<"................."<<endl;
    int x=71;
    int y=11;
    for(int i=1;i<=Contador;i++){    
        gotoxy(x,y); cout<<" o ";
        x+=4;
        if(i%4==0){
            y+=2;
            x=71;
        }
        Sleep(100);
    }
    Sleep(1000);
}

Pasajero* Pila::Pop(){
    system("cls");
	Pasajero* Sacar = Top;
    Top = Top->siguiente;
    Contador--;
    gotoxy(70,5);cout<<"-----ATERRIZAJE-----"<<endl;
    gotoxy(70,8);cout<<"Baja " << Sacar->nombre<<"..."<<endl;
	int ban=0;
	for(int j=70;j<95;j++){
	    gotoxy(j,10);cout<< "  o";
		gotoxy(j,11); cout<< " /|\\";
		if(ban==0){
			gotoxy(j,12); cout<< " / ";
			ban=1;
		}
        else{
			gotoxy(j,12); cout<< "   \\";
			ban=0;
		}
	    Sleep(30);
	}
    return Sacar;
}

bool Pila::Vacia(){
    return Contador <= 0;
}

int Pila::getCount(){
    return Contador;
}