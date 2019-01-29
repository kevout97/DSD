//Secuencia con 17 y -17
# include <stdio.h>

int main(int argc, char const *argv[])
{
    int i=17;
    printf("'printf(\"%%d\", i >= 0 ? i : -i)' con i=17:\t");
    printf("%d\n", i >= 0 ? i : -i);
    i=-17;
    printf("'printf(\"%%d\", i >= 0 ? i : -i)' con i=-17:\t");
    printf("%d\n", i >= 0 ? i : -i);
    return 0;
}
