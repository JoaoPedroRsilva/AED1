#include <stdio.h>
#include <stdlib.h>

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize)
{
    int highestValue = 0;
    for( int i = 0; i < accountsSize; i++ )
    {
        int accountsSum = 0;
        for( int j = 0; j < accountsColSize[i]; j++ )
        {
            accountsSum += accounts[i][j];
        }
        if( accountsSum > highestValue ) highestValue = accountsSum; 
    }    
    return highestValue;
}

int main() {
    // Exemplo de entrada: [[1,2,3],[3,2,1]]
    int data[][3] = {
        {1, 2, 3},
        {3, 2, 1}
    };
    int accountsSize = 2;
    int cols = 3;

    // Alocar ponteiros para cada linha
    int** accounts = malloc(accountsSize * sizeof(int*));
    for (int i = 0; i < accountsSize; i++) {
        accounts[i] = data[i];  // aponta para as linhas da matriz estática
    }

    int* accountsColSize = malloc(accountsSize * sizeof(int));
    for (int i = 0; i < accountsSize; i++) {
        accountsColSize[i] = cols;
    }

    int resultado = maximumWealth(accounts, accountsSize, accountsColSize);
    printf("Maior riqueza: %d\n", resultado);

    free(accounts);
    free(accountsColSize);
    return 0;
}
