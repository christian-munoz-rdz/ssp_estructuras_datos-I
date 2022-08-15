#include <iostream>

using namespace std;

int vector []={78,5,7,9,90,15};

int mayor (int *);

int main() {
    int *pv;
    pv = &vector[0];
    
    int m = mayor(pv);
    cout<<"El numero mayor es:" << m;
    return 0;
}

int mayor(int *vector){
    
    int *mayor = &vector[0];

    for(int i=1; i<6; i++){
        if(vector[i] > *mayor)
            *mayor= vector[i];
    }
    return *mayor;
}