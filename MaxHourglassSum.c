#include <stdio.h>
#include <limits.h> // For INT_MIN

#define SIZE 6

int hourglassSum(int arr[SIZE][SIZE]);
int main(){
    int arr[SIZE][SIZE];
    for(int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            scanf("%d ",&arr[i][j]);
        }
    }
    printf("%d",hourglassSum(&arr[0][0]));
    return 0;
}    
int hourglassSum(int arr[SIZE][SIZE]){
    int max_hourglass_sum = INT_MIN;
    for (int i = 0; i < SIZE - 2; i++) {
        for (int j = 0; j < SIZE - 2; j++) {
            int hourglass_sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];            
            if (hourglass_sum > max_hourglass_sum) {
                max_hourglass_sum = hourglass_sum;
            }
        }
    }
    return max_hourglass_sum;
}    
