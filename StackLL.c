#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* top = NULL;

void Push(int element){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	if (top == NULL){
		newNode->next = NULL;
	}	 
	newNode->next = top;
	top = newNode;
}

void Pop(){
	if (top == NULL){
		printf("Stack Underflow\n");
	}	 
	else{
		Node* temp;
		temp = top;
		printf("Deleted element is %d\n",temp->data);
		top = top->next;
		free(temp);
	}
}

void Peek(){
	if (top == NULL){
		printf("Stack Empty\n");
	}	 
	else{
		Node* temp = (Node*)malloc(sizeof(Node));
		temp = top;
		printf("Top element is %d\n",temp->data);
		free(temp);
	}
}

void Display(){
	if (top == NULL){
		printf("Stack Empty\n");
	}	
	else{
		Node* temp; 
		temp = top;
		printf("Elements in stack :");
		while (temp != NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		} 
	}
	printf("\n");
}

void main(){
	int ch,element;
	while(1){
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("5.Exit\n");
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter element\n");
				scanf("%d",&element);
				Push(element);
				break;
			case 2:
				Pop();	
				break;
			case 3:
				Peek();	
				break;	
			case 4:
				Display();
				break;
			case 5:
				return;
			default:
				printf("Invalid Choice\n");
				break;		
			}
		}
}		
