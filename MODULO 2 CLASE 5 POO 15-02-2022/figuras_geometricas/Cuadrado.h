class Cuadrado{
private:
    double lado;
    double area;
public:
    void setLado(double);
    double getLado();
    void calculaArea();
    double getArea();
};

void Cuadrado::setLado(double lado){
    this->lado = lado;
}

double Cuadrado::getLado(){
    return this->lado;
}

void Cuadrado::calculaArea(){
    this->area = this->lado*this->lado;
}

double Cuadrado::getArea(){
    return this->area;
}