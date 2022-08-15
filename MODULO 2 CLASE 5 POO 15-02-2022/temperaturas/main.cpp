#include <iostream>
#include <string>
#include "Celsius.h"
#include "Farenheit.h"
#include "Kelvin.h"

using namespace std;

bool d_input(string);
void menu();
void opciones(int);

string input;

int main(){
    menu();
    return 0;
}

void menu(){
    int opc;
    do{
        system("cls");
        cout<<"1)Convertir Celsius a Kelvin"<<endl
        <<"2)Convertir Kelvin a Celsius"<<endl
        <<"3)Convertir celsius a Farenheit"<<endl
        <<"4)Convertir Farenheit a Celsius"<<endl
        <<"5)Salir"<<endl
        <<">>>>>";
        cin>>opc;
        opciones(opc);
    }while(opc!=5);
    system("pause");
}

void opciones(int opc){
    switch (opc)
    {

    case 1:
        system("cls");
        Celsius c;
        cout << "CELSIUS A KELVIN" << endl << endl;
        cout << "Inngrese grados celsius>>>";
        cin >> input;
        if(!d_input(input)){
            cout << "Error!los valores deben ser numericos"<<endl;
            system("pause");
        }
        else{
            c.set_grados(stod(input));
            cout << input << " Grados Celsius = " << c.calcula_kelvin() << " Grados Kelvin" << endl;
            system("pause");
        }
        break;

    case 2:
        system("cls");
        Kelvin k;
        cout << "KELVIN A CELSIUS" << endl << endl;
        cout << "Inngrese grados Kelvin>>>";
        cin >> input;
        if(!d_input(input)){
            cout << "Error!los valores deben ser numericos"<<endl;
            system("pause");
        }
        else{
            k.set_grados(stod(input));
            cout << input << " Grados Kelvin = " << k.calcula_Celsius() << " Grados Celsius" << endl;
            system("pause");
        }
        break;

    case 3:
        system("cls");
        Celsius c1;
        cout << "CELSIUS A FARENHEIT" << endl << endl;
        cout << "Inngrese grados Celsius>>>";
        cin >> input;
        if(!d_input(input)){
            cout << "Error!los valores deben ser numericos"<<endl;
            system("pause");
        }
        else{
            c.set_grados(stod(input));
            cout << input << " Grados Celsius = " << c.calcula_farenheit() << " Grados Farenheit" << endl;
            system("pause");
        }
        break;
    
    case 4:
        system("cls");
        Farenheit f;
        cout << "FARENHEIT A CELSIUS" << endl << endl;
        cout << "Inngrese grados Farenheit>>>";
        cin >> input;
        if(!d_input(input)){
            cout << "Error! los valores deben ser numericos" << endl;
            system("pause");
        }
        else{
            f.set_grados(stod(input));
            cout << input << " Grados Farenheit = " << f.calcula_Celsius() << " Grados Celsius()" << endl;
            system("pause");
        }
        break;

    case 5:
        system("cls");
        cout << "SALIENDO..." << endl;
        break;

    default:
        system("cls");
        cout<<"Opcion Invalida..."<<endl;
        system("pause");
        break;
    }
}

bool d_input(string input){
    int length = input.length();
    int point_counter = 0;
    for(int i=0; i<length;i++){

        if(!isdigit(input[i])){
            if(input[i]=='.'){
                point_counter++;
                if(point_counter>1){
                    return false;
                }
            }
            else{
                return false;
            }
        }

    }
    return true;
}