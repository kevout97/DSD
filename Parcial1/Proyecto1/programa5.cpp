/* Defina una clase llamada Fraccion, la cual almacena un numerador y un denominador enteros. 
Debe incluir una función para que el usuario pueda inicializar a ambos, así como una función que devuelva el resultado de la división entre el numerador y el denominador como un double. 
Por último debe existir una función que devuelva a la fracción en su mínima expresión. Por ejemplo la fracción 18/15 deberá imprimirse como 6/5. 
Pruebe la clase con el código mínimo en el programa principal. 
 */
#include <iostream>
#include "Fraccion.h"
using namespace std;
int main() {   
    Fraccion f;
    f.inicializarFraccion(50,100);
    f.imprimeFraccion();
    cout << "La division es: " << f.division() << "\n";
    cout << "Aplicando Simplificacion...\n";
    f.simplificacion();
    f.imprimeFraccion();
}