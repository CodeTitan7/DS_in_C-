#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void encqueue(int element) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = element;
}

int decqueue() {
    int element;
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    element = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    return element;
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    } while (i != (rear + 1) % MAX);

    printf("\n");
}

int main() {
    encqueue(1);
    encqueue(4);
    encqueue(2);
    encqueue(6);
    display();
    decqueue();
    display();
    encqueue(8);
    encqueue(7);
    display();
    encqueue(9);
    display();
    decqueue();
    decqueue();
    decqueue();
    decqueue();
    decqueue();
    display();
    encqueue(144);
    display();
}
