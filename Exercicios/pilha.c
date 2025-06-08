#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct Aluno {
    int matricula;
    int turma;
} Aluno;

typedef struct Pilha {
    Aluno alunos[MAX];
    int topo;
    int base;
    int limite;
} Pilha;

bool push( Pilha* pilha, Aluno* item );
void pop( Pilha* pilha, Aluno* aluno );
bool full( Pilha* pilha );
bool empty( Pilha* pilha );
void reset( Pilha* pilha );
void listar( Pilha* pilha, Pilha* tempP );

int main() {
    Aluno alunos[MAX];
    Aluno tempA; 
    Aluno teste1 = {1001, 1};
    Aluno teste2 = {1002, 2};
    Aluno teste3 = {1003, 3};
    Pilha pilha;
    Pilha tempP;

    reset( &tempP );
    reset( &pilha );

    push( &pilha, &teste1 );
    push( &pilha, &teste2 );
    push( &pilha, &teste3 );

    listar( &pilha, &tempP );
    pop( &pilha, &tempA );
    listar( &pilha, &tempP );
    reset( &pilha );
    listar( &pilha, &tempP );


    return 0;
}

void listar( Pilha* pilha, Pilha* tempP ) {
    if ( !empty( pilha ) && tempP->topo < MAX ) {
        while( pilha->topo > pilha->base )
        {
            ( pilha->topo)--;
            printf("\tMatricula: %d\n\tTurma: %d\n", pilha->alunos[pilha->topo].matricula, pilha->alunos[pilha->topo].turma);
            tempP->alunos[tempP->topo++] = pilha->alunos[pilha->topo]; 
        }

        while( tempP->topo > tempP->base )
        {
            ( tempP->topo)--;
            pilha->alunos[pilha->topo++] = tempP->alunos[tempP->topo];
        }
    }
}

void pop( Pilha* pilha, Aluno* aluno ) {
    if ( pilha->topo == 0 ) {
        return;
    }

    if ( !empty( pilha ) ) {
        pilha->topo--;
        *aluno = pilha->alunos[pilha->topo]; // Armazena temporariamente o pop na variavel aluno;
    }
}

bool push( Pilha* pilha, Aluno* item ) {
    if ( !full( pilha ) ) {
        pilha->alunos[pilha->topo] = *item;
        pilha->topo++;
        return true;
    }

    return false;
}

bool full( Pilha* pilha ) {
    return pilha->topo == pilha->limite;
}

bool empty( Pilha* pilha ) {
    return pilha->topo == pilha->base;
}

void reset( Pilha* pilha ) {
    pilha->base = 0;
    pilha->topo = 0;
    pilha->limite = MAX;
}
