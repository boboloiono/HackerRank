#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
    int size = 2*n - 1;
    int arr[size][size];
    
  	// Complete the code to print the pattern.
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=j; k<=2*n-j-2; k++){
                arr[j][k] = n-j;
                arr[k][j] = n-j;
                arr[2*n-j-2][k] = n-j;
                arr[k][2*n-j-2] = n-j;
            }
        }
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}