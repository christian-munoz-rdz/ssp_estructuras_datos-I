#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

void hex_to_dec(string,int*);
string mayusculas(string);
int is_hex(string);

bool flag_hex;

void hex_to_dec_input(){
    string hex;
    int dec=0;
    int *decptr = &dec;
    do{
        system("cls");
        cout << "Ingrese una cadena hexadecimal: ";
        cin >> hex;
        hex = mayusculas(hex);
        if(is_hex(hex)==0){
            cout << "Solo puede ingresar numeros del 0 al 9 o letras de la A a la F" << endl << "intente de nuevo..." << endl;
            system("pause");
            flag_hex = false; 
        }
        else{
            hex_to_dec(hex,decptr);
            cout << hex << " = " << dec << endl;
            system("pause");
            flag_hex = true;               }
    }while(!flag_hex);    
}

void hex_to_dec(string hex, int* dec){
    string decode = "0123456789ABCDEF";
    int str_size = hex.length();
    int exp=0,val;

    for(int i=str_size-1; i>=0; i--){
        val = 0;
        for(int j=0; j<16;j++){
            if(hex[i]==decode[j]){
                val=j;
                break;
            }
        }
        *dec += val * pow(16,exp);
        exp++;
    }
}


string mayusculas(string s)
{
    transform(s.begin(), s.end(), s.begin(),[](unsigned char c){ return toupper(c); });
    return s;
}

int is_hex(string input){
    char c;
    for(int i=0; i<input.length(); i++){
        c = input[i];
        if(isalpha(c)){
            if(c>=65 && c<=70)
                continue;
            else{
                return 0;
            }
        }
        else if(isdigit(c)){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}