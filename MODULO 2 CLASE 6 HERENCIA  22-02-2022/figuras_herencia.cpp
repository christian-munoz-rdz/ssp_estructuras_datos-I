#include <iostream>
#include <string>
#include <cmath>
#define PI 3.14159265
using namespace std;

class Figura{
private:
    double a;
    double b;
    double area;
public:
    void setA(double);
    double getA();
    void setB(double);
    double getB();
    void setArea(double);
    double getArea();
};

void Figura::setA(double a){
    this->a = a;
}

double Figura::getA(){
    return this->a;
}

void Figura::setB(double b){
    this->b = b;
}

double Figura::getB(){
    return this->b;
}

void Figura::setArea(double area){
    this->area = area;
}

double Figura::getArea(){
    return this->area;
}

class Triangulo: public Figura{
public:
    void calculaArea();
};

void Triangulo::calculaArea(){
        this->setArea(this->getA()*this->getB()/2);
}

class Poligono: public Figura{
private:
    double perimetro;
    double m_angulo;
    double apotema;
public:
    void calcular_perimetro();
    void calcular_angulo();
    void calcular_apotema();
    void calcular_area();
};

void Poligono::calcular_perimetro(){
    this->perimetro = this->getA()*this->getB();
}

void Poligono::calcular_angulo(){
    this->m_angulo = 360/(this->getA()*2);
}

void Poligono::calcular_apotema(){
    this->apotema = this->getB()/(2*tan(this->m_angulo*PI/180));
}

void Poligono::calcular_area(){
    calcular_perimetro();
    calcular_angulo();
    calcular_apotema();
    this->setArea(this->perimetro*this->apotema/2);
}

class Cuadrado: public Figura{
public:
    void calculaArea();
};

void Cuadrado::calculaArea(){
    this->setArea(this->getA()*this->getA());
}

class Rectangulo:public Figura{
public:
    void calculaArea();
};

void Rectangulo::calculaArea(){
    this->setArea(this->getA()*this->getB());
}

bool d_input(string);
bool i_input(string);
void menu();
void opciones(int);
void triangulo(double,double);
void cuadrado(double);
void rectangulo(double,double);
void poligono(double,double);

string input1,input2;

int main(){
    menu();
    return 0;
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

void menu(){
    string opc;
    int exit;
    do{
        system("cls");
        cout<<"1)Calcular el area de un Triangulo"<<endl
        <<"2)Calcular el area de un Cuadrado"<<endl
        <<"3)Calcular el area de un Rectangulo"<<endl
        <<"4)Calcular el area de un Poligono"<<endl
        <<">>>>>";
        cin>>opc;
        if(!i_input(opc)){
            cout << "Error!los valores deben ser numericos"<<endl;
        }
        else{
            opciones(stoi(opc));
        }
        cout<<"Continuar 1.Si 2.No"<<endl
        <<">>>>>";
        cin>>exit;
    }while(exit!=2);
    system("pause");
}

void opciones(int opc){
    switch (opc)
    {

    case 1:
        system("cls");
        cout << "AREA DE UN TRIANGULO" << endl << endl;
        cout << "Inngrese la Base>>>";
        cin >> input1;
        cout << "Ingrese la Altura>>>";
        cin >> input2;
        if(!d_input(input1)||!d_input(input2)){
            cout << "Error!los valores deben ser numericos"<<endl;
        }
        else{
            triangulo(stod(input1),stod(input2));
        }
        break;

    case 2:
        system("cls");
        cout << "AREA DE UN CUADRADO" << endl << endl;
        cout << "Inngrese el lado>>>";
        cin >> input1;
        if(!d_input(input1)){
            cout << "Error!los valores deben ser numericos"<<endl;
        }
        else{
            cuadrado(stod(input1));
        }
        break;

    case 3:
        system("cls");
        cout << "AREA DE UN RECTANGULO" << endl << endl;
        cout << "Inngrese la Base>>>";
        cin >> input1;
        cout << "Ingrese la Altura>>>";
        cin >> input2;
        if(!d_input(input1)||!d_input(input2)){
            cout << "Error!los valores deben ser numericos"<<endl;
        }
        else{
            rectangulo(stod(input1),stod(input2));
        }
        break;
    
    case 4:
        system("cls");
        cout << "AREA DE UN POLIGONO" << endl << endl;
        cout << "Inngrese el numero de lados>>>";
        cin >> input1;
        cout << "Ingrese la medida de los lados>>";
        cin >> input2;
        if(!d_input(input1)||!d_input(input2)){
            cout << "Error!"<<endl
            << "Ingrese un valor entero para el numero de lados y un valor real para la medida de los lados"<<endl;
        }
        else{
            poligono(stod(input1),stod(input2));
        }
        break;

    default:
        system("cls");
        cout<<"Opcion Invalida..."<<endl;
        break;
    }
}

void triangulo(double base,double altura){
    Triangulo t;
    t.setA(base);
    t.setB(altura);
    t.calculaArea();
    cout << "Area = " << t.getArea() << endl;
}

void cuadrado(double lado){
    Cuadrado c;
    c.setA(lado);
    c.calculaArea();
    cout << "Area = " << c.getArea() << endl;
}

void rectangulo(double base, double altura){
    Rectangulo r;
    r.setA(base);
    r.setB(altura);
    r.calculaArea();
    cout << "Area = " << r.getArea() << endl;
}

void poligono(double n_lados, double m_lado){
    Poligono p;
    p.setA(n_lados);
    p.setB(m_lado);
    p.calcular_area();
    cout << "Area = " << p.getArea() << endl;
}
