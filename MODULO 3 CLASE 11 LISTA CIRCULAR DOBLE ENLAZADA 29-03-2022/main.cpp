#include "CircularList.h"

void opciones(int);
CircularList* list = new CircularList();

int main(){
    string opc;
    do{
        system("cls");
        cout<<"1)Insertar al principio"<<endl
        <<"2)Insertar al final" <<endl
        <<"3)Buscar por posicion" <<endl
        <<"4)Modificar"<<endl
        <<"5)Remover"<<endl
        <<"6)Imprimir"<<endl
        <<"0)Salir"<<endl
        <<"Elija una opcion >>>>>";
        cin>>opc;
        if (!i_input(opc))
            opc="7";
        opciones(stoi(opc));
    }while(stoi(opc)!=0);
    return 0;
}

void opciones(int opc){
    string insert;
    string search;
    int int_index;
    bool confirmation;
    bool retry = false;
    switch (opc){
    case 1:
        do{
            system("cls");
            cout<<"INSERTAR AL PRINCIPIO"<<endl;
            if(retry)
                cout<<"Ingrese un valor valido >>";
            else
                cout<<"Ingrese un numero >>";
            cin>>insert;
            retry = true;
        }while (!i_input(insert));
        list->insert_First(stoi(insert));
        system("pause");
        break;

    case 2:
        do{
            system("cls");
            cout<<"INSERTAR AL FINAL"<<endl;
            if(retry)
                cout<<"Ingrese un valor valido >>";
            else
                cout<<"Ingrese un numero >>";
            cin>>insert;
            retry = true;
        }while (!i_input(insert));
        list->insert_Last(stoi(insert));
        system("pause");
        break;

    case 3:
        do{
            system("cls");
            cout<<"BUSCAR POR POSICION"<<endl;
            if(retry)
                cout<<"Ingrese un valor valido >>";
            else
                cout<<"Ingrese una posicion >>";
            cin>>search;
            retry = true;
        }while (!i_input(search));
        if(list->searchPos(stoi(search))!=NULL)
            cout << "El valor en la posicion " << search << " es " << list->searchPos(stoi(search))->number << endl;
        else
            cout << "Valor no encontrado" << endl;
        system("pause");
        break;

    case 4:
        do{
            system("cls");
            cout<<"MODIFICAR"<<endl;
            if(retry)
                cout<<"Ingrese un valor valido >>";
            else
                cout<<"Ingrese un numero para modificar >>";
            cin>>search;
            retry = true;
        }while(!i_input(search));
        if(list->searchValue(stoi(search))<0)
            cout<<"Valor no encontrado"<<endl;
        else{
            list->searchPos(list->searchValue(stoi(search)))->Mod();
            cout<<"Modificado con exito"<<endl;
        }
        system("pause");
        break;
    
    case 5:
        do{
            system("cls");
            cout<<"REMOVER"<<endl;
            if(retry)
                cout<<"Ingrese un valor valido >>";
            else
                cout<<"Ingrese una posicion >>";
            cin>>search;
            retry = true;
        }while (!i_input(search));
        if(list->searchPos(stoi(search))!=NULL){
            list->remove(stoi(search));
            cout<<"Removido con exito"<<endl;
        }
        else
            cout << "Valor no encontrado" << endl;
        system("pause");
        break;

    case 6:
        system("cls");
        cout<<"IMPRIMIR"<<endl;
        list->print();
        system("pause");
        break;

    case 0:
        system("cls");
        cout<<"Saliendo..."<<endl;
        system("pause");
        break;

    default:
        system("cls");
        cout<<"Opcion Invalida..."<<endl;
        system("pause");
        break;
    }
}