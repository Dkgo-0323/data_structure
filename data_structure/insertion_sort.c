#include<stdio.h>

int main(){
    int A[20] = {3,5,2,1,19,18,14,11,12,16,15,13,6,10,20,17,7,8,9,4};

    /*insertion sort*/
    int k,j,temp;
    for(k = 1; k < 20; k++ ){
        temp = A[k];
        for(j = k-1; j >= 0; j-- ){
            if( A[j] > temp ){
                A[j+1] = A[j];
            }else{
                A[j+1] = temp;
                break;
            }
        }
        if ( j < 0 ){
            A[0] = temp;
        }
    }
    /*print contents of A*/
    for(int i = 0; i<20; i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    return 0;
}