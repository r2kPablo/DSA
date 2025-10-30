#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *right;
    struct node *left;
};
struct node *createNode(int value){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->right=newNode->left=NULL;
    return newNode;
}
struct node *insert(struct node *root,int value){
    
    if(root==NULL){
        return createNode(value);
    }
    if(value<root->data){
        root->left=insert(root->left,value);
    }else if(value>root->data){
        root->right=insert(root->right,value);
    }
    return root;
    
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);

    }

}
int main(){
    struct node *root=NULL;
    while(1){
        printf("\nMENU\n1.insert value to tree\n2.inorder travaersal\n3.preorder\n4.postorder\n5.exit\n");
        printf("enter the choice: ");
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\nenter the value to insert: ");
            int value;
            scanf("%d",&value);
            root=insert(root,value);
            break;
        case 2:
            if (root==NULL){
                printf("tree is empty");
            }else{
                inorder(root);
            }
            
        default:
            break;
        }
    }
}