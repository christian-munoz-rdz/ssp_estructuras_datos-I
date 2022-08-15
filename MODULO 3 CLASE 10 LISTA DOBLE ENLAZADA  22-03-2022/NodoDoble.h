#include <iostream>

using namespace std;
bool i_input(string);

template <typename T>
class NodoDoble{
public:
    T num;
    NodoDoble<T>* Anterior;
    NodoDoble<T>* Siguiente;

    NodoDoble();
};

template<typename T>
NodoDoble<T>::NodoDoble(){
    string _num;
    bool retry=false;
    do{
        system("cls");
        if(retry)
            cout<<"Opcion invalida"<<endl;

        cout << "Ingrese un numero >> ";
        cin>>_num;
        retry=true;
    }while(!i_input(_num));

    this->num = stoi(_num);
    Anterior = NULL;
    Siguiente = NULL;
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