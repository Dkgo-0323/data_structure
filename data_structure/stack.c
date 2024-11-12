#include<stdio.h>

char s[100];
int top,num_of_items = 0;

void push(char c);
char pop();
char TopItem();
int IsEmpty();

int main(){
    /* solve balanced paratheses problem*/
    char input;
    printf("please enter a paratheses sequence (press <enter> when done) :\n");
    scanf("%c",&input);
    while(input != '\n'){
        if(input == '(' || input == '[' ||input == '{'){
            push(input);
        }else if ( input == ')' ){
            if(IsEmpty() || TopItem() != '('){
                printf("Not a balanced paratheses sequence.\n");
                return 0;
            }else{
                pop();
            }
        }else if ( input == ']' ){
            if(IsEmpty() || TopItem() != '['){
                printf("Not a balanced paratheses sequence.\n");
                return 0;
            }else{
                pop();
            }
        }else if ( input == '}' ){
            if(IsEmpty() || TopItem() != '{'){
                printf("Not a balanced paratheses sequence.\n");
                return 0;
            }else{
                pop();
            }
        }
        scanf("%c",&input);
    }
    if(IsEmpty()){
        printf("It's balanced.\n");
    }else{
        printf("Not a balanced paratheses sequence.\n");
    }

    return 0;
}

void push(char c){
    /* 入栈 */
    if (num_of_items == 0){
        top = 0;
        s[0] = c;
    }else{
        s[++top] = c;
    }
    num_of_items ++;
}

char pop(){
    /* 出栈 */
    if ( IsEmpty() ){
        printf("The stack is empty!\n");
        return '\0';
    }else{
        num_of_items--;
        return s[top--];
    }
}

char TopItem(){
    /* 检查栈顶元素 */
    if ( IsEmpty() ){
        printf("The stack is empty!\n");
        return '\0';
    }else{
        return s[top];
    }
}

int IsEmpty(){
    /* 检查栈是否为空 */
    return num_of_items == 0;
}