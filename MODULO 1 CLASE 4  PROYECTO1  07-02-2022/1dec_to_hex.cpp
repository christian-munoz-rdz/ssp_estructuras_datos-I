#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string dec_to_hex(int*);

int main(){
    system("CLS");
    int num;
    int* numptr = NULL;
    cout << "Conversor Decimal a Hexadecimal" << endl;
    cout << "Digite un número: ";
    cin >> num;
    cout <<num;
    numptr = &num;
    cout <<" = " << dec_to_hex(numptr)<< endl;
    system("PAUSE");
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