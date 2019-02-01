# include <stdio.h>

int main(int argc, char const *argv[])
{
    int sum = 0;
    for(int i=0;i<10;i++){
        if(i%2)
            continue;
        sum += i;
    }
    printf("%d\n", sum); //Imprime 20
    return 0;
}
