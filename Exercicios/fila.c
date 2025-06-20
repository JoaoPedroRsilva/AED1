#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct QueueType{
    int product;
    struct QueueType *next;
}QueueType;

typedef struct{
    QueueType *start;
    QueueType *end;
}QueueTracker;

void dequeue( QueueTracker *tracker );
void queue( QueueTracker *tracker, int product );
QueueTracker *reset( QueueTracker *oldQueue );
bool empty( QueueTracker *tracker );
void print( QueueTracker *tracker );

int main() {
    QueueTracker *fila = reset( NULL );

    queue( fila, 100 );
    queue( fila, 200 );
    queue( fila, 300 );

    printf("Fila após enfileirar:\n");
    prin( fila );
    
    if (empty( fila )) {
        printf("Fila está vazia\n");
    } else {
        printf("Fila contém elementos\n");
    }
    
    dequeue( fila );
    printf("Removido um elemento da fila\n");
    print( fila ); 
    
    dequeue( fila );
    dequeue( fila );

    if ( empty( fila ) ) {
        printf("Fila está vazia agora\n");
    }

    print( fila );
    
    fila = reset( fila );
    printf("Fila foi resetada\n");

    print( fila );  

    free( fila ); 
    return 0;
}


void print( QueueTracker *tracker ){
    QueueType *runList = tracker->start;

    int i = 1;
    for( ; runList != NULL; runList = runList->next ){
        printf("\tLista[%d]: %d\n", i++, runList->product);
    }
}

void clear(QueueTracker *tracker) {
    while (!empty(tracker)) {
        dequeue(tracker);
    }
}

void dequeue( QueueTracker *tracker ){
    if( empty( tracker ) ) return;

    QueueType *temp = tracker->start;
    tracker->start = temp->next; 

    if (tracker->start == NULL) {
        tracker->end = NULL;
    }

    free( temp );
}

void queue( QueueTracker *tracker, int product ){
    QueueType *queue = malloc( sizeof( QueueType ) );
    if( !queue ){
        printf("\tErro no malloc\n");
        exit( 1 );
    }
    queue->product = product;
    queue->next = NULL;

    if( empty( tracker ) ){
        tracker->start = queue;
        tracker->end = queue;
    } else{
        tracker->end->next = queue;
        tracker->end = queue;
    }
}

QueueTracker *reset( QueueTracker *oldQueue ){
    if( oldQueue ){
        clear( oldQueue );
    }

    QueueTracker *tracker = malloc( sizeof( QueueTracker ) );
    if( !tracker ){
        printf("\tErro no malloc\n");
        exit( 1 );
    }
    tracker->start = NULL;
    tracker->end = NULL;

    return tracker;
}

bool empty( QueueTracker *tracker ){
    return tracker->start == NULL;
}
