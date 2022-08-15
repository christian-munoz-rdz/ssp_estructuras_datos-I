#include <iostream>
#include <cstdlib>

using namespace std;
int suma(int*,int*);

int main(){
	system("cls");
    int numero1=0, numero2=0;
    int* ptr1=NULL,* ptr2=NULL;
	cout<<"Ingrese numero1: ";
	cin>>numero1;
	cout<<"Ingrese numero 2: ";
	cin>>numero2;
	ptr1=&numero1;
	ptr2=&numero2;
	cout<<"Resultado: "<<suma(ptr1,ptr2)<<endl;
	system("PAUSE");
    return 0;
}

int suma(int* n1, int* n2){
	int res = 0;
	res = *n1+*n2;
	return res;
}