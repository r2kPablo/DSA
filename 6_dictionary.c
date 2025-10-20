#include <stdio.h>
#include<stdlib.h>
#include <string.h>
struct node{
    char word[50];
    char meaning[100];
    struct node *left,*right;
};
struct node *createNode(char word[],char meaning[]){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    strcpy(newNode->word,word);
    strcpy(newNode->meaning,meaning);
    newNode->left=newNode->right=NULL;
    return newNode;
}

struct node *insert(struct node* root,char word[],char meaning[]){
    if(root==NULL){
        return createNode(word,meaning);
    }
    if (strcmp(word,root->word)<0){
        root->left=insert(root->left,word,meaning);
    }else if(strcmp(word,root->word)>0){
        root->right=insert(root->right,word,meaning);
    }else{
        printf("word already exist\n");

    }
    return root;
}
void search(struct node* root,char word[]){
    if(root==NULL){
        printf("word not found|n");
        return;
    }
    if(strcmp(word,root->word)==0){
        printf("meaning of %s is %s\n",word,root->meaning);
    }else if(strcmp(word,root->word)<0){
        search(root->left,word);
    }else{
        search(root->right,word);
    }

}

void inorder(struct node* root){
    if (root!=NULL){
        inorder(root->left);
        printf("%s : %s\n",root->word,root->meaning);
        inorder(root->right);

    }

}

int main(){
    struct node *root=NULL;
    int ch;
    char word[50],meaning[100];
    do{
        printf("MENU\n");
        printf("1.Insert word\n2.Search word\n3.Display DIctionary\n4.Exit\n");
        printf("enter your choice: \n");
        scanf("%d",&ch);
        getchar();

        switch(ch){
            case 1:
                printf("enter word: \n");
                fgets(word,50,stdin);
                printf("enetr meaning:\n");
                fgets(meaning,100,stdin);
                root=insert(root,word,meaning);
                break;
            case 2:
                printf("enter the word:\n");
                fgets(word,50,stdin);
                search(root,word);
                break;
            case 3:
                printf("dictionary word\n");
                inorder(root);
                break;
            case 4:
                printf("exiting..");
                exit(0);
            default:
                printf("invaild choice");                
        }
    }while(1);
    return 0;
}