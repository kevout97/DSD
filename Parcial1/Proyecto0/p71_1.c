//Números al revés 
# include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Introduce un número de dos dígitos: ");
    scanf("%d", &n);
    printf("El número al revés del que ingresó es: %d%d\n", n%10, n/10);
    return 0;
}
