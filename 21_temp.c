#include <stdio.h>
#include <Stdlib.h>
#include<ctype.h>
#include <string.h>
#define max 100
char stack[max];
int top=-1;
void push(char c){
    stack[++top]=c;

}
char pop(){
    if (top==-1){
        return -1;
    }else{
        return stack[top--];
    }
}
int precedence(char c){
    if(c=='^'){
        return 3;
    }else if(c=='*'||c=='/'){
        return 2;
    }else if(c=='+'||c=='-'){
        return 1;
    }else{
        return 0;
    }

}
char infixToPostfix[](char infix[]){
    char postfix[max];
    int j=0;
    char c;
    for(int i=0;infix[i]!='\0';i++){
        c=infix[i];

        if(isalpha(c)||isdigit(c)){
            postfix[j++]=c;
        }else if(c=='('){
            push(c);
        }else if(c==')'){
            while(top!=-1&&stack[top]!='('){
                postfix[j++]=pop();
            }
            pop();
        }else{
            while(top!=-1&&precedence(stack[top])>=precedence(c)){
                postfix[j++]=pop();

            }
            push(c);
        }
       
    }
    while(top!=-1){
            postfix[j++]=pop();
        }
    postfix[j]='\0';
    return postfix;

}
struct node{
    char data;
    struct node *left,*right;

};
struct stack{
    struct node *data;
    struct node *next; 
};

struct stack *top2=NULL;

struct node *createNode(char value){
    struct node *newNode=(struct node*)malloc(sizeof(strcut node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;

}
void push2(struct node *treeNode){
    struct stack *temp=(struct stack*)malloc(sizeof(struct stack));
    temp->data=treeNode;
    temp->next=top2;
    top2=temp;

}
struct node *pop2(){
    if(top2==NULL){
        return NULL;
    }
    struct stack *temp=top2;
    struct node *res=top2->data;
    top2=top2->next;
    free(temp);
    return res;

}
struct node *createExpTree(char postfix[]){
    int i=0;
    char symbol;
    while((symbol=postfix[i])!='\0'){
        if(isdigit(symbol)){
            struct node *operandNode=createNode(symbol);
            push2(operandNode);

        }else{
            struct node *operatorNode=createNode(symbol);
            operatorNode->left=pop2();
            operatorNode->right=pop2();
            push2(operatorNode);
        }
        i++;
    }
    return pop();

}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    }

}


int main(){
    char infix[max];
    
    struct node *root=NULL;
    while(1){
        printf("\n MENU\n1.create expression tree\n2.inorder\n3.postorder\n4.preorder\n5.exit");
        printf("enter choice: ");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("enter the inifx expression: ");
                scanf("%s",infix);
                char postfix[max]=infixToPostfix(infix);
                root=createExpTree(postfix);
                break;
            case 2:
                inorder(root) ;
                break;   
        }
    }


}