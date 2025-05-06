#include <stdio.h>

#define TAM 30

void PreencheArray( int* array, int valor );

int main ()
{
    int array[ TAM ] = { 0 };

    // Trocar o valor para prencher direto na chamada da funçao
    PreencheArray( array, 3 );

    for(int i = 0; i < TAM; i++)
    {
        printf("%d", array[i]);
    }

    return 0;
}

void PreencheArray( int* array, int valor )
{
    // Na declaraçao o '*' nao serve como desreferenciador, mas sim como declarador

    int *p = array;
    int *fim = array + TAM;

    while( p < fim )
    {
        *p = valor;
        p++;
    }
}