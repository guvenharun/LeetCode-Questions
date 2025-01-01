#include <stdio.h>
#include <stdlib.h>

struct LinkedList{
    int val;
    struct LinkedList* next;
};

struct Stack{
    struct LinkedList* top;
};  

struct Stack* createStack(){
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack* stack, int value){
    struct LinkedList* newNode = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    newNode->val = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack *stack){
    if (stack->top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct LinkedList *temp = stack->top;
    int popedValue = temp->val;
    stack->top = temp->next;
    free(temp);
    return popedValue;

}

int peek(struct Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->val;
}

int main() {
    struct Stack *stack = createStack();

    push(stack, 10);
    push(stack, 20);

    printf("Pop: %d\n", pop(stack));        
    printf("Peek: %d\n", peek(stack));      

    return 0;
}
