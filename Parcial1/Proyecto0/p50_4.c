//Teléfono
# include <stdio.h>

int main(int argc, char const *argv[])
{
    char tel[20];
    printf("Introduce tu teléfono en la forma [(xxx) xxx-xxxx]\n");
    scanf("%[^\n]", tel);
    printf("%c%c%c.%c%c%c.%c%c%c%c\n", tel[1],tel[2],tel[3],tel[6],tel[7],tel[8],tel[10],tel[11],tel[12],tel[13]);
    return 0;
}