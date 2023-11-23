#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int pow;
	int coef;
	struct Node* next;
}Node;

void readPoly(Node* poly){
	int pow,coef,terms;
	Node* temp = (Node*)malloc(sizeof(Node));
	temp = poly;
	printf("Enter number of terms :");
	scanf("%d",&terms);
	for(int i = 0;i<terms;i++){
		printf("Enter coefficient and exponent of the term :");	
		scanf("%d %d",&coef,&pow);
		temp->coef = coef;
		temp->pow = pow;
		temp->next = NULL;
	}	
} 

void Display(Node* poly){
	Node* temp;
	temp = poly;
	while(temp != NULL){
		printf("%dx^%d ",temp->coef,temp->pow);
		if(temp!=NULL){
			printf("+");
		}
		temp = temp->next;
	}
	printf("\n");
}

void main(){
	Node* poly1;
	Node* poly2;
	//Node* result;
	readPoly(poly1);
	//readPoly(&poly2);
	Display(poly1);
	//Display(poly2);
	//addPoly(&result,poly1,poly2);
	//Display(result);
} 
