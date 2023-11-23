#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

void enQueue(int element){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->next = NULL;  
	if(rear == NULL){
		front = newNode;
		rear = newNode;
	}
	else{
		rear->next = newNode;
		rear = newNode;
	}	
}

void deQueue(){
	if (front == NULL) printf("Queue underflow\n");
	else{
		Node* temp ;
		temp = front;
		printf("Deleted element is %d\n",temp->data); 
		front = front->next;
	} 
}

void Display(){
	if (front == NULL) printf("Queue is empty\n");
	else{
		Node* temp;
		temp = front;
		printf("Elements of Queue are :"); 
		while(temp != NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}		
	}	
	printf("\n");
}

void main(){
	int ch,element;
	while(1){
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Dispalay\n");
		printf("4.Exit\n");
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter element\n");
				scanf("%d",&element);
				enQueue(element);
				break;
			case 2:
				deQueue();	
				break;
			case 3:
				Display();	
				break;	
			case 4:
				return;
			default:
				printf("Invalid Choice\n");
				break;		
			}
		}
}		 
