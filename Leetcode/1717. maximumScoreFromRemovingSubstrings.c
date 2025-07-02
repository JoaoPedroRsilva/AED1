#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximumGain(char* s, int x, int y); // Declaração da função

int main() {
    // Exemplo 1
    char input1[] = "cdbcbbaaabab";
    int x1 = 4;
    int y1 = 5;
    int result1 = maximumGain(input1, x1, y1);
    printf("Exemplo 1 -> Resultado: %d\n", result1); // Esperado: 19

    // Exemplo 2
    char input2[] = "aabbaaxybbaabb";
    int x2 = 5;
    int y2 = 4;
    int result2 = maximumGain(input2, x2, y2);
    printf("Exemplo 2 -> Resultado: %d\n", result2); // Esperado: 20

    return 0;
}

int maximumGain( char* s, int x, int y ) {    
    int result = 0;
    char *stack = ( char* ) malloc( sizeof( char ) * strlen( s ) );
    if( !stack ){
        printf("**** Malloc Error.\n");
        exit( 1 );
    }    

    int sLength = strlen( s );
    int top = 0;
    int k = 0;
    for( int i = 0; i < sLength; i++ ){
        stack[top] = s[i];
        top++;
        if( x <= y ){
        while( top >= 2 && stack[top - 1] == 'a' && stack[top - 2] == 'b' ){ // BA
            top -= 2;
            result += y;
        }
        } else{
        while( top >= 2 && stack[top - 1] == 'b' && stack[top - 2] == 'a'){ // AB
            top -= 2;
            result += x;
        }
        }
    }
    if( x <= y && top > 1){
    while( top > 0 ){
                top--;
                s[k] = stack[top]; 
                k++;
                while( k >= 2 && s[k - 1] == 'a' && s[k - 2] == 'b' ){
                    k -= 2;
                    result += x;
                }
            }
     } else if( x > y && top > 1){
     while( top > 0 ){
         top--;
         s[k] = stack[top]; 
         k++;
         while( k >= 2 && s[k - 1] == 'b' && s[k - 2] == 'a' ){
             k -= 2;
             result += y;
         }
     }
    }

    return result;
}