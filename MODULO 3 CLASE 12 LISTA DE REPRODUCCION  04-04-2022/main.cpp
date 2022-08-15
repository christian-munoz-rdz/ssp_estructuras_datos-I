#include "Lista.h"
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void PlaySong(string);
bool i_input(string);

int main(){
	Cancion playlist[30];
    ifstream myFile;
    myFile.open("_songs.csv");
    int flag=1;
    int index=0;
    int id=1;
    while (myFile.good())
    {
        string line;
        getline(myFile, line,',');

        switch (flag)
        {
            case 1:
                playlist[index].id = id;
                playlist[index].titulo = line;
                flag++;
                break;
            case 2:
                playlist[index].artista = line;
                flag++;
                break;
            case 3:
                playlist[index].genero = line;
                flag=1;
                index++;
                id++;
                break;
            }
    }
	ifstream myFileR;
    myFileR.open("_roots.csv");
    index=0;
    while (myFileR.good())
    {
        string line;
        getline(myFileR, line,',');

        playlist[index].ruta = line;
        index++;
    }
    Lista* lista = new Lista();
	string opcion_menu;
	do{
		system("cls");
		if(lista->count!=0){
			PlaySong(lista->actual->cancion.ruta);
			lista->ImprimirLista();
		}
		else{
			gotoxy(0,8);cout<<"\nNo hay canciones disponibles\n";
		}	

		gotoxy(0,0);cout << "\n|-------------------------------------|";
		gotoxy(0,1);cout << "\n|               ROCKOLA               |";
		gotoxy(0,2);cout << "\n|------------------|------------------|";
		gotoxy(0,3);cout << "\n|1.Agregar cancion |5.Eliminar primera|";
		gotoxy(0,4);cout << "\n|2.Siguiente       |6.Eliminar ultima |";
		gotoxy(0,5);cout << "\n|3.Anterior        |7.Modificarcancion|";
		gotoxy(0,6);cout << "\n|4.Eliminar actual |8.Salir           |";
		gotoxy(0,7);cout << "\n|------------------|------------------|";
		gotoxy(0,9);cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;
		if((!i_input(opcion_menu))){
			cout<<"Ingrese solo numeros"<<endl;
			Sleep(1000);
		}
		else{
			int x=0;
			int y=12;
			string id;
			switch(stoi(opcion_menu)){
			case 1:
				cout << "\n\n AGREGA CANCON A LA LISTA \n\n";
				cout<<"CANCIONES DISPONIBLES"<<endl;
				for(int i = 0; i < 30; i++){
					gotoxy(x,y);cout<<"[" << playlist[i].id<<"]  "<<playlist[i].titulo;
					x+=30;
					if((i+1)%2==0&&(i!=0)){
						x=0;
						y+=1;
					}
				}
				cout<<"\nIndique el id de la cancion a agregar >> ";
				cin>>id;
				if((!i_input(id))){
					cout<<"Ingrese solo numeros"<<endl;
					Sleep(1000);
				}
				else{
					if (stoi(id)>30){
						cout<<"Ingrese un id valido"<<endl;
						Sleep(1000);
					}
					else{
						lista->Agregar(playlist[stoi(id)-1]);
					}
				}
				break;
			case 2:
				lista->Siguiente();
				break;
			case 3:
				lista->Anterior();
				break;
			case 4:
				lista->EliminarActual();
				break;
			case 5: 
				lista->EliminarPrimero();
				break;
			case 6:
				lista->EliminarUltimo();
				break;
			case 7:
				lista->Modificar();
				break;
			case 8:
				cout<<"Saliendo..."<<endl;
				break;
			default:
				cout << "\n\n Opcion No Valida \n\n";
				system("pause");
				break;
			}
		}
	} while (opcion_menu[0] != '8');
	
	return 0;
}

void PlaySong(string song_s){
	const char* song = song_s.c_str();
	cout<<PlaySound(song,NULL,SND_ASYNC);
}

bool i_input(string input){
    int length = input.length();
    for(int i=0; i<length;i++){
        if(!isdigit(input[i])){
            return false;
        }
    }
    return true;
}