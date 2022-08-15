class Rectangulo{
private:
    double base;
    double altura;
    double area;
public:
    void setBase(double);
    double getBase();
    void setAltura(double);
    double getAltura();
    void calculaArea();
    double getArea();
};

void Rectangulo::setBase(double base){
    this->base = base;
}

double Rectangulo::getBase(){
    return this->base;
}

void Rectangulo::setAltura(double altura){
    this->altura = altura;
}

double Rectangulo::getAltura(){
    return this->altura;
}

void Rectangulo::calculaArea(){
    this->area = this->base*this->altura;
}

double Rectangulo::getArea(){
    return this->area;
}