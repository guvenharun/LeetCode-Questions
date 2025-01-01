 #include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct CircularSinglyLinkedList {
    Node *head;
} CircularSinglyLinkedList;

CircularSinglyLinkedList *createList() {
    CircularSinglyLinkedList *list = (CircularSinglyLinkedList *)malloc(sizeof(CircularSinglyLinkedList));
    list->head = NULL;
    return list;
}

void insertAtEnd(CircularSinglyLinkedList *list, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (!list->head) {
        list->head = newNode;
        newNode->next = newNode;
        return;
    }

    Node *temp = list->head;
    while (temp->next != list->head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = list->head;
}

void deleteNode(CircularSinglyLinkedList *list, int value) {
    if (!list->head) return;

    Node *curr = list->head, *prev = NULL;

    if (curr->value == value) {
        if (curr->next == list->head) {
            free(curr);
            list->head = NULL;
            return;
        }

        while (curr->next != list->head) {
            curr = curr->next;
        }

        curr->next = list->head->next;
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }

    prev = list->head;
    curr = list->head->next;

    while (curr != list->head && curr->value != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->value == value) {
        prev->next = curr->next;
        free(curr);
    }
}

void display(CircularSinglyLinkedList *list) {
    if (!list->head) return;

    Node *temp = list->head;
    do {
        printf("%d -> ", temp->value);
        temp = temp->next;
    } while (temp != list->head);
    printf("%d (head)\n", list->head->value);
}

int main() {
    CircularSinglyLinkedList *list = createList();

    insertAtEnd(list, 10);
    insertAtEnd(list, 20);
    insertAtEnd(list, 30);

    display(list); // Çıktı: 10 -> 20 -> 30 -> 10 (head)

    deleteNode(list, 20);
    display(list); // Çıktı: 10 -> 30 -> 10 (head)

    return 0;
}
