#include <iostream>
using namespace std;

class Urna{
private:
    double votos=0;
    double totalvotos;
public:
    void addVoto();
    double getVotos();
    void setTotalVotos(double);
    double getTotalVotos();
};

void Urna::addVoto(){
    this->votos += 1;
}

double Urna::getVotos(){
    return this->votos;
}

void Urna::setTotalVotos(double count){
    this ->totalvotos = count;
}

double Urna::getTotalVotos(){
    return this->totalvotos;
}

class Candidato: public Urna{
private:
    double prcnt;
public:
    void setPorcentaje();
    double getPorcentaje();
};

void Candidato::setPorcentaje(){
    this->prcnt = (this->getVotos()/this->getTotalVotos())*100;
}

double Candidato::getPorcentaje(){
    return this->prcnt;
}

int main() {

    char opc,resp;
    double total=0; 
    Candidato a;
    Candidato b;
    Candidato c;
    do{
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"Candidato -> Anaya [1]"<<endl;
        cout<<"Candidato -> Meade [2]"<<endl;
        cout<<"Candidato -> Amlo [3]"<<endl;
        cout<<"Seleccione opcion>>>";
        cin>>opc;
        cout<<endl;
        cout<<endl;

        switch(opc){
            case '1':
                 a.addVoto();
                break;
            case '2':
                b.addVoto();
                break;
            case '3':
                c.addVoto();
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                system("pause");
                break;
        }

        cout<<"*********VOTOS**********"<<endl;
        cout<<" Anaya: "<<a.getVotos() <<endl;
        cout<<" Meade: "<<b.getVotos()<<endl;
        cout<<" Amlo: "<<c.getVotos()<<endl;
        cout<<endl<<endl;

        total = a.getVotos() + b.getVotos() + c.getVotos();

        a.setTotalVotos(total);
        b.setTotalVotos(total);
        c.setTotalVotos(total);
        a.setPorcentaje();
        b.setPorcentaje();
        c.setPorcentaje();

        cout<<"*****PORCENTAJES********"<<endl;
        cout<<"% Anaya "<<a.getPorcentaje()<<endl;
        cout<<"% Meade "<<b.getPorcentaje()<<endl;
        cout<<"% AMLO "<<c.getPorcentaje()<<endl;
        cout<<endl<<endl;
        cout<<"Ingresar nuevo voto 1 [si] 2[no]>>>";
        cin>>resp;
    }while(resp!='2');
    return 0;
}