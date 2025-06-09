#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_NOME 50
#define TAM_EMAIL 50
#define TAM_PESSOA ( TAM_NOME + sizeof( int ) + TAM_EMAIL )
#define TAM_CABECAMEM ( sizeof( int ) * 4 + 50 + 50 ) // Espaço de memoria antes da primeira pessoa adicionada na lista

void AdicionarPessoa( void *pBuffer, int *numeroDePessoas, char *limpaBuffer );
void RemoverPessoa( void *inicioLista, int *numeroDePessoas, char *buscaEmail, int *loopControl, char *limpaBuffer, int *achou );
void BuscarPessoa( void *inicioLista, int *numeroDePessoas, char *buscaEmail, int *loopControl, char *limpaBuffer, int *achou );
void ListarTodos( void *inicioLista, int *numeroDePessoas, int *loopControl );

int main()
{
    char *pBuffer = ( char* ) malloc( TAM_CABECAMEM ); 
    if( !pBuffer ){
        printf("\t***** Erro no malloc *****\n");
        exit(1);
    }
    char *inicioLista = pBuffer + TAM_CABECAMEM;
    char *buscaEmail = pBuffer + sizeof( int ) * 4 + 50;
    char *limpaStdin = ( char* ) ( pBuffer + sizeof( int ) * 4 );
    int *escolha = ( int* )pBuffer;
    *escolha = 0;
    int *numeroDePessoas = ( int* )pBuffer + 1;
    *numeroDePessoas = 0;
    int *loopControl = ( int* )pBuffer + 2;
    *loopControl = 0;
    int *achou = ( int* )pBuffer + 3;
    *achou = 1;
    
    

    do{
        printf("\n\t\t===== MENU =====\n");
        printf("\t\t1 - Adicionar Pessoa\n");
        printf("\t\t2 - Listar Todos\n");
        printf("\t\t3 - Buscar Pessoa\n");
        printf("\t\t4 - Remover Pessoa\n");
        printf("\t\t5 - Sair\n\n");
        printf("Escolha uma opçao: ");
        scanf("%d", escolha);
        while( *escolha < 1 || *escolha > 5 ){
            printf("***** Opçao invalida. Tente novamente *****\n");
            printf("Escolha uma opçao: ");
            scanf("%d", escolha);
        }
        fgets( limpaStdin, 50, stdin );

        switch( *escolha ){
            case 1:
            pBuffer = AdicionarPessoa( pBuffer, numeroDePessoas, limpaStdin );
            break;

             case 2:
            ListarTodos( inicioLista, numeroDePessoas, loopControl );
            break;
           
            case 3:
            BuscarPessoa( inicioLista, numeroDePessoas, buscaEmail, loopControl, limpaStdin, achou );
            break;
            
            case 4:
            RemoverPessoa( inicioLista, numeroDePessoas, buscaEmail, loopControl, limpaStdin, achou );
            break;

            case 5:
            printf("\t===== Encerrando o programa =====\n");
            break; 

            default:
            printf("\t***** Entrada inválida. Tente novamente *****\n");
            
        }
    }while( *escolha != 5 );

    free(pBuffer);
    return 0;
}

void RemoverPessoa( void *inicioLista, int *numeroDePessoas, char *buscaEmail, int *loopControl, char *limpaBuffer, int *achou ){
    printf("Digite o e-mail da pessoa que esta buscando: ");
    fgets( buscaEmail, TAM_EMAIL, stdin );

    while( *loopControl < *numeroDePessoas ){
        char *lista = ( char* )inicioLista + *loopControl * TAM_PESSOA;
        char *listaProximo = ( char* )inicioLista + ( *loopControl + 1 ) * TAM_PESSOA;
        if(  strcmp( buscaEmail, lista + TAM_NOME + sizeof( int ) ) == 0 ){
            *achou = 0;
            if( *loopControl == *numeroDePessoas - 1 ){
                ( *numeroDePessoas )--;    
                break;
            }
            memmove( lista, listaProximo, ( *numeroDePessoas - ( *loopControl + 1 ) ) * TAM_PESSOA );
            ( *numeroDePessoas )--;
            break;
        }
        ( *loopControl )++;
    }
    *loopControl = 0;
    if( *achou == 1 ){
        printf("\t*****Nenhum usario com esse e-mail foi encontrado *****\n");
    }
    *achou = 1;
}

void AdicionarPessoa( void *bufferAdd, int *numeroDePessoas, char *limpaBuffer ){
    bufferAdd = realloc( bufferAdd, TAM_CABECAMEM + ( *numeroDePessoas + 1 ) * TAM_PESSOA );
    if( !bufferAdd ){
        printf("\t***** Erro no realloc *****\n");
        exit(1);
    }
    char *pessoaNova = bufferAdd + TAM_CABECAMEM + *numeroDePessoas * TAM_PESSOA;
    printf("Digite o nome: ");
    fgets( pessoaNova, TAM_NOME, stdin );
    printf("Digite a idade: ");
    scanf( "%d", ( char* )pessoaNova + TAM_NOME );
    fgets( limpaBuffer, 50, stdin );
    printf("Digite o e-mail: ");
    fgets( ( char* )pessoaNova + TAM_NOME + sizeof( int ), TAM_EMAIL, stdin );
    ( *numeroDePessoas )++;
}

void BuscarPessoa( void *inicioLista, int *numeroDePessoas, char *buscaEmail, int *loopControl, char *limpaBuffer, int *achou ){
    printf("Digite o e-mail da pessoa que esta buscando: ");
    fgets( buscaEmail, TAM_EMAIL, stdin );

    while( *loopControl < *numeroDePessoas ){
        char *lista = ( char* )inicioLista + *loopControl * TAM_PESSOA;
        if(  strcmp( buscaEmail, lista + TAM_NOME + sizeof( int ) ) == 0 ){
            *achou = 0;
            printf( "\tNome[%d]: %s", *loopControl, lista );
            printf( "\tIdade[%d]: %d\n", *loopControl, *( int* )(lista + TAM_NOME) );
            printf( "\tE-mail[%d]: %s\n", *loopControl, lista + TAM_NOME + sizeof( int ) );
        } 
        ( *loopControl )++;
    }
    *loopControl = 0;
    if( *achou == 1 ){
        printf("\t*****Nenhum usario com esse e-mail foi encontrado *****\n");
    }
    *achou = 1;
}

void ListarTodos( void *inicioLista, int *numeroDePessoas, int *loopControl ){
    while( *loopControl < *numeroDePessoas ){
        char *lista = ( char* )inicioLista + *loopControl * TAM_PESSOA;
        printf( "\tNome[%d]: %s", *loopControl, lista );
        printf( "\tIdade[%d]: %d\n", *loopControl, *( int* )(lista + TAM_NOME) );
        printf( "\tE-mail[%d]: %s\n", *loopControl, lista + TAM_NOME + sizeof( int ) );
        ( *loopControl )++;
    }
    *loopControl = 0;
}