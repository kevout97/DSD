#include "Temperature.h"
#include <iostream>
using namespace std;
Temperature::Temperature(double kelvin){
    degrees = kelvin;
}
void Temperature::setTempKelvin(double kelvin){
    degrees = kelvin;   
    return;
}
void Temperature::setTempFahrenheity(double fahrenheity){
    degrees = (fahrenheity - 32) * 0.55555 + 273.15;
    return;
}
void Temperature::setTempCelsiusque(double celsius){
    degrees = celsius + 273.15;
    return;
}
void Temperature::printTempKelvin(){
    cout << "The temperature is: " << degrees << " °K\n";
    return;
}
void Temperature::printTempFahrenheity(){
    cout << "The Temperature is: " << ( (degrees - 273.15) * (1.8) + 32) << " °F\n";
    return;
}
void Temperature::printTempCelsiusque(){
    cout << "The temperature is: " << (degrees - 273.15) << " °C\n";
}