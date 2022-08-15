class Farenheit{
private:
    double grados;
public:
    void set_grados(double);
    double calcula_Celsius();
};

void Farenheit::set_grados(double grados){
    this->grados = grados;
}

double Farenheit::calcula_Celsius(){
    return (this->grados-32)/1.8;
}
