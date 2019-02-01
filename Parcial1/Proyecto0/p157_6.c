# include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Tamaño de variable int: %lu\n",sizeof(int));
    printf("Tamaño de variable short: %lu\n",sizeof(short));
    printf("Tamaño de variable long: %lu\n",sizeof(long));
    printf("Tamaño de variable float: %lu\n",sizeof(float));
    printf("Tamaño de variable double: %lu\n",sizeof(double));
    printf("Tamaño de variable long double: %lu\n",sizeof(long double));
    return 0;
}
