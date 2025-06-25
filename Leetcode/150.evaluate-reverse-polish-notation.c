/*
 * @lc app=leetcode id=150 lang=c
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int operation( int *stack, int *top, char operand ){
    int operator_1 = 0;
    int operator_2 = 0;
    operator_1 = stack[--( *top )];
    operator_2 = stack[--( *top )];
    if( operand == '+'){
        return operator_1 + operator_2;
    } else if( operand == '-'){
        return operator_2 - operator_1;
    } else if( operand == '*'){
        return operator_1 * operator_2;
    } else if( operand == '/'){
        return operator_2 / operator_1;
    } 
    return 0;
}

int evalRPN(char** tokens, int tokensSize) {
    int *stack;
    stack = ( int* )malloc( sizeof( int ) * tokensSize );
    if( !stack ){
        printf("Memory allocation error.\n");
        exit( 1 );
    }
    int top = 0;

    int j = 0;
    int result = 0;
    for( int i = 0; i < tokensSize; i++ ){
        if( ( tokens[i][0] == '+' || tokens[i][0] == '-' || 
    tokens[i][0] == '*' || tokens[i][0] == '/' ) && tokens[i][1] == '\0' ){
            result = operation( stack, &top, tokens[i][0] );
            stack[( top )++] = result;
        
        } else{
        stack[( top )++] = atoi( tokens[i] );
        }
    }

    
    return stack[0];
}




// @lc code=end

