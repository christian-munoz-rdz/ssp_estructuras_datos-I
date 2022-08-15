#include <iostream>
#include <string>
#define MAX 6
using namespace std;

struct contacto
{
	int id;
	string nombre;
	string direccion;
	string email;
	string telefono;
}agenda[MAX];

void RegistrarContacto(struct contacto agenda[], int indice)
{
    agenda[indice].id=indice+1;
	cout<<"ingrese nombre: ";
	fflush(stdin);
	getline(cin, agenda[indice].nombre);
	cout<<"ingrese direccion: ";
	fflush(stdin);
	getline(cin, agenda[indice].direccion);
	cout<<"ingrese email: ";
	fflush(stdin);
	getline(cin, agenda[indice].email);
	fflush(stdin);
	cout<<"ingrese telefono: ";
	fflush(stdin);
	getline(cin, agenda[indice].telefono);
}

int BuscarContacto(int id_buscar)
{
	int posicion=-1,x=0;
	bool flag=false;
	while(x<5 && flag==false)
	{
		if(id_buscar==agenda[x].id)
		{
			flag=true;
			posicion=x;	
		}
		x++;
	}
	return posicion;
}

void MostrarContacto(int posicion)
{
	cout<<"Nombre: "<<agenda[posicion].nombre<<endl;
	cout<<"Direccion: "<<agenda[posicion].direccion<<endl;
	cout<<"Email: "<<agenda[posicion].email<<endl;
	cout<<"Telefono: "<<agenda[posicion].telefono<<endl;
}

void EditarContacto(struct contacto agenda[],int id_buscar)
{
	int opc,seguir;
    do
    {
    	system("CLS");
        cout << "Que deseas modificar?" << endl;
		cout << "1) Nombre" << endl;
		cout << "2) Direccion" << endl;
		cout << "3) Email" << endl;
		cout << "4) Telefono" << endl;
		cout << "Ingresar Opcion: ";
        cin >> opc;

        switch(opc)
            {
                case 1:
                    cout << "Nuevo nombre: ";
					fflush(stdin);
                    getline(cin, agenda[id_buscar-1].nombre);
                    break;
                case 2:
                    cout << "Nueva direccion: ";
					fflush(stdin);
                    getline(cin, agenda[id_buscar-1].direccion);
                    break;
                case 3:
                    cout << "Nuevo email: ";
					fflush(stdin);
                    getline(cin, agenda[id_buscar-1].email);
                    break;
                case 4:
                    cout << "Nuevo telefono: ";
					fflush(stdin);
                    getline(cin, agenda[id_buscar-1].telefono);
                    break;
                default:
                    cout << "Opcion equivocada" << endl;
            }
        cout << "Desea hacer otro cambio? (1)Si (0)No ---->"; 
        cin >> seguir;
    }while(seguir!=0);
}

int eliminarContacto(struct contacto agenda[],int capturado)
{
	int id_eliminar;
	cout<<"Ingrese Id para Eliminar: ";
	cin>>id_eliminar;
	for(int i=id_eliminar-1;i<capturado;i++)
	{
        agenda[i]=agenda[i+1];
		agenda[i].id=i+1;
	}
	cout << "Contacto Eliminado" << endl;
	return capturado=capturado-1;
}

void error()
{
	cout << "No se han registrado contactos" << endl;
    system("PAUSE");
}

int main()
{
	int opc, capturado=0,indice=0;
	int id_buscar;

	do
	{
		system("CLS");
		cout << "1) Registro Contacto" << endl;
		cout << "2) Buscar Contacto" << endl; 
		cout << "3) Editar Contacto" << endl; 
		cout << "4) Remover Contacto" << endl;
		cout << "5) Salir" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opc;

		switch(opc)
		{
			case 1:
				system("CLS");
                if (capturado==MAX)
				   	cout << "Ya se lleno la agenda" << endl;
				else
				{
					RegistrarContacto(agenda,indice);
					indice++;
				   	capturado++;
				}
				system("PAUSE");
				break;
			case 2:
				system("CLS");
                if (capturado==0)
		 		{
					error();
					break;
				}
				cout<<"Ingrese Id a Buscar: ";
	            cin>>id_buscar;
			    MostrarContacto(BuscarContacto(id_buscar));				
				system("PAUSE");
				break;
			case 3:
				system("CLS");
                if (capturado==0)
		 		{
					error();
					break;
				}
				cout<<"Ingrese Id para Editar: ";
	            cin>>id_buscar;
				EditarContacto(agenda,id_buscar);
				system("PAUSE");
				break;
			case 4:
				system("CLS");
                if (capturado==0)
		 		{
					error();
					break;
				}
				capturado=eliminarContacto(agenda,capturado);
				indice=capturado;
				system("PAUSE");
				break;
			case 5:
				cout << "Saliendo..." << endl;
				break;
			default:
				cout << "Opcion equivocada, selecciona otra vez" << endl;
				system("PAUSE");
		}
	}while(opc!=5);
	system("PAUSE");
	return 0;
}
