#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

struct node *head=NULL;
void insertEnd(int value){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->next=NULL;

    if (head==NULL){
        head=newNode;

    }else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }

}
void insertBegin(int value){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;

}

void insertPos(int value,int pos){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->next=NULL;

    if (pos==1){
        newNode->next=head;
        head=newNode;
        return;
    }
    node *temp=head;
    for(int i=1;i<pos-1;i++){
        if (temp==NULL){
            printf("invalid position");
            return;
        }
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;

}
void deleteEnd(){
    if (head==NULL){
        printf("list is empty");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    
}
void deleteBegin(){
    if (head==NULL){
        printf("list is empty");
        return;

    }
    node *temp=head;
    head=temp->next;
    free(temp);

}
void deletePos(int pos){
    if(head==NULL){
        printf("list is empty");
        return;
    }
    if (pos==1){
        node *temp=head;
        head=head->next;
        free(temp);
        return;
    }
    node *temp=head;
    for(int i=1;i<pos-1;i++){
        if(temp==NULL){
            printf("invalid postition");
            return;
        }
        temp=temp->next;
    }
    if(temp->next==NULL){
        printf("invalid postion");
        return;
    }
    node *deleteNode=temp->next;
    temp->next=deleteNode->next;
    free(deleteNode);
    

}
void display(){
    if(head==NULL){
        printf("list is empty");
        return;
    }
    node *temp=head;
    printf("list is \n");
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp=temp->next;

    }
    printf("NULL");
}

int main(){
    while(1){
        printf("\nMENU\n1.insert at end\n2,insert at beginning\n3.insert at any position\n4.delete from end\n5.delete from beginning\n6.delete from any position\n7.display\n8.exit\n");
        printf("enter your choice");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:
                int a;
                printf("enter the value to insert: \n");
                scanf("%d",&a);
                insertEnd(a);
                break;
            case 2:
                int b;
                printf("enter the value to insert: \n");
                scanf("%d",&b);
                insertBegin(b);
                break;
            case 3:
                int c;
                int d;
                printf("enter the position: \n");
                scanf("%d",&d);
                printf("enter the value to insert: \n");
                scanf("%d",&c);
                insertPos(c,d);
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                deleteBegin();
                break;
            case 6:
                int e;
                printf("enter the position: ");
                scanf("%d",&e);
                deletePos (e);
                break;
            case 7:
                display();
                break;    
            case 8:
                printf("exiting...");
                exit(0);
            default:
                printf("invalid choice");
                break;               
        }
    }
}