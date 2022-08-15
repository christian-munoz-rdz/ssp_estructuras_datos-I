#include "ListaDoble.h"

void opciones(int);
ListaDoble<int>* lista = new ListaDoble<int>();

int main(){
    string opc;
    do{
        system("cls");
        cout<<"1)Insertar"<<endl
        <<"2)Eliminar intermedio" <<endl
        <<"3)Eliminar ultimo elemento" <<endl
        <<"4)Buscar"<<endl
        <<"5)Primero"<<endl
        <<"6)Ultimo"<<endl
        <<"7)Tamanho"<<endl
        <<"8)Vaciar"<<endl
        <<"9)Mostrar Lista"<<endl
        <<"10)Mostrar Lista en Reversa"<<endl
        <<"11)Ordenar de forma ascendente"<<endl
        <<"12)Ordenar de forma descendente"<<endl
        <<"13)Salir"<<endl
        <<"Elija una opcion >>>>>";
        cin>>opc;
        if (!i_input(opc))
            opc="15";
        opciones(stoi(opc));
    }while(stoi(opc)!=13);
    return 0;
}

void opciones(int opc){
    string numSearch;
    string insert;
    string index;
    int int_index;
    bool confirmation;
    switch (opc){
    case 1:
        system("cls");
        cout << "INSERTAR NUMERO" << endl << endl;
        cout <<"a)Insertar al inicio"<< endl
        <<"b)Insertar al final"<< endl
        <<"c)Insertar en indice intermedio"<< endl
        <<"Elija una opcion >>> ";
        cin>>insert;
        if(insert.length()!=1)
            insert="d";
        switch (insert[0]){
            case 'a':
            case 'A':
                lista->InsertarInicio();
                break;
            case 'b':
            case 'B':
                lista->InsertarFinal();
                break;
            case 'c':
            case 'C':
                cout<<"ELija un indice>> ";
                cin>>index;
                if(!i_input(index))
                    index="-1";
                lista->InsertarMedio(stoi(index));
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                system("pause");
                break;
        }
        break;

    case 2:
        system("cls");
        cout << "ELIMINAR NUMERO" << endl << endl;
        cout << "Ingrese el numero a eliminar>>>";
        cin >> numSearch;
        if(!i_input(numSearch))
            cout<<"Ingrese numeros solamente"<<endl;
        else{
            confirmation = lista->RemoverMedio(lista->BuscarIndice(stoi(numSearch)));
            if(confirmation)
                cout << "Elemento removido con exito" << endl;
            else
                cout << "No fue posible remover el elemento debido a que no existe en la lista" << endl;
        }
        system("pause");
        break;
    case 3:
        system("cls");
        cout << "ELIMINAR ULTIMO NUMERO" << endl << endl;
        if(lista->Cabecera==NULL)
            cout << "La lista esta vacia" << endl;
        else
            lista->RemoverFinal();
            cout<<"Elemento eliminado con exito"<<endl;
        system("pause");
        break;
    case 4:
        system("cls");
        cout << "BUSCAR NUMERO" << endl << endl;
        cout << "Inngrese el numero a buscar>>>";
        cin >> numSearch;
        if(!i_input(numSearch))
            cout<<"Ingrese numeros solamente"<<endl;
        else{
            int_index = lista->BuscarIndice(stoi(numSearch));
            if(int_index!=-1)
                cout<<numSearch<<" encontrado en el indice " << int_index << endl;
            else
                cout<<"Numero no encontrado en la lista..." << endl;
        }
        system("pause");
        break;
    
    case 5:
        system("cls");
        cout << "MOSTRAR EL PRIMER ELEMENTO" << endl << endl;
        if(lista->Cabecera==NULL)
            cout << "La lista esta vacia" << endl;
        else
            cout << "Primer numero: " << lista->Primero()<<endl;
        system("pause");
        break;

    case 6:
        system("cls");
        cout << "MOSTRAR EL ULTIMO ELEMENTO" << endl << endl;
        if(lista->Cabecera==NULL)
            cout << "La lista esta vacia" << endl;
        else
            cout << "Ultimo numero: " << lista->Ultimo()<<endl;
        system("pause");
        break;
        

    case 7:
        system("cls");
        cout << "MOSTRAR TAMANO DE LA LISTA" << endl << endl;
        cout << "La lista tiene " << lista->Tamanho() << " elementos" << endl;
        system("pause");
        break;

    case 8:
        system("cls");
        cout << "VACIAR LA LISTA" << endl << endl;
        lista->VaciarLista();
        system("pause");
        break;

    case 9:
        system("cls");
        cout << "MOSTRAR LISTA" << endl << endl;
        if (lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else{
            lista->MostrarLista();
        }
        system("pause");
        break;

    case 10:
        system("cls");
        cout << "MOSTRAR LISTA EN REVERSA" << endl << endl;
        if (lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else{
            lista->MostrarReversa();
        }
        system("pause");
        break;
    
    case 11:
        system("cls");
        cout<<"ORDENAR DE FORMA ASCENDENTE"<<endl;
        cout<<"ANTES--->";
        lista->MostrarLista();
        lista->AscSort();
        cout<<"DESPUES--->";
        lista->MostrarLista();
        system("pause");
        break;

    case 12:
        system("cls");
        cout<<"ORDENAR DE FORMA DESCENDENTE"<<endl;
        cout<<"ANTES--->";
        lista->MostrarLista();
        lista->DescSort();
        cout<<"DESPUES--->";
        lista->MostrarLista();
        system("pause");
        break;

    case 13:
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