#include <iostream>
#include <windows.h>
using namespace std;

bool i_input(string);

class Node{
public:
    int id;
    string name;
    string direction;
    string email;
    Node* left;
    Node* right;

    Node(int);
    void edit();
    void show();
};

Node::Node(int id){
    system("cls");
    this->id = id;
    cout<<"Ingrese nombre: ";
    cin>>name;
    cout<<"Ingrese direccion: ";
    cin>>direction;
    cout<<"Ingrese email: ";
    cin>>email;
    left = NULL;
    right = NULL;
}

void Node::edit(){
        bool retry;
        do{
            if(retry)
                system("cls");
            retry =false;
            string change;
            string election;
            cout<<"Seleccione que desea editar:\n"<<
            "1)Nombre\n"<<
            "2)Direccion\n"<<
            "3)Email\n";
            cout<<"Indique opcion >> ";
            cin>>election;
            if (!i_input(election)){
                cout<<"Ingrese opcion valida"<<endl;
                Sleep(1000);
                retry = true;
            }
            else{
                switch (stoi(election)){
                    case 1:
                        cout<<"Ingrese nuevo nombre: ";
                        cin>>name;
                        system("pause");
                        break;
                    
                    case 2:
                        cout<<"Ingrese nueva Direccion: ";
                        cin>>direction;
                        system("pause");
                        break;
                    
                    case 3:
                        cout<<"Ingrese nuevo Email: ";
                        cin>>email;
                        system("pause");
                        break;
                
                default:
                    cout<<"Ingrese opcion valida"<<endl;
                    Sleep(1000);
                    retry = true;
                    break;
                }
            }
        }while(retry);
}

void Node::show(){
    cout<<"---------------"<<endl;
    cout<<"id: "<<id<<endl
    <<"Nombre: "<<name<<endl
    <<"Direccion: "<<direction<<endl
    <<"Email: "<<email<<endl;
    cout<<"---------------"<<endl;
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


