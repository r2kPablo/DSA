#include<stdio.h>
#include <stdlib.h>
struct node {
    int coeff;
    int exp;
    struct node *next;
};
struct node *createNode(int coeff,int exp){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->coeff=coeff;
    newNode->exp=exp;
    newNode->next=NULL;
    return newNode;
}
struct node *insertNode(struct node *head,int coeff,int exp){
    struct node *newNode=createNode(coeff,exp);
    if(head==NULL){
        head=newNode;
    }else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    return head;
}
void display(struct node *head){
    struct node *temp=head;
    if(temp==NULL){
        printf("it is empty");
        return;
    }
    while(temp!=NULL){
        printf("%dx^%d ",temp->coeff,temp->exp);
        if(temp->next!=NULL){
            printf("+");
        }
        temp=temp->next;
    }

}
struct node *addPoly(struct node *p1,struct node *p2){
    struct node *p3=NULL;
    while(p1!=NULL && p2!=NULL){
        if(p1->exp>p2->exp){
            p3=insertNode(p3,p1->coeff,p1->exp);
            p1=p1->next;
        }else if(p2->exp>p1->exp){
            p3=insertNode(p3,p2->coeff,p2->exp);
            p2=p2->next;
        }else{
            int sum=p1->coeff+p2->coeff;
            if (sum!=0){
                p3=insertNode(p3,sum,p1->exp);
                p1=p1->next;
                p2=p2->next;
            }
        }
    }
    while(p1!=NULL){
        p3=insertNode(p3,p1->coeff,p1->exp);
        p1=p1->next;
    }
    while(p2!=NULL){
        p3=insertNode(p3,p2->coeff,p2->exp);
        p2=p2->next;
    }
    return p3;
}
struct node *multiply(struct node *p1,struct node *p2){
    struct node *p4=NULL;
    struct node *ptr1=p1;
    struct node *ptr2=p2;

    while(ptr1!=NULL){
        ptr2=p2;
        while(ptr2!=NULL){
            int coeff=ptr1->coeff*ptr2->coeff;
            int exp=ptr1->exp+ptr2->exp;
            p4=insertNode(p4,coeff,exp);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }

    return p4;
}


int main(){
    struct node *p1=NULL,*p2=NULL,*p3=NULL,*p4=NULL;
    int n,m,coeff,exp;
    printf("enter the no of terms in first polynomial: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the values of term %d (coefficient exponent)",i+1);
        scanf("%d %d",&coeff,&exp);
        p1=insertNode(p1,coeff,exp);
    }
    printf("enter the no of terms in second polynomial:\n");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        printf("enyer the values of term %d (coefficeint exponent)",i+1);
        scanf("%d %d",&coeff,&exp);
        p2=insertNode(p2,coeff,exp);
    }
    printf("frist polynomial : ");
    display(p1);
    printf("\n");
    printf("second polynomial: ");
    printf("\n");
    p3=addPoly(p1,p2);
    printf("the sum of polynomial is : ");
    display(p3);
    printf("\n");
    printf("the multiplication: ");
    p4=multiply(p1,p2);
    display(p4);
    return 0;

}