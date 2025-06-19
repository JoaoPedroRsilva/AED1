#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_MEMHEAD ( sizeof( int ) * 5 + 50 + 50 ) // Espaço de memoria antes da primeira pessoa adicionada na lista

void AdicionarPessoa( void **pBuffer );
void ListarTodos( void **pBuffer );
void BuscarPessoa( void **pBuffer );
void RemoverPessoa( void ** pBuffer );


int main()
{
    void *pBuffer = malloc( TAM_MEMHEAD ); 
    if( !pBuffer ){
        printf("\t***** Erro no malloc *****\n");
        exit(1);
    }    
    memset( pBuffer, 0, TAM_MEMHEAD );
    int *escolha = ( int* )pBuffer;
    *escolha = 0;
   
    

    do{
        printf("\n\t\t===== MENU =====\n");
        printf("\t\t1 - Adicionar Pessoa\n");
        printf("\t\t2 - Listar Todos\n");
        printf("\t\t3 - Buscar Pessoa\n");
        printf("\t\t4 - Remover Pessoa\n");
        printf("\t\t5 - Sair\n\n");
        printf("Escolha uma opçao: ");
        scanf("%d", escolha);
        getchar();

        while( *escolha < 1 || *escolha > 5 ){
            printf("***** Opçao invalida. Tente novamente *****\n");
            printf("Escolha uma opçao: ");
            scanf("%d", escolha);
            getchar();
        }

        switch( *escolha ){
            case 1:
            AdicionarPessoa( &pBuffer );
            break;

            case 2:
            ListarTodos( &pBuffer );
            break;
           
            case 3:
            BuscarPessoa( &pBuffer );
            break;
             
            case 4:
            RemoverPessoa( &pBuffer );
            break;
  
            case 5:
            printf("\t===== Encerrando o programa =====\n");
            break; 

            default:
            printf("\t***** Entrada inválida. Tente novamente *****\n"); 
        }
        escolha = ( int* )pBuffer;
    }while( *escolha != 5 );

    free(pBuffer);
    return 0;
}

void AdicionarPessoa( void **pBuffer ){
    char *stringBufferNome = ( char* )*pBuffer + sizeof( int ) * 5; // Mudar o numero de sizeof( int ) sempre que nova variavel
    char *stringBufferEmail = ( char* )*pBuffer + sizeof( int ) * 5 + 50;
    int *quantPessoas = ( int* )*pBuffer + 1;
    int *tamPessoa = ( int* )*pBuffer + 2;
    int *tamTodos = ( int* )*pBuffer + 3;
    
    printf("Digite o nome: ");
    fgets( stringBufferNome, 50, stdin );
    stringBufferNome[strcspn(stringBufferNome, "\n")] = '\0';
    printf("Digite o e-mail: ");
    fgets( stringBufferEmail, 50, stdin );
    stringBufferEmail[strcspn(stringBufferEmail, "\n")] = '\0';
    *tamPessoa = strlen( stringBufferNome ) + strlen( stringBufferEmail ) + sizeof( int ) + 2;
    

    char *temp;
    temp = realloc( *pBuffer, TAM_MEMHEAD + *tamTodos + *tamPessoa );
    if( !temp ){
        printf( "\t\t***** Erro no Realloc *****\n" );
        exit( 1 );
    }
    *pBuffer = temp;
    

    // === Atualizando os Ponteiros ===
    stringBufferNome = ( char* )*pBuffer + sizeof( int ) * 5; // Mudar o numero de sizeof( int ) sempre que nova variavel
    stringBufferEmail = ( char* )*pBuffer + sizeof( int ) * 5 + 50;
    quantPessoas = ( int* )*pBuffer + 1;
    tamPessoa = ( int* )*pBuffer + 2;
    tamTodos = ( int* )*pBuffer + 3;

    char *inicioLista = ( char* )*pBuffer + TAM_MEMHEAD + *tamTodos;
    memcpy( inicioLista, stringBufferNome, strlen( stringBufferNome ) + 1 );
    printf( "Digite sua idade: " );
    scanf( "%d", ( int* )( ( char* )inicioLista + sizeof( char ) * ( strlen( stringBufferNome ) + 1 ) ) );
    getchar();
    memcpy( ( char* )inicioLista + strlen( stringBufferNome ) + 1 + sizeof( int ), stringBufferEmail, strlen( stringBufferEmail ) + 1 );

    *quantPessoas++;
    *tamTodos += *tamPessoa;
}

void ListarTodos( void **pBuffer ){
    char *percorreLista = ( char* )*pBuffer + TAM_MEMHEAD;
    int *tamTodos = ( int* )*pBuffer + 3;
    char *fimLista = ( char* )*pBuffer + TAM_MEMHEAD + *tamTodos;

    while( percorreLista < fimLista ){
        printf("\tNome: %s\n", percorreLista );
        percorreLista += strlen( percorreLista ) + 1;
        printf("\tIdade: %d\n", *( int* )percorreLista );
        percorreLista += sizeof( int );
        printf("\tE-mail: %s\n\n", percorreLista);
        percorreLista += strlen( percorreLista ) + 1;
    }
}

void BuscarPessoa( void **pBuffer ){
    char *percorreLista = ( char* )*pBuffer + TAM_MEMHEAD;
    char *pessoaBusca = ( char* )*pBuffer + sizeof( int ) * 4;
    int *tamTodos = ( int* )*pBuffer + 3;
    char *fimLista = ( char* )*pBuffer + TAM_MEMHEAD + *tamTodos;
    printf("Digite o nome que deseja buscar: ");
    fgets( pessoaBusca, 50, stdin );
    pessoaBusca[strcspn(pessoaBusca, "\n")] = '\0';

    while( percorreLista < fimLista ){
            if( strcmp( percorreLista, pessoaBusca ) == 0 ){
                printf("\n\tNome: %s\n", percorreLista );
                percorreLista += strlen( percorreLista ) + 1;
                printf("\tIdade: %d\n", *( int* )percorreLista );
                percorreLista += sizeof( int );
                printf("\tE-mail: %s\n\n", percorreLista);
                percorreLista += strlen( percorreLista ) + 1;
                return;
            }
        percorreLista += strlen( percorreLista ) + 1;
        percorreLista += sizeof( int );
        percorreLista += strlen( percorreLista ) + 1;
    }
    printf("\t*** Pessoa nao encontrada ***\n");
}

void RemoverPessoa( void **pBuffer ){
    char *percorreLista = ( char* )*pBuffer + TAM_MEMHEAD;
    char *pessoaRemove = ( char* )*pBuffer + sizeof( int ) * 4;
    int *quantPessoas = ( int* )*pBuffer + 1;
    int *numPessoaLista = ( int* )*pBuffer + 4;
    *numPessoaLista = 0;
    int *tamTodos = ( int* )*pBuffer + 3;
    char *fimLista = ( char* )*pBuffer + TAM_MEMHEAD + *tamTodos;

    printf("Digite o nome de quem deseja remover: ");
    fgets( pessoaRemove, 50, stdin );
    pessoaRemove[strcspn(pessoaRemove, "\n")] = '\0';

    while( percorreLista < fimLista ){
         if( strcmp( percorreLista, pessoaRemove ) == 0){
            printf("\t*** Pessoa Removida ***\n");
            if( *numPessoaLista == *quantPessoas - 1 ){
                memset( percorreLista, 0, fimLista - percorreLista );
                *tamTodos -= ( fimLista - percorreLista );
                *quantPessoas--;
                return;
            }
            char *destinoMem = percorreLista;
            percorreLista += strlen( percorreLista ) + 1;
            percorreLista += sizeof( int ); 
            percorreLista += strlen( percorreLista ) + 1;
            memmove( destinoMem, percorreLista, fimLista - percorreLista );
            *tamTodos -= ( percorreLista - destinoMem );
            *quantPessoas--;
            return;
        } else {
            percorreLista += strlen( percorreLista ) + 1;
            percorreLista += sizeof( int );
            percorreLista += strlen( percorreLista ) + 1;
            *numPessoaLista++;
        }
    }
    printf("\t*** Pessoa nao encontrada ***\n");
}




   
