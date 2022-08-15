#include <iostream>
#include <string>

using namespace std;

class Moneda{
private:
    double pesos;
    double dolares;
    double euros;
    double yenes;
    double yuanes;
public:
    void setPesos(double);
    double getPesos();
    void setDolares(double);
    double getDolares();
    void setEuros(double);
    double getEuros();
    void setYenes(double);
    double getYenes();
    void setYuanes(double);
    double getYuanes();
    void clear();
};

void Moneda::setPesos(double pesos){
    this->pesos = pesos;
}

double Moneda::getPesos(){
    return this->pesos;
}

void Moneda::setDolares(double dolares){
    this->dolares = dolares;
}

double Moneda::getDolares(){
    return this->dolares;
}

void Moneda::setEuros(double euros){
    this->euros = euros;
}

double Moneda::getEuros(){
    return this->euros;
}

void Moneda::setYenes(double yenes){
    this->yenes = yenes;
}

double Moneda::getYenes(){
    return this->yenes;
}

void Moneda::setYuanes(double yuanes){
    this->yuanes = yuanes;
}

double Moneda::getYuanes(){
    return this->yuanes;
}

void Moneda::clear(){
    this->pesos=0;
    this->dolares=0;
    this->euros=0;
    this->yenes=0;
    this->yuanes=0;
}

class Peso: public Moneda{
public:
    void toDolares();
    void toEuros();
    void toYenes();
    void toYuanes();
};

void Peso::toDolares(){
    this->setDolares(this->getPesos()*0.049);
}

void Peso::toEuros(){
    this->setEuros(this->getPesos()*0.044);
}

void Peso::toYenes(){
    this->setYenes(this->getPesos()*5.61);
}

void Peso::toYuanes(){
    this->setYuanes(this->getPesos()*0.31 );
}

class Dolar: public Moneda{
public:
    void toPesos();
};

void Dolar::toPesos(){
    this->setPesos(this->getDolares()*20.42);
}

class Euro: public Moneda{
public:
    void toPesos();
};

void Euro::toPesos(){
    this->setPesos(this->getEuros()*22.92);
}

class Yen: public Moneda{
public:
    void toPesos();
};

void Yen::toPesos(){
    this->setPesos(this->getYenes()*0.18);
}

class Yuan: public Moneda{
public:
    void toPesos();
};

void Yuan::toPesos(){
    this->setPesos(this->getYuanes()*3.23);
}

bool d_input(string);
bool i_input(string);
void menu();
void opciones(int);

string input1;
Peso p;
Dolar d;
Euro e;
Yen ye;
Yuan yu;
bool ban=true;

int main(){
    menu();
    return 0;
}

void menu(){
    string opc;
    do{
        system("cls");
        cout<<"1)Peso a Dolar"<<endl
        <<"2)Dolar a Peso"<<endl
        <<"3)Peso a Euro"<<endl
        <<"4)Euro a Peso"<<endl
        <<"5)Peso a Yen"<<endl
        <<"6)Yen a Peso"<<endl
        <<"7)Peso a Yuan"<<endl
        <<"8)Yuan a Peso"<<endl
        <<"9)Salir"<<endl
        <<"Elija una opcion >>>>>";
        cin>>opc;
        if(!i_input(opc)){
            cout << "Error! Ingrese un numero"<<endl;
            system("pause");
        }
        else{
            opciones(stoi(opc));
        }
    }while(ban);
}

void opciones(int opc){
    switch (opc)
    {
    case 1:
        system("cls");
        cout << "PESOS A DOLARES" << endl << endl;
        cout << "Inngrese los pesos>>>";
        cin >> input1;
        if(!d_input(input1)){
            cout << "Error!los valores deben ser numericos"<<endl;
            system("pause");
        }
        else{
            p.setPesos(stod(input1));
            p.toDolares();
            cout<< p.getPesos() << " Pesos = " << p.getDolares() << " Dolares"<< endl;
            p.clear();
            system("pause");
        }
        break;

    case 2:
        system("cls");
        cout << "DOLARES A PESOS" << endl << endl;
        cout << "Inngrese los dolares>>>";
        cin >> input1;
        if(!d_input(input1)){
            cout << "Error!los valores deben ser numericos"<<endl;
            system("pause");
        }
        else{
            d.setDolares(stod(input1));
            d.toPesos();
            cout << d.getDolares() << " Dolares = " << d.getPesos() << " Pesos" << endl;
            d.clear();
            system("pause");
        }
        break;

    case 3:
        system("cls");
        cout << "PESOS A EUROS" << endl << endl;
        cout << "Inngrese los pesos>>>";
        cin >> input1;
        if(!d_input(input1)){
            cout << "Error!los valores deben ser numericos"<<endl;
            system("pause");
        }
        else{
            p.setPesos(stod(input1));
            p.toEuros();
            cout<< p.getPesos() << " Pesos = " << p.getEuros() << " Euros" << endl;
            p.clear();
            system("pause");
        }
        break;
    
    case 4:
        system("cls");
        cout << "EUROS A PESOS" << endl << endl;
        cout << "Inngrese los euros>>>";
        cin >> input1;
        if(!d_input(input1)){
            cout << "Error!los valores deben ser numericos"<<endl;
            system("pause");
        }
        else{
            e.setEuros(stod(input1));
            e.toPesos();
            cout << e.getEuros() << " Euros = " << e.getPesos() << " Pesos" << endl;
            e.clear();
            system("pause");
        }
        break;

    case 5:
        system("cls");
        cout << "PESOS A YENES" << endl << endl;
        cout << "Inngrese los pesos>>>";
        cin >> input1;
        if(!d_input(input1)){
            cout << "Error!los valores deben ser numericos"<<endl;
            system("pause");
        }
        else{
            p.setPesos(stod(input1));
            p.toYenes();
            cout << p.getPesos() << " Pesos = " << p.getYenes() << " Yenes" << endl;
            p.clear();
            system("pause");
        }
        break;

    case 6:
        system("cls");
        cout << "YENES A PESOS" << endl << endl;
        cout << "Inngrese los yenes>>>";
        cin >> input1;
        if(!d_input(input1)){
            cout << "Error!los valores deben ser numericos"<<endl;
            system("pause");
        }
        else{
            ye.setYenes(stod(input1));
            ye.toPesos();
            cout << ye.getYenes() << " Yenes = " << ye.getPesos() << " Pesos" << endl;
            ye.clear();
            system("pause");
        }
        break;

    case 7:
        system("cls");
        cout << "PESOS A YUANES" << endl << endl;
        cout << "Inngrese los pesos>>>";
        cin >> input1;
        if(!d_input(input1)){
            cout << "Error!los valores deben ser numericos"<<endl;
            system("pause");
        }
        else{
            p.setPesos(stod(input1));
            p.toYuanes();
            cout << p.getPesos() << " Pesos = " << p.getYuanes() << " Yuanes" << endl;
            p.clear();
            system("pause");
        }
        break;

    case 8:
        system("cls");
        cout << "YUANES A PESOS" << endl << endl;
        cout << "Inngrese los yuanes>>>";
        cin >> input1;
        if(!d_input(input1)){
            cout << "Error!los valores deben ser numericos"<<endl;
            system("pause");
        }
        else{
            yu.setYuanes(stod(input1));
            yu.toPesos();
            cout << yu.getYuanes() << " Yuanes = " << yu.getPesos() << " Pesos" << endl;
            yu.clear();
            system("pause");
        }
        break;

    case 9:
        system("cls");
        cout << "SALIENDO..." << endl;
        ban = false;
        system("pause");
        break;

    default:
        system("cls");
        cout<<"Opcion Invalida..."<<endl;
        system("pause");
        break;
    }
}

bool d_input(string input){
    int length = input.length();
    int point_counter = 0;
    for(int i=0; i<length;i++){

        if(!isdigit(input[i])){
            if(input[i]=='.'){
                point_counter++;
                if(point_counter>1){
                    return false;
                }
            }
            else{
                return false;
            }
        }

    }
    return true;
}

bool i_input(string input){
    int length = input.length();
    for(int i=0; i<length;i++){

        if(!isdigit(input[i])){
            return false;
        }

    }
    return true;
}