#include <iostream>
using namespace std;

bool i_input(string);

class Node{
public:
    int number;
    Node *next;
    Node *back;
    void Mod();
};

void Node::Mod(){
    string newNumber;
    bool retry = false;
    do{
        system("cls");
        if (retry)
            cout<<"Opcion invalida"<<endl;
        cout << "Ingrese un numero>> ";
        cin>> newNumber;
        retry=true;
    }while(!i_input(newNumber));
    number = stoi(newNumber);
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