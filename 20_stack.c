#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
bool isFull(){
    return(top==MAX-1);
}
bool isEmpty(){
    return (top==-1);
}
void push(int item){
    if (isFull()){
        printf("stackoverflow");
        return;
    }else{
        stack[++top]=item;
    }

}
int pop(){
    if (isEmpty()){
        printf("stack underflow");
        return -1;
    }else{
        int x=stack[top];
        top--;
        return x;
    }

}
int peek(){
    if (isEmpty()){
        printf("stack is empty");
    }else{
        return stack[top];
    }
}
void display(){
    if (isEmpty()){
        printf("stack empty");
    }else{
        for (int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }   
}
int main(){
    while(1){
    printf("MENU\n");
    printf("1.PUSH\n2.POP\n3.PEEK\n4.dispaly\n5.EXIT\nenter your choice:");
    int ch;
    
    scanf("%d",&ch);

    
        switch(ch)
        {
        case 1: 
            int item;
            printf("enter the element to be pushed\n");
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            int x=pop();
            printf("%d is popped",x);
            break;
        case 3:
            int b=peek();
            printf("%d is the top element",b);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("exiting from program...");    
            exit(0);

        default:
            printf("invalid choice");
            break;
        }
    }
}