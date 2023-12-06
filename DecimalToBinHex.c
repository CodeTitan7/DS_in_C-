#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stackb[MAX];
int stackh[MAX];
int topb = -1;
int toph = -1;

void pushb(int el){
    stackb[++topb]=el;
}
void pushh(int el){
    stackh[++toph]=el;
}
/*
int pop(){
    if (top == -1) exit;
    return stack[top--];
}*/

void displayb(){
    if (topb==-1) exit;
    int temp = topb;
    while (temp!=-1) printf("%d",stackb[temp--]);
    printf("\n");
}
void displayh(){
    if (toph==-1) exit;
    int temp = toph;
    while (temp!=-1) {
        if (stackh[temp] < 10) printf("%d",stackh[temp--]);
        else {
            printf("%c",(stackh[temp--]+55));
        }
    }    
    printf("\n");
}

void decToBin(int dec){
    int rem;
    if (dec == 0) printf("%d",0);
    while(dec){
        rem = dec%2;
        dec  = dec/2; 
        pushb(rem);
    }
    displayb(); 
}

void decToHex(int dec){
    int rem;
    int ch;
    if (dec == 0) printf("%d",0);
    while(dec){
        rem = dec%16;
        dec  = dec/16; 
        pushh(rem);
    }
    displayh(); 
}

void main()
{
    int dec;
    printf("Enter decimal:\n");
    scanf("%d",&dec);
    printf("Binary of %d is ",dec);
    decToBin(dec);
    printf("Hexadecimal of %d is ",dec);
    decToHex(dec);
}
