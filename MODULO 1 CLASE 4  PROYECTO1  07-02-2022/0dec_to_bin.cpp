#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string dec_to_bin(int*);

int main(){
    system("CLS");
    int num;
    int* numptr = NULL;
    cout << "Conversor Decimal a Binario" << endl;
    cout << "Digite un numero: ";
    cin >> num;
    cout <<num;
    numptr = &num;
    cout <<" = " << dec_to_bin(numptr)<< endl;
    system("PAUSE");
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