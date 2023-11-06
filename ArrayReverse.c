#include <stdio.h>

void reverseArray(int* arr){
    int s,temp;
    scanf("%d",&s);
    for(int j=0;j<s;j++){
        scanf("%d ",(arr+j));
    }
    for (int i=0,j =s-1;i<j;i++,j--){
         temp = arr[i];
         arr[i]=arr[j];
         arr[j]=temp;
    }
    for (int k=0;k<s;k++){
        printf("%d ",arr[k]);
    }
}
int main(){
    int array[1000]; 
    reverseArray(array);
    return 0;
}
    
