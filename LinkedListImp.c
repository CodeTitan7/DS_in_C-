#include<stdio.h>
#include<stdlib.h>

typedef struct List{
	char data;
	struct List* next; 
}List;

void createLL(List *head,int n){
	List *current;
	current = head;
	char datainsert;
	printf("Enter data to inserted to the node\n");
	for(int i = 1;i<=n+5;i++){
		List* newNode ;
		newNode = (List *)malloc(sizeof(List));
		scanf("%c",&datainsert);
		newNode->data = datainsert; 
		if (current == NULL) {
			current = newNode;
		}
		current->next = newNode;
		current = newNode;
		current->next=NULL;
		}		
}

void insertAdata(List *head,char targetData,char newData){
	List *current;
	current = head;
	while(current != NULL && current->data != targetData){
		current = current->next;
	}
	if (current == NULL) return;
	List* newNode ;
	newNode = (List *)malloc(sizeof(List));	
	newNode->data = newData; 
	newNode->next = current->next;
	current->next = newNode;
}

void insertBdata(List *head,char targetData,char newData){
	List *current;
	current = head;
	List *previous = NULL;
	while(current != NULL && current->data != targetData){
		previous = current;
		current = current->next;
	}
	if (current == NULL) return;
	List* newNode ;
	newNode = (List *)malloc(sizeof(List));	
	newNode->data = newData; 
	if (previous == NULL){newNode->next = head;}
	else {newNode->next = current;
	}
}

void insertposition(List *head,int position,char newData){
	int count=0;
	if (position < 1){ return;}
	List* newNode ;
	newNode = (List *)malloc(sizeof(List));	
	newNode->data = newData; 
	if (position == -1){newNode->next = head;}
	List *current;
	current = head;
	while(current!= NULL){
		count++;
		if (count == position){
			newNode->next=current->next;
			current->next = newNode;
			break;
		}
		current = current->next;
	}	 
	 
}

void display(List *head){
	List *current;
	current = head;
	while(current->next != NULL){
		current = current->next;
		printf("%c",current->data);
	}
}

void main(){
	int n;
	char target,new,pos;
	List* head; 
	head->next = NULL;
	printf("Enter number of elemnts to be inserted into LinkedList : ");
	scanf("%d",&n);         
	createLL(head,n);
	
	printf("Enter target data: ");
	scanf("%c\n",&target);
	printf("Enter new data to be added: ");
	scanf("%c\n",&new); 
	insertAdata(head,target,new);		
	
	display(head);
	
	/*printf("Enter target data: ");
	scanf("%c\n",&target);
	printf("Enter new data to be added: ");
	scanf("%c\n",&new); 
	insertBdata(head,target,new);		
	
	printf("Enter positon where new node needed to be inserted :");
	scanf("%d\n",&pos);
	printf("Enter new data to be added: ");
	scanf("%c\n",&new); 
	insertposition(head,pos,new);*/
	
	
}
