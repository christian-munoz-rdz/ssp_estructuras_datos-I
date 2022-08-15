#include <iostream>

using namespace std;

void factorial(double *num){
    if(*num>1){
        for(int i=*num-1;i>0;i--)
            *num=*num*i;
    }        
}

int main(){
    double *iNum= new double;

    cout << "Ingrese un numero: ";
    cin >> *iNum;

    factorial(iNum);

    cout << "Factorial: "<< std::fixed << *iNum;

    return 0;
}


