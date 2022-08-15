class Kelvin{
private:
    double grados;
public:
    void set_grados(double);
    double calcula_Celsius();
};

void Kelvin::set_grados(double grados){
    this->grados = grados;
}

double Kelvin::calcula_Celsius(){
    return this->grados-273.15;
}