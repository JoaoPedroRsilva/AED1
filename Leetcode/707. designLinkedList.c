


typedef struct MyLinkedList {
    int val;
    struct MyLinkedList *next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *head;
    head = ( MyLinkedList* ) malloc( sizeof( MyLinkedList ) );
    if( !head ){
        printf("Malloc ERROR.\n");
        exit( 1 );
    }
    head->val = 0;
    head->next = NULL;
    return head;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList *current = obj->next;
    int i = 0;
    while( current != NULL ){
        if( i == index ) return current->val;
        current = current->next;
        i++;
    }
    
    printf("Invalid index.\n");
    return -1;
    
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *newNode;
    newNode = ( MyLinkedList* ) malloc( sizeof( MyLinkedList ) );
    if( !newNode ){
        printf("Malloc ERROR.\n");
        exit( 1 );
    }
    newNode->val = val;
    newNode->next = obj->next;
    obj->next = newNode;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *newNode;
    newNode = ( MyLinkedList* ) malloc( sizeof( MyLinkedList ) );
    if( !newNode ){
        printf("Malloc ERROR.\n");
        exit( 1 );
    }
    newNode->val = val;
    newNode->next = NULL;
    MyLinkedList* temp = obj;
    for( ; temp->next != NULL; temp = temp->next ){
    }
    temp->next = newNode;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList *previous = obj;
    MyLinkedList *next = obj;

    int i = 0;
    while( i < index && previous->next != NULL ){
        previous = previous->next;
        i++;
    }
    if( i == index ){
        MyLinkedList *newNode;
        newNode = ( MyLinkedList* ) malloc( sizeof( MyLinkedList ) );
        if( !newNode ){
           printf("Malloc ERROR.\n");
            exit( 1 );
        }
        newNode->val = val;
        newNode->next = previous->next;
        previous->next = newNode;
    }

}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList *current = obj;
    MyLinkedList *temp = NULL;
    int i = 0;
    while( i < index && current->next != NULL ){
        current = current->next;
        i++;
    }
    if( current->next != NULL && current != NULL ){
        temp = current->next;
        current->next = temp->next;
        free( temp );
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *temp = NULL;
    while( obj != NULL ){
        temp = obj->next;
        free( obj );
        obj = temp;
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/