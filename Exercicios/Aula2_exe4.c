#include <stdio.h>
#include <stdlib.h>

void *meuRealloc(void *pont, size_t oldSize, size_t newSize);

int main()
{
    size_t sizeVetor = 5; // size_t é um unsigned int, ou seja, nao só sao apenas valores positivos, mas tambem tem um range maior de valores positivos.
    
/*   
    printf("Digite o tamanho do vetor: ");
    scanf("%zu", &sizeVetor);
*/
    int *vetor;
    vetor = (int*) malloc(sizeof(int) * sizeVetor);
    if(!vetor)
    {
        printf("\tErro ao alocar a memoria dinamicamente.\n");
        return -1;
    }
    vetor[0] = 1;
    vetor[1] = 2;
    vetor[2] = 3;
    vetor[3] = 4;
    vetor[4] = 5;

    int *realocVetor;
    realocVetor = meuRealloc(vetor, sizeVetor, 15);

    realocVetor[5] = 6;
    realocVetor[6] = 7;
    realocVetor[7] = 8;
    realocVetor[8] = 9;
    realocVetor[9] = 10;
    realocVetor[10] = 11;
    realocVetor[11] = 12;
    realocVetor[12] = 13;
    realocVetor[13] = 14;
    realocVetor[14] = 15;

    for(int i = 0; i < 15; i++)
    {
        printf("\tVetor Realocado[%d]: %d\n", i, realocVetor[i]);
    }

    free(realocVetor);
    return 0;
}

void *meuRealloc(void *pont, size_t oldSize, size_t newSize)
{
    int *oldVetor = (int*)pont; // Passando ele de tipo void* para int*
    int *newVetor;
    newVetor = (int*) malloc(sizeof(int) * newSize);
    if(!newVetor)
    {
        printf("\tErro ao alocar a memoria dinamicamente.\n");
        exit(1);
    }

    if(newSize >= oldSize) 
    {
        for(int i = 0; i < oldSize; i++)
        {
            newVetor[i] = oldVetor[i];
        }
    }else if(oldSize > newSize)
    {
        for(int i = 0; i < newSize; i++)
        {
            newVetor[i] = oldVetor[i];
        }
    }
    free(oldVetor);
    return newVetor;
}