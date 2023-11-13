#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1; // Return an invalid value or handle the error appropriately
    } else {
        return stack[top--];
    }
}

void push(int element) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        // Create a temporary stack to hold elements
        int tempStack[MAX_SIZE];
        int tempTop = -1;
        
        // Move elements larger than the one being pushed to the temporary stack
        while (top != -1 && element < stack[top]) {
            tempStack[++tempTop] = pop();
        }
        
        // Add the new element to the original stack
        stack[++top] = element;
        
        // Push the larger elements back onto the original stack
        while (tempTop != -1) {
            stack[++top] = tempStack[tempTop--];
        }
    }
}

int main() {
    push(1);
    push(3);
    push(2);
    push(5);
    push(1);
    
    while (top != -1) {
        printf("%d ", pop());
    }
    return 0;
}


