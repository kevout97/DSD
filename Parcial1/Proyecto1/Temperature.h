#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_
class Temperature{
private:
    double degrees;
public:
    Temperature(double = 310.15);
    void setTempKelvin(double);
    void setTempFahrenheity(double);
    void setTempCelsiusque(double);
    void printTempKelvin();
    void printTempFahrenheity();
    void printTempCelsiusque();
};
#endif