#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    int data = stack->top->data;
    stack->top=stack->top->next;
    return data;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->front == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue underflow.\n");
        exit(EXIT_FAILURE);
    }
    int data = queue->front->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}

void reverseQueue(struct Queue* queue) {
    struct Stack* stack = createStack();

    while (queue->front != NULL) {
        push(stack, dequeue(queue));
    }

    while (stack->top != NULL) {
        enqueue(queue, pop(stack));
    }

    free(stack);
}

void displayQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeQueue(struct Queue* queue) {
    while (queue->front != NULL) {
        dequeue(queue);
    }
    free(queue);
}

void main() {
    struct Queue* myQueue = createQueue();
    enqueue(myQueue, 1);
    enqueue(myQueue, 2);
    enqueue(myQueue, 3);
    enqueue(myQueue, 4);
    enqueue(myQueue, 5);
    printf("Original queue: ");
    displayQueue(myQueue);
    reverseQueue(myQueue);
    printf("Reversed queue: ");
    displayQueue(myQueue);
    freeQueue(myQueue);
}
