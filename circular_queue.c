#include <stdio.h>

int Q[100];
int head,tail,num_of_ele;

void Enqueue( int x );
void Dequeue( int x );


int main(){
    /* solve Josephus problem */
    int n,answer;
    printf("Enter a number (1--99):\n");
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        Enqueue(i);
    }
    for(int i = 0; i < n-1; i++){
        Enqueue(Q[head]);
        Dequeue(2);
    }
    answer = Q[head];
    printf("The vallue of J(%d) is %d.\n",n,answer);

    return 0;
}

void Enqueue( int x ){
    if (num_of_ele == 0){
        head = tail = 0;
        Q[0] = x;
    }else{
        tail = (tail + 1) % 100; // circular
        Q[tail] = x;
    }
    num_of_ele ++;
}

void Dequeue( int x ){
    /*参数x代表Dequeue的次数*/
    if (num_of_ele == 0){
        printf("There is no element in the queue.\n");
    }else{
        for(int i=0; i<x; i++)
        {
            head = (head + 1) % 100;
            num_of_ele --;
        }
    }
}

