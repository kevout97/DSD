//Mayor número
# include <stdio.h>

int main(int argc, char const *argv[])
{
    float n, o=0;
    int i=0;
    do{
        printf("Escribe un número: ");
        scanf("%f", &n);
        if(n > o)
            o=n;
    }while (n > 0);
    printf("El mayor es: %0.2f\n", o);
    return 0;
}
