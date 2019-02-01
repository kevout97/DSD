#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num[10], suma=0;
    for(int i=1;i<argc;i++){
        num[i]=atoi(argv[i]);
        suma=suma+num[i];
    }
    printf("La suma es: %d\n", suma);
    return 0;
}
