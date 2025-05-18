#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool dfs(char** board, int boardSize, int* boardColSize, int i, int j, char* word, int indice, bool** visitado) 
{
    if ( word[indice] == '\0' ) return true; 
    if ( i < 0 || j < 0 || i >= boardSize || j >= boardColSize[i] ||
        visitado[i][j] || board[i][j] != word[indice] )
        return false;

    visitado[i][j] = true;

    bool found = dfs( board, boardSize, boardColSize, i+1, j, word, indice+1, visitado ) ||
                 dfs( board, boardSize, boardColSize, i-1, j, word, indice+1, visitado ) ||
                 dfs( board, boardSize, boardColSize, i, j+1, word, indice+1, visitado ) ||
                 dfs( board, boardSize, boardColSize, i, j-1, word, indice+1, visitado );

    visitado[i][j] = false; 

    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) 
{
    bool** visitado = (bool**)malloc(boardSize * sizeof(bool*));
    for ( int i = 0; i < boardSize; i++ ) 
    {
        visitado[i] = (bool*)calloc(boardColSize[i], sizeof(bool));
    }

    for ( int i = 0; i < boardSize; i++ ) 
    {
        for ( int j = 0; j < boardColSize[i]; j++ ) 
        {
            if ( dfs(board, boardSize, boardColSize, i, j, word, 0, visitado) ) 
            {
                for ( int k = 0; k < boardSize; k++) free(visitado[k] );
                free(visitado);
                return true;
            }
        }
    }

    for ( int i = 0; i < boardSize; i++ ) free(visitado[i]); 
    free(visitado);
    return false;
}

int main() {
    char* row1 = "ABCE";
    char* row2 = "SFCS";
    char* row3 = "ADEE";

    int boardSize = 3;
    int boardColSize[] = {4, 4, 4};

    char** board = (char**)malloc(boardSize * sizeof(char*));
    board[0] = row1;
    board[1] = row2;
    board[2] = row3;

    char word[] = "ABCCED";

    if (exist(board, boardSize, boardColSize, word)) {
        printf("Palavra \"%s\" encontrada!\n", word);
    } else {
        printf("Palavra \"%s\" NÃO encontrada.\n", word);
    }

    free(board);

    return 0;
}
