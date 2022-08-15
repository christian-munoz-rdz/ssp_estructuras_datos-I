#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <cstdlib>
#include "hex_to_dec.h"

using std::string;

void suma(double*,double*);
void resta(double*,double*);
void multiplicacion(double*,double*);
void division(double*,double*);
void potencia(double*,double*);
void factorial(double*);
string dec_to_bin(int*);
void bin_to_dec(string,int*);
string dec_to_oc(int*);
int oc_to_dec(int*);
string dec_to_hex(int*);
void hex_to_dec(string,int*);

void suma(double* sumado,double* sumando){
	*sumado += *sumando;
}

void resta(double* minuendo,double* sustraendo){
    *minuendo -= *sustraendo;
}

void multiplicacion(double* multiplicando,double* multiplicador){
    *multiplicando *= *multiplicador;
}

void division(double* dividendo,double* divisor){
    *dividendo /= *divisor;
}

void potencia(double* base,double* exponente){
    double aux=1;
    if((*exponente == 0)||(*base==1)){
        *base = 1;
    }
    else if(*exponente==1){
        return;
    }
    else if (*base==0){
        return;
    }

    for(int i=1; i<=*exponente;i++){
        aux *= *base;
    }

    *base = aux;
}

void factorial(double *num){
    if(*num>1){
        for(int i=*num-1;i>0;i--)
            *num=*num*i;
    }        
}

string dec_to_bin(int* val){
    string decode= "01";
    string bin = "";

    while (*val>1)
    {
        bin = decode[*val%2] + bin;
        *val /= 2;
    }
    bin = decode[*val] + bin;
    return bin;
}

void bin_to_dec(string bit, int* dec){
    int str_size = bit.length();
    int pot = bit.length()-1;
    
    for (int i=0;i<str_size;i++)
    {
        if(bit[i]=='1'){
            *dec += pow(2,pot);
        }
        pot--;
    }
}

string dec_to_hex(int* val){
    string decode= "0123456789ABCDEF";
    string hex = "";

    while (*val>15)
    {
        hex = decode[*val%16] + hex;
        *val /= 16;
    }
    hex = decode[*val] + hex;
    return hex;
}

string dec_to_oc(int* dec){
    string oc="";
    int res;
    while(*dec/8!=0){
        oc = to_string(*dec%8) + oc;
        *dec/=8;
    }
    oc = to_string(*dec%8) + oc;
    return oc;
}

int oc_to_dec(int* oc){
    int dec=0;
    int exp=0;
    while (*oc>=10)
    {
        dec += (*oc%10) * pow(8,exp);
        exp++;
        *oc /= 10;
    }
    dec += *oc * pow(8,exp);
    return dec;
}