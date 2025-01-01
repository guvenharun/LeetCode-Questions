#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int value;
    struct Node* next;
} Node;


Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}


void insert(Node** head, int value) {
    
    Node* newNode = createNode(value);

    if (*head == NULL || (*head)->value > value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL && current->next->value <= value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return;
}



int main() {
    Node* head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    insert(&head, 25);
    insert(&head, 35);
    insert(&head, 55);
    insert(&head, 5);
    
    
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }


    return 0;
}