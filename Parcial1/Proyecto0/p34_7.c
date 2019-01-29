//Dólares
# include <stdio.h>

int main(int argc, char const *argv[])
{
    int d, veinte,diez,cinco,uno;
    printf("Introduzca cuántos dólares: \n");
    scanf("%d", &d);
    
    veinte=d/20;
    d-=veinte*20;
    diez=d/10;
    d-=diez*10;
    cinco=d/5;
    d-=cinco*5;

    
    printf("Billetes de $20: %d\n", veinte);
    printf("Billetes de $10: %d\n", diez);
    printf("Billetes de $5:  %d\n", cinco);
    printf("Billetes de $1:  %d\n", d);
    return 0;
}