#include <stdio.h>
#include <stdlib.h>

struct Node *head = NULL;
 
struct Node {
    int data;
    struct Node *next;
};

void insert(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        head->next = head; 
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node *current = head, *prev = NULL;
    while (current->data != key) {
        prev = current;
        current = current->next;
        if (current == head) {
            printf("Node with key %d not found in the list.\n", key);
            return;
        }
    }
    if (current->next == head && prev == NULL) {
        free(current);
        return ;
    }
    if (current == head) {
        prev = head;
        while (prev->next != head) {
            prev = prev->next;
        }
        head = current->next;
        prev->next = head;
    } else {
        prev->next = current->next;
    }
    free(current);
}

void display() {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void freeList() {
    if (head == NULL) {
        return;
    }
    struct Node *current = head, *temp;
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
}

void main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    printf("Circular Linked List after insertion: ");
    display();
    deleteNode(3);
    deleteNode(1);
    printf("Circular Linked List after deletion: ");
    display();
    freeList();
}
