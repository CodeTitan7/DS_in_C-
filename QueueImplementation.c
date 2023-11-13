#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int element) {
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = element;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
    } else {
        printf("Deleted element is %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

void main() {
    enqueue(1);
    enqueue(4);
    enqueue(2);
    enqueue(6);
    display();
    
    dequeue();
    display();
}

