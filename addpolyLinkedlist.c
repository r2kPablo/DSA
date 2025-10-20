#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int expo;
    struct node *next;
};

struct node *createNode(int coeff ,int expo){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->expo=expo;
    newNode->next=NULL;
    return newNode;
}

struct node *insertNode(struct node *head,int coeff,int expo){
    struct node *newNode= createNode(coeff,expo);
    if(head==NULL){
        head=newNode;
    }else{
        struct node *temp=head;
        while (temp->next !=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    return head;
}
void display(struct node *head){
    struct node *temp=head;
    if(temp==NULL){
        printf("0\n");
        return;
    }
    while(temp!=NULL){
        printf("%dx^%d",temp->coeff,temp->expo);
        if(temp->next !=NULL){
            printf("+");
        }
        temp=temp->next;
        printf("\n");
    }
}
struct node *addPoly(struct node *p1,struct node *p2){
    struct node *result =NULL;

    while(p1!=NULL && p2!=NULL){
        if(p1->expo > p2->expo){
            result=insertNode(result,p1->coeff,p1->expo);
            p1=p1->next;
        }else if(p2->expo>p1->expo){
            result=insertNode(result,p2->coeff,p2->expo);
            p2=p2->next;
        }else{
            int sum=p1->coeff+p2->coeff;
            if(sum!=0){
                result=insertNode(result,sum,p1->expo);
            }
            p1=p1->next;
            p2=p2->next;
        }

    }
    while(p1!=NULL){
        result=insertNode(result,p1->coeff,p1->expo);
        p1=p1->next;
    }
    while(p2!=NULL){
        result=insertNode(result,p2->coeff,p2->expo);
        p2=p2->next;
    }
    return result;
}

int main(){
    struct node *p1=NULL,*p2 =NULL,*sum=NULL;
    int n,m,coeff,expo;

    printf("enter the nuo of terms in firsst polynomial:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enetr coefficent and exponent for terem %d: \n",i+1);
        scanf("%d %d",&coeff,&expo);
        p1=insertNode(p1,coeff,expo);
    }
    printf("enter the nuo of terms in second polynomial:\n");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        printf("enetr coefficent and exponent for terem %d: \n",i+1);
        scanf("%d %d",&coeff,&expo);
        p2=insertNode(p2,coeff,expo);
    }
    printf("\n");
    display(p1);
    display(p2);
    sum=addPoly(p1,p2);
    printf("sum of poly:\n");
    display(sum);
    return 0;

}