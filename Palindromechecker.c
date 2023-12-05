#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

struct DoublyLinkedList {
    struct Node* head;
    struct Node* tail;
};
struct DoublyLinkedList* head = NULL;
struct DoublyLinkedList* tail = NULL;

void createDLL(struct DoublyLinkedList* list, const char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = str[i];
        newNode->next = NULL;
        newNode->prev = NULL;
        if (list->head == NULL) {
            list->head = list->tail = newNode;
        } else {
            list->tail->next = newNode;
            newNode->prev = list->tail;
            list->tail = newNode;
        }
    }
}

bool isPalindrome(struct DoublyLinkedList* list) {
    struct Node* front = list->head;
    struct Node* back = list->tail;
    while (front != NULL && back != NULL) {
        if (front->data != back->data) {
            return false; 
        }
        front = front->next;
        back = back->prev;
    }
    return true; 
}

void displayDLL(struct DoublyLinkedList* list) {
    struct Node* current = list->head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeDLL(struct DoublyLinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

void main() {
    char a[20];
    printf("Enter word to be checked: ");
    scanf("%s",a);
    const char* input = a;
    struct DoublyLinkedList* List = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    createDLL(List, input);
    displayDLL(List);
    if (isPalindrome(List)) {
        printf("Given string is a palindrome.\n");
    } else {
        printf("Given string is not a palindrome.\n");
    }
    freeDLL(List);
}
