#include <stdio.h>

int main(int argc, char const *argv[])
{
    char frase[100];
    int i, k;
    printf("Introduzca una frase: ");
    scanf("%[^\n]", frase);
    k=strlen(frase);
    printf("La frase al revés es:\t");
    for(i=k;i>=0;i--)
        printf("%c",frase[i]);
    printf("\n");
    return 0;
}