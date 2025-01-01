#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (!queue->rear) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(Queue *queue) {
    if (!queue->front) {
        printf("Queue Underflow\n");
        return -1;
    }

    Node *temp = queue->front;
    int dequeuedValue = temp->value;
    queue->front = queue->front->next;

    if (!queue->front) {
        queue->rear = NULL;
    }

    free(temp);
    return dequeuedValue;
}

int peekFront(Queue *queue) {
    return queue->front ? queue->front->value : -1;
}

int peekRear(Queue *queue) {
    return queue->rear ? queue->rear->value : -1;
}

int main() {
    Queue *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);

    printf("Peek Front: %d\n", peekFront(queue)); 
    printf("Peek Rear: %d\n", peekRear(queue));   
    printf("Dequeue: %d\n", dequeue(queue));      
    printf("Peek Front: %d\n", peekFront(queue)); 

    return 0;
}
