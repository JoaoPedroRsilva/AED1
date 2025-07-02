#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int *item;
    int rear;
    int front;
    int size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
bool myCircularQueueDeQueue(MyCircularQueue* obj);
int myCircularQueueFront(MyCircularQueue* obj);
int myCircularQueueRear(MyCircularQueue* obj);
void myCircularQueueFree(MyCircularQueue* obj);

int main() {
    MyCircularQueue* myCircularQueue = myCircularQueueCreate(3);

    printf("%s\n", myCircularQueueEnQueue(myCircularQueue, 1) ? "true" : "false");
    printf("%s\n", myCircularQueueEnQueue(myCircularQueue, 2) ? "true" : "false");
    printf("%s\n", myCircularQueueEnQueue(myCircularQueue, 3) ? "true" : "false");
    printf("%s\n", myCircularQueueEnQueue(myCircularQueue, 4) ? "true" : "false");
    printf("%d\n", myCircularQueueRear(myCircularQueue));
    printf("%s\n", myCircularQueueIsFull(myCircularQueue) ? "true" : "false");
    printf("%s\n", myCircularQueueDeQueue(myCircularQueue) ? "true" : "false");
    printf("%s\n", myCircularQueueEnQueue(myCircularQueue, 4) ? "true" : "false");
    printf("%d\n", myCircularQueueRear(myCircularQueue));

    myCircularQueueFree(myCircularQueue);

    return 0;
}


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *queue = ( MyCircularQueue* ) malloc(sizeof( MyCircularQueue ) );
    if( !queue ){
        printf("Malloc error.\n");
        exit( 1 );
    }
    queue->rear = 0;
    queue->front = 0;
    queue->size = k + 1;
    queue->item = ( int* ) malloc( sizeof( int ) * ( k + 1 ) );
    if( !queue->item ){
        printf("Malloc error.\n");
        exit( 1 );
    }
    memset( queue->item, 0, sizeof( int ) * ( k + 1 ) );

    return queue;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return ( ( obj->rear + 1 ) % obj->size == obj->front );
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if( myCircularQueueIsFull( obj ) ){
        return false;
    } else 
    obj->item[obj->rear] = value;
    obj->rear = ( obj->rear + 1 ) % obj->size;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if( myCircularQueueIsEmpty( obj ) ){
        return false;
    }
    obj->front = ( obj->front + 1 ) % obj->size;
    return true;

}

int myCircularQueueFront(MyCircularQueue* obj) {
    if( myCircularQueueIsEmpty( obj ) ){
        printf("Queue is empty. There is no front.\n");
        return -1;
    } else 
    return obj->item[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if( myCircularQueueIsEmpty( obj ) ){
        printf("Queue is empty. There is no front.\n");
        return -1;
    } else {
    int index = ( obj->rear - 1 + obj->size ) % obj->size;
    return obj->item[index]; 
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free( obj->item );
    free( obj );
}
