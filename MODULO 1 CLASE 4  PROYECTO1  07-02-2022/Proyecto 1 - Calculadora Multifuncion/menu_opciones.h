#include <iostream>
#include <cstdlib>
#include "operaciones.h"
#include <stdlib.h>
#include <string>
#include <unistd.h>

using namespace std;
using std::string;


double din1, din2, din3;
double* din1ptr,* din2ptr,* din3ptr;
bool flag;

int intin;
int* intinptr;

string strin;


void two_inputs();
int is_digit(string);
int is_octal(string);
int is_double(string);
int is_binary(string);

void Menu(){
    int opc;
    
    cout<<"M E N U"<<endl
    <<"1)Suma"<<endl
    <<"2)Resta"<<endl
    <<"3)Multiplicacion"<<endl
    <<"4)Division"<<endl
    <<"5)Potencia"<<endl
    <<"6)Factorial"<<endl
    <<"7)Decimal a Binario"<<endl
    <<"8)Binario a Decimal"<<endl
    <<"9)Decimal a Octal"<<endl
    <<"10)Octal a Decimal"<<endl
    <<"11)Decimal a Hexadecimal"<<endl
    <<"12)Hexadecimal a Decimal"<<endl
    <<"0)Salir"<<endl
    <<"Ingrese una opcion ---->";
    
    cin>>opc;

    switch(opc){
        case 0:
            sleep(0.5);
            exit(0);
        case 1: //suma
            do{
                two_inputs();
                if((is_double(to_string(din1))==0)||(is_double(to_string(din2))==0)){
                    cout << "Solo puede ingresar números." << endl << "intente de nuevo..." << endl;
                    system("pause");
                    flag = false;
                }
                else{
                    cout<<din1<<" + "<<din2<<" = ";
                    suma(din1ptr,din2ptr);
                    cout<<*din1ptr<<endl;
                    system("pause");
                    flag=true;
                }    
            }while(!flag);
            break;

        case 2: //resta
            do{
                two_inputs();
                if((is_double(to_string(din1))==0)||(is_double(to_string(din2))==0)){
                    cout << "Solo puede ingresar números." << endl << "intente de nuevo..." << endl;
                    system("pause");
                    flag = false;
                }
                else{
                    cout<<din1<<" - "<<din2<<" = ";
                    resta(din1ptr,din2ptr);
                    cout<<*din1ptr<<endl;
                    system("pause");
                    flag=true;
                }
            }while(!flag);
            break;
        
        case 3: //multiplicacion
            do{
                two_inputs();
                if((is_double(to_string(din1))==0)||(is_double(to_string(din2))==0)){
                    cout << "Solo puede ingresar números." << endl << "intente de nuevo..." << endl;
                    system("pause");
                    flag = false;
                }
                else{
                    cout<<din1<<" * "<<din2<<" = ";
                    multiplicacion(din1ptr,din2ptr);
                    cout<<*din1ptr<<endl;
                    system("pause");
                    flag=true;
                }
            }while(!flag);
            break;
        
        case 4: //division
            do{
                two_inputs();
                if((is_double(to_string(din1))==0)||(is_double(to_string(din2))==0)){
                    cout << "Solo puede ingresar números." << endl << "intente de nuevo..." << endl;
                    system("pause");
                    flag = false; 
                }
                else{
                    cout<<din1<<" / "<<din2<<" = ";
                    division(din1ptr,din2ptr);
                    cout<<*din1ptr<<endl;
                    system("pause");
                    flag=true;
                }
            }while(!flag);
            break;
        
        case 5: //potencia
            do{
                system("cls");
                cout<<"Ingrese la base: ";
                cin>>din1;
                din1ptr = &din1;
                cout<<"Ingrese el exponente: ";
                cin>>din2;
                din2ptr = &din2;
                if((is_double(to_string(din1))==0)||(is_double(to_string(din2))==0)){
                    cout << "Solo puede ingresar números." << endl << "intente de nuevo..." << endl;
                    system("pause");
                    flag = false; 
                }
                else{                    
                    cout<<din1<<" ^ "<<din2<<" = ";
                    potencia(din1ptr,din2ptr);
                    cout<< std::fixed << *din1ptr<<endl;
                    system("pause");
                    flag = true;
                }
            }while(!flag);
            break;
        
        case 6: //facotorial
            do{
                system("cls");
                cout<<"Ingrese el numero: ";
                cin>>din1;
                din1ptr = &din1;
                if(is_double(to_string(din1))==0){
                    cout << "Solo puede ingresar números." << endl << "intente de nuevo..." << endl;
                    system("pause");
                    flag = false; 
                }
                else{
                    cout << din1 << "!" << " = ";
                    factorial(din1ptr);
                    cout << std::fixed << *din1ptr<<endl;
                    system("pause");
                    flag = true;
                }
            }while(!flag);
            break;

        case 7: //decimal a binario
            do{
                system("cls");
                cout << "Ingrese un numero entero: ";
                cin >> intin;
                intinptr = &intin;
                if(is_digit(to_string(intin))==0){
                    cout << "Solo puede ingresar números." << endl << "intente de nuevo..." << endl;
                    system("pause");
                    flag = false; 
                }
                else{
                    cout <<intin;
                    cout <<" = " << dec_to_bin(intinptr)<< endl;
                    system("pause");
                    flag = true;
                }
            }while(!flag);
            break;
        
        case 8: // binario a decimal
            do{
                system("cls");
                *intinptr=0;
                cout << "Ingrese una cadena de bits: ";
                cin >> strin;
                if(is_binary(strin)==0){
                    cout << "Solo puede ingresar 1s o 0s" << endl << "intente de nuevo..." << endl;
                    system("pause");
                    flag = false; 
                }
                else{
                    bin_to_dec(strin,intinptr);
                    cout << strin << " = " << intin << endl;
                    system("pause");
                    flag = true;
                }
            }while(!flag);                
            break;

        case 9: // decimal a octal
            do{
                system("cls");
                cout << "Ingrese un numero entero: ";
                cin >> intin;
                intinptr = &intin;
                if(is_digit(to_string(intin))==0){
                    cout << "Solo puede ingresar números." << endl << "intente de nuevo..." << endl;
                    system("pause");
                    flag = false; 
                }
                else{
                    cout <<intin;
                    cout << " = " << dec_to_oc(intinptr) << endl;
                    system("pause");
                    flag = true;
                }
            }while(!flag);
            break;

        case 10: //Octal a decimal
            do{
                system("cls");
                cout << "Ingrese un numero en notacion octal: ";
                cin >> intin;
                intinptr = &intin;
                if(is_octal(to_string(intin))==0){
                    cout << "Solo puede ingresar números del 0 al 7" << endl << "intente de nuevo..." << endl;
                    system("pause");
                    flag = false; 
                }
                else{
                    cout <<intin;
                    cout << " = " << oc_to_dec(intinptr) << endl;
                    system("pause");
                    flag = true;
                }
            }while(!flag);
            break;

        case 11: //decimal a hexadecimal
            do{
                system("cls");
                cout << "Ingrese un numero entero: ";
                cin >> intin;
                intinptr = &intin;
                if(is_digit(to_string(intin))==0){
                    cout << "Solo puede ingresar números." << endl << "intente de nuevo..." << endl;
                    system("pause");
                    flag = false; 
                }
                else{
                    cout <<intin;
                    cout <<" = " << dec_to_hex(intinptr)<< endl;
                    system("pause");
                    flag = true;
                }
            }while(!flag);
            break;
        
        case 12: //hexadecimal a decimal
            hex_to_dec_input();
            break;
        
        default: 

            system("cls");
            cout << "Opcion invalida..." << endl;
            system("pause"); 
            break;
    }
}


void two_inputs(){
    system("cls");
    cout<<"Ingrese el primer numero: ";
    cin>>din1;
    din1ptr = &din1;
    cout<<"Ingrese el segundo numero: ";
    cin>>din2;
    din2ptr = &din2;
}

int is_digit(string input){
    char c;
    for(int i=0; i<input.length(); i++){
        c = input[i];
        if(isdigit(c)==0){
            return 0;
        }
        else{
            continue;
        }
    }
    return 1;
}

int is_double(string input){
    char c;
    for(int i=0; i<input.length(); i++){
        c = input[i];
        if(isdigit(c) || c == '.'){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int is_binary(string input){
    char c;
    for(int i=0; i<input.length(); i++){
        c = input[i];
        if(c == '1' || c == '0'){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int is_octal(string input){
    char c;
    for(int i=0; i<input.length(); i++){
        c = input[i];
        if(c < 48 || c > 55){
            return 0;
        }
        else{
            continue;
        }
    }
    return 1;
}