#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

void insertFront(int element){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	if (front == NULL){
		front = newNode;
		rear = newNode;
	}
	else{
		newNode->next = front;
		front = newNode;
	}
	
} 

void insertRear(int element){
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

void deleteFront(){
	if (front == NULL) printf("Queue underflow\n");
	else{
		Node* temp ;
		temp = front;
		printf("Deleted element is %d\n",temp->data); 
		front = front->next;
	} 
}

void deleteRear(){
	if (rear == NULL) printf("Queue underflow\n");
	else{
		Node* temp ;
		Node* prev ;
		Node* current =front;
		temp = rear;
		while(current->next != NULL){
			prev = current;
			current = current->next;
		}
		printf("Deleted element is %d\n",temp->data); 
		prev->next = NULL;
		rear = prev;
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
	int ch,val;
	while(1){
		printf("1.Insert Front\n");
		printf("2.Insert Rear\n");
		printf("3.Delete Front\n");
		printf("4.Delete Rear\n");
		printf("5.Display\n");
		printf("Enter choice :"); 
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter element :");
			 	scanf("%d",&val);
			 	insertFront(val);
			 	break;
			case 2:
				printf("Enter element :");
			 	scanf("%d",&val);
			 	insertRear(val);
			 	break; 	
			case 3:
				deleteFront();
				break;
			case 4:
				deleteRear();
				break;
			case 5:
				Display();
				break;
			default:
				printf("Invalid Choice");
				return;							 	
		}
	}
}	
		
