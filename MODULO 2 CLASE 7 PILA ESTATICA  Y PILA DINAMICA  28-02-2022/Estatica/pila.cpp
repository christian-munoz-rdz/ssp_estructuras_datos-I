#include "pila.h"

using namespace std;

int main(){
	Stack s;
	int opcion;
	int num;

	do{    
		system("cls");
		s.SohowStack();
		cout<<
		"\n\n[1].ingresar numero"<<endl
		<<"[2].Eliminar tope"<<endl
		<<"[3].Mostrar tope"<<endl
		<<"[4].salir"<<endl
		<<"Ingrese una opcion>>> ";
		cin>>opcion;
		switch(opcion){
			case 1:
			    s.Push();
			    break;
			case 2:  
				s.Pop();
			    break;
			case 3:  
				s.ShowTop();
			    break;
			case 4:
				cout<<"Saliendo..."<<endl;
				break;   
			default:
				cout<<"Opcion invalida..."<<endl;	  	        
			    system("pause");
		}
	}while(opcion!=4);
	return 0;
}
