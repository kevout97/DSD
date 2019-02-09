/*
Defina  una  clase  Temperatura  que  almacene  de  manera  interna  un  valor  de  temperatura  en grados Kelvin. 
También elabore las funciones setTempKelvin, setTempFahrenheity setTempCelsiusque tomen  la  temperatura  en  la  escala  especificada  por  el  usuario  y  la  almacenen  en  grados  Kelvin. 
Asimismo  escriba  las  funciones  que  impriman  el  valor  almacenado  en  la  clase  y  en  los  grados Centigrados,  Kelvin  o  Fahrenheit,  según  lo  solicite  el  usuario.  
Escriba  una  función  principal  para probar la clase
*/
#include <iostream>
#include "Temperature.h"
using namespace std;
int main() {   
    Temperature t;
    t.printTempCelsiusque();
    t.printTempFahrenheity();
    t.printTempKelvin();

    t.setTempCelsiusque(10);
    t.printTempCelsiusque();
    t.printTempFahrenheity();
    t.printTempKelvin();

    t.setTempFahrenheity(64);
    t.printTempCelsiusque();
    t.printTempFahrenheity();
    t.printTempKelvin();
}