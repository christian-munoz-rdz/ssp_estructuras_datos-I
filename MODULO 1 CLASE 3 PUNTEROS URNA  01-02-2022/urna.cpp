#include <iostream>
using namespace std;

struct Candidato{
    double votos=0;
    double porcentaje;
};

double setVoto(double votos){
    votos+=1;
    return votos;
}

double setPorcentajes(double voto1,double voto2,double voto3){
    double porcentaje;
    porcentaje=(voto1*100)/(voto1+voto2+voto3);
    return porcentaje;
}

int main(int argc, char** argv) {

    int opc=0, resp;
    Candidato *a = new Candidato();
    Candidato *b = new Candidato();
    Candidato *c = new Candidato();
    
    do{
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"Candidato -> Atlas [1]"<<endl;
        cout<<"Candidato -> Chivas [2]"<<endl;
        cout<<"Candidato -> Toluca [3]"<<endl;
        cout<<"Seleccione opcion"<<endl;
        cin>>opc;
        cout<<endl;
        cout<<endl;

        switch(opc){
            case 1:
                a->votos = setVoto(a->votos);
                break;
            case 2:
                b->votos = setVoto(b->votos);
                break;
            case 3:
                c->votos = setVoto(c->votos);
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                break;
        }

        cout<<"*********VOTOS**********"<<endl;
        cout<<" Atlas: "<<a->votos<<endl;
        cout<<" Chivas: "<<b->votos<<endl;
        cout<<" Toluca: "<<c->votos<<endl;
        cout<<endl<<endl;

        a->porcentaje= setPorcentajes(a->votos,b->votos,c->votos);
        b->porcentaje= setPorcentajes(b->votos,a->votos,c->votos);
        c->porcentaje= setPorcentajes(c->votos,a->votos,b->votos);
        
        cout<<"*****PORCENTAJES********"<<endl;
        cout<<" % Atlas "<<a->porcentaje<<endl;
        cout<<" % Chivas "<<b->porcentaje<<endl;
        cout<<" % Toluca "<<c->porcentaje<<endl;
        cout<<endl<<endl;
        cout<<"Ingresar nuevo voto 1 [si] 2[no]"<<endl;
        cin>>resp;
    }while(resp!=2);
    
    system("pause");
    return 0;
}