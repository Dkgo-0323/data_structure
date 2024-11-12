#include<stdio.h>   /*printf,scanf,NULL*/
#include<stdlib.h>  /*malloc,free*/

struct node{
    int val;
    struct node *next;
};

typedef struct node Node;


Node *head = NULL;

void Insert(int k){

    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->val = k;



    if(head == NULL || head->val > k){  /*k is inserted at the beginning of the list.*/
        new_node->next = head;
        head = new_node;

    }else{  /*k is inserted somewhere inside the list*/
        Node *current = head;
        while(current->next != NULL && current->next->val < k){
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}


Node* Delete(int k){
    Node *current = head;

    while(current != NULL){
        
    }



}




void print(){
    if(head == NULL){
        printf("The list is empty!");
    }

    else{
        Node *current = head;
        while(current != NULL){
            printf("%d\n",current->val);
            current = current->next;
        }
    }
}

void freeList() {
    Node *current = head;
    Node *temp;
    while(current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL; // 清空链表头
}



int main(){
    Insert(15);
    Insert(12);
    Insert(1);
    Insert(3);
    Insert(2);
    Insert(60);

    print();
    freeList();

    return 0;
}