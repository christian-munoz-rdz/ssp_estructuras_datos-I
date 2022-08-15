class Celsius{
private:
    double grados;
public:
    void set_grados(double);
    double calcula_kelvin();
    double calcula_farenheit();
};

void Celsius::set_grados(double grados){
    this->grados = grados;
}

double Celsius::calcula_kelvin(){
    return this->grados+273.15;
}

double Celsius::calcula_farenheit(){
    return this->grados*1.8+32;
}