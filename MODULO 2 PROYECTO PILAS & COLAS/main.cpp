#include "Pila.h"

int main(){
    srand(time(NULL));
    Cola* c = new Cola();
    int opcion;
    do{
        system("cls");
        cout<< "--REGISTRO DE PASAJEROS--" << endl;
        c->Push();
        cout<< "Desea Registrar a otro pasajero? [1]si [cualquier tecla]no >> ";
        cin >> opcion;
    }while(opcion==1);
    hideCursor();
    c->Recepcion();
    c->Asientos();
    c->Equipaje();
    Pila* p = new Pila();
    int auxcount = c->getCount();
    system("cls");
    for(int i=0;i<auxcount;i++){
        p->Push(c->Pop());
    }
    gotoxy(70,23);system("pause");
    system("cls");
    avion();
    auxcount = p->getCount();
    for(int i=0;i<auxcount;i++){
        c->Transfer(p->Pop());
    }
    gotoxy(70,13);system("pause");
    c->Taxi();
    fin();
};
