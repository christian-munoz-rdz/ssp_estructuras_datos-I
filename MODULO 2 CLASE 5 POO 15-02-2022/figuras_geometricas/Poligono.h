#include <cmath>
#define PI 3.14159265
class Poligono{
private:
    int n_lados;
    double m_lado;
    double perimetro;
    double m_angulo;
    double area;
    double apotema;
public:
    void set_n_lados(int);
    void set_m_lado(double);
    void calcular_perimetro();
    void calcular_angulo();
    void calcular_apotema();
    void calcular_area();
    double get_area();
};

void Poligono::set_n_lados(int n_lados){
    this->n_lados = n_lados;
}

void Poligono::set_m_lado(double m_lado){
    this->m_lado = m_lado;
}

void Poligono::calcular_perimetro(){
    this->perimetro = this->m_lado*this->n_lados;
}

void Poligono::calcular_angulo(){
    this->m_angulo = 360/(this->n_lados*2);
}

void Poligono::calcular_apotema(){
    this->apotema = this->m_lado/(2*tan(this->m_angulo*PI/180));
}

void Poligono::calcular_area(){
    calcular_perimetro();
    calcular_angulo();
    calcular_apotema();
    this->area = this->perimetro*this->apotema/2;
}

double Poligono::get_area(){
    return this->area;
}
