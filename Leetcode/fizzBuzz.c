#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fizzBuzz(int n, int* returnSize) 
{
    *returnSize = n;
    char **answer;
    char buffer[12];

    answer = NULL;
    answer = malloc(sizeof(*answer) * n);
    if(!answer)
    {
        return (answer);
    }
    for( int i = 0; i < n; i++ )
    {
        if( (i + 1) % 15 == 0)
        {
            answer[i] = strdup("FizzBuzz");
        } else 
        if( (i + 1) % 3 == 0 )
        {
            answer[i] = strdup("Fizz");
        } else 
        if( (i + 1) % 5 == 0 )
        {
           answer[i] = strdup("Buzz");
        } else
        {
            sprintf(buffer, "%d", i + 1);
            answer[i] = strdup(buffer);
        }
    }

    return answer;
}

int main() {
    int n = 20;
    int returnSize;

    char** resultado = fizzBuzz(n, &returnSize);

    printf("Resultado do FizzBuzz até %d:\n", n);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", resultado[i]);
        free(resultado[i]);  // liberar cada string alocada
    }

    free(resultado);  // liberar o array de ponteiros
    return 0;
}
