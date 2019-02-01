#include <stdio.h>
#include <math.h>

int polinomio(int x){
    int res;
    res=(3*pow(x,5))+(2*pow(x,4))-(5*pow(x,3))-(pow(x,2))+(7*x)-(6);
    return res;
}

int main(int argc, char const *argv[])
{
    int x, resultado;
	printf("Introduzca un valor para x: \n");
    scanf("%d", &x);
    printf("El resultado del polinomio 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 con x=%d es:\n", x);
    resultado=polinomio (x);
    printf("%d\n", resultado);
    return 0;
}
