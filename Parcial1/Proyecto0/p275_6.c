
/*Sorts an array od integers using Quicksort algoritm*/
#include <stdio.h>
#include <stdlib.h>
#define N 5

void quicksort(int* a, int* low, int* high);
int* split(int* a, int* low, int* high);

int main(){
    int* a = (int*)malloc(sizeof(int)*N), i;

    printf("Enter %d numbers to be sorted: ", N);
    for(i = 0; i < N; i++)
        scanf("%d",&a[i]);
    int* tmp = (int*)malloc(sizeof(int));
    *tmp = 0;
    int* tmp2 = (int*)malloc(sizeof(int));
    *tmp2 = N - 1;
    quicksort(a,tmp,tmp2);
    printf("In sorted order: ");
    for(i = 0; i< N; i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}

void quicksort(int* a,int* low,int* high){
    int* middle = (int*)malloc(sizeof(int));
    if(*low >= *high) return;
    middle = split(a,low,high);
    int* tmp = (int*)malloc(sizeof(int));
    *tmp = *middle - 1;
    quicksort(a,low,tmp);
    *tmp = *middle + 1;
    quicksort(a,tmp,high);
}

int* split(int* a,int* low, int* high){
    int part_element = a[*low];
    for(;;){
        while (*low < *high && part_element <= a[*high])
            (*high)--;
        if(*low >= *high) break;
        a[(*low)++] = a[*high];

        while(*low < *high && a[*low] <= part_element)
            (*low)++;
        if(*low >= *high) break;
        a[(*high)--] = a[*low];
    }
    a[*high] = part_element;
    return high;
}