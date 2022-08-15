#include <iostream>
#include <string>
#include "Triangulo.h"
#include "Cuadrado.h"
#include "Rectangulo.h"
#include "Poligono.h"

using namespace std;

bool d_input(string);
bool i_input(string);
void menu();
void opciones(int);
void triangulo(double,double);
void cuadrado(double);
void rectangulo(double,double);
void poligono(int,double);

string input1,input2;

int main(){
    menu();
    return 0;
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

bool i_input(string input){
    int length = input.length();
    for(int i=0; i<length;i++){

        if(!isdigit(input[i])){
            return false;
        }

    }
    return true;
}

void menu(){
    int opc;
    int exit;
    do{
        system("cls");
        cout<<"1)Calcular el area de un Triangulo"<<endl
        <<"2)Calcular el area de un Cuadrado"<<endl
        <<"3)Calcular el area de un Rectangulo"<<endl
        <<"4)Calcular el area de un Poligono"<<endl
        <<">>>>>";
        cin>>opc;
        opciones(opc);
        cout<<"Continuar 1.Si 2.No"<<endl
        <<">>>>>";
        cin>>exit;
    }while(exit!=2);
    system("pause");
}

void opciones(int opc){
    switch (opc)
    {

    case 1:
        system("cls");
        cout << "AREA DE UN TRIANGULO" << endl << endl;
        cout << "Inngrese la Base>>>";
        cin >> input1;
        cout << "Ingrese la Altura>>>";
        cin >> input2;
        if(!d_input(input1)||!d_input(input2)){
            cout << "Error!los valores deben ser numericos"<<endl;
        }
        else{
            triangulo(stod(input1),stod(input2));
        }
        break;

    case 2:
        system("cls");
        cout << "AREA DE UN CUADRADO" << endl << endl;
        cout << "Inngrese el lado>>>";
        cin >> input1;
        if(!d_input(input1)){
            cout << "Error!los valores deben ser numericos"<<endl;
        }
        else{
            cuadrado(stod(input1));
        }
        break;

    case 3:
        system("cls");
        cout << "AREA DE UN RECTANGULO" << endl << endl;
        cout << "Inngrese la Base>>>";
        cin >> input1;
        cout << "Ingrese la Altura>>>";
        cin >> input2;
        if(!d_input(input1)||!d_input(input2)){
            cout << "Error!los valores deben ser numericos"<<endl;
        }
        else{
            rectangulo(stod(input1),stod(input2));
        }
        break;
    
    case 4:
        system("cls");
        cout << "AREA DE UN POLIGONO" << endl << endl;
        cout << "Inngrese el numero de lados>>>";
        cin >> input1;
        cout << "Ingrese la medida de los lados>>";
        cin >> input2;
        if(!i_input(input1)||!d_input(input2)){
            cout << "Error!"<<endl
            << "Ingrese un valor entero para el numero de lados y un valor real para la medida de los lados"<<endl;
        }
        else{
            poligono(stoi(input1),stod(input2));
        }
        break;

    default:
        system("cls");
        cout<<"Opcion Invalida..."<<endl;
        break;
    }
}

void triangulo(double base,double altura){
    Triangulo t;
    t.setBase(base);
    t.setAltura(altura);
    t.calculaArea();
    cout << "Area = " << t.getArea() << endl;
}

void cuadrado(double lado){
    Cuadrado c;
    c.setLado(lado);
    c.calculaArea();
    cout << "Area = " << c.getArea() << endl;
}

void rectangulo(double base, double altura){
    Rectangulo r;
    r.setBase(base);
    r.setAltura(altura);
    r.calculaArea();
    cout << "Area = " << r.getArea() << endl;
}

void poligono(int n_lados, double m_lado){
    Poligono p;
    p.set_n_lados(n_lados);
    p.set_m_lado(m_lado);
    p.calcular_area();
    cout << "Area = " << p.get_area() << endl;
}

