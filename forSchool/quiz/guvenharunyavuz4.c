#include <stdio.h>
#define MAX 100

// Stack işlemleri
int stack[MAX];
int top = -1;

void pushStack(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        stack[++top] = value;
        printf("Stack Pushed: %d\n", value);
    }
}

int popStack() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        printf("Stack Popped: %d\n", stack[top]);
        return stack[top--];
    }
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Queue işlemleri
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue overflow!\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("Queue Enqueued: %d\n", value);
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow!\n");
        return -1;
    } else {
        printf("Queue Dequeued: %d\n", queue[front]);
        return queue[front++];
    }
}

void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Ana fonksiyon
int main() {
    // Stack işlemleri
    printf("** Stack **\n");
    pushStack(10);
    pushStack(20);
    pushStack(30);
    displayStack();
    popStack();
    displayStack();

    // Queue işlemleri
    printf("\n** Queue **\n");
    enqueue(100);
    enqueue(200);
    enqueue(300);
    displayQueue();
    dequeue();
    displayQueue();

    return 0;
}
