#include <stdio.h>
#include <stdlib.h>

struct LinkedList{
    int val;
    struct LinkedList* prev;
    struct LinkedList* next;
};

struct LinkedList* createList(int value){
    struct LinkedList* newNode = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    newNode->val = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void addAtHead(struct LinkedList** list ,int val)
{
   struct LinkedList* newNode = createList(val);
   newNode->next = *list;

   if(*list != NULL){
        (*list)->prev = newNode;
   }

   *list = newNode;

}

void addAtTail(struct LinkedList** list ,int val)
{
    struct LinkedList* newNode = createList(val);
    struct LinkedList* temp = *list;

    if (*list == NULL) {
        newNode->prev = NULL;
        *list = newNode;
        return;
    }

    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

}

void deleteNode(struct LinkedList** list, int value){
    struct LinkedList* temp = *list;
    if(*list ==  NULL){
        return;
    }

    while(temp != NULL && temp->val != value){
        temp = temp->next;
    }
    if(temp == NULL) return;

    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    }else{
        *list = temp->next;
    }
    if(temp-> next != NULL){
        temp->next->prev = temp->prev;
    }
    free(temp);

}

void printList(struct LinkedList* list) {
    struct LinkedList* temp = list;
    while (temp) {
        printf("%d", temp->val);
        if (temp->next) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct LinkedList* list) {
    struct LinkedList* temp;
    while (list) {
        temp = list;
        list = list->next;
        free(temp);
    }
}

int main() {
    struct LinkedList* head = NULL;

    addAtHead(&head, 3);
    addAtHead(&head, 2);
    addAtHead(&head, 1);

    printf("Liste: ");
    printList(head); 

    deleteNode(&head, 2);

    printf("Liste: ");
    printList(head); 
    
    freeList(head);

    return 0;
}
