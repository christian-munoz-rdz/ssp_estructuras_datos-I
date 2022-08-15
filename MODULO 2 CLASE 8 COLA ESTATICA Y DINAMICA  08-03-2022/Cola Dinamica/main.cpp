#include "Queue.h"

int main(){
    int dato;
    string opcion;
   	Cola c;

    do{
        system("cls");
        c.MostrarCola();
        cout<<""<<endl;
        cout<<"Menu"<<endl;
        cout<<"[1]Encolar(push)"<<endl;
        cout<<"[2]Mostrar inicio"<<endl;
        cout<<"[3]Mostrar fin"<<endl;
        cout<<"[4]Des-Encolar(pop)"<<endl;
        cout<<"[5]Salir"<<endl
        << "ingrese opcion >> ";
        cin>>opcion;
	    if(!isdigit(opcion[0])){
            cout<<"Error! Ingrese un numero!..."<<endl;
            system("pause");
	    }
        else{
            switch(stoi(opcion)){
                case 1: 
                    c.Push();
                    break;
                case 2: 
                    c.Frente();
                    break;     
                case 3: 
                    c.Atras();
                    break;	    
                case 4: 
                    c.Pop();   
                    break;                    
            }
        }
    }while(opcion!="5");
}