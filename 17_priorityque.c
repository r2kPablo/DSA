#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char name[100];
    int prio;
    struct node *next;
}customer;
customer *front=NULL;
customer *createNode(char name[],int prio){
    customer *newNode=(customer*)malloc(sizeof(customer));
    strcpy(newNode->name,name);
    newNode->prio=prio;
    newNode->next=NULL;
    return newNode;

}
void addCustomer(char name[],int prio){
    customer *newNode=createNode(name,prio);
    if(front==NULL||prio>front->prio){
        newNode->next=front;
        front=newNode;
        
    }else{
        customer *temp=front;
        while(temp->next!=NULL&&temp->next->prio>=prio){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;

    }
    printf("customer %s added with prio %d\n",name,prio);

}
void serve(){
    if(front==NULL){
        printf("no customers to serve\n");

    }else{
        customer *temp=front;
        printf("serving customer %s (prio: %d)\n",front->name,front->prio);
        front=front->next;
        free(temp);
    }
}
void display(){
    customer *temp=front;
    if(temp==NULL){
        printf("no customers");

    }else{
        printf("queue:\n");
        while(temp!=NULL){
            printf("%s (prio: %d)\n",temp->name,temp->prio);
            temp=temp->next;
        }
    }
}
int main(){
    while(1){
        printf("\nMENU\n1.Add customer\n2.serve customer\n3.display queue\n4.exit\n");
        printf("enter your choice: ");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:
                char name[100];
                int prio;
                printf("enter customer name: ");
                scanf("%s",name);
                printf("select which category customer belong to :\n1.ordinary\n2.defence personel\n3.senior citizen\4.differently abled\n");
                scanf("%d",&prio);
                addCustomer(name,prio);
                break;
            case 2:
                serve();   
                break;
            case 3:
                display();
                break;
            case 4:
                printf("exitin,...");
                exit(0);
            default:
                printf("invalid choice");
                break;             
        }
    }
}