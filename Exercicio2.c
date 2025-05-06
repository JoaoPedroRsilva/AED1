#include <stdio.h>

#define TAM 10

void PercorreArray( int* array );

int main ()
{
    int array [ TAM ] = { 0,1,2,3,4,5,6,7,8,9 }; 
    PercorreArray(array);

    return 0;
}

void PercorreArray( int* array )
{
    int* ponteiro = array;
    int* fim = array + TAM;

    printf("Array :\n");
    while( ponteiro < fim )
    {
        printf("%d ", *ponteiro);
        ponteiro++;
    }
}