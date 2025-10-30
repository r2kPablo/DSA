#include<stdio.h>
 
typedef struct{
    int row;
    int col;
    int value;
}Matrix;

void displayMatrix(int row,int col, int matrix[row][col]){
    printf("the oroginal matrix:\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
}
void convert(int row,int col,int matrix[row][col],int n,Matrix sparse[]){
    sparse[0].row=row;
    sparse[0].col=col;
    sparse[0].value=n;

    int k=1;
    for(int i=0; i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]!=0){
                sparse[k].row=i;
                sparse[k].col=j;
                sparse[k].value=matrix[i][j];
                k++;
            }
        }
    }
}
void displaySparseMatrix(Matrix sparse[]){
    int terms=sparse[0].value;
    printf("ROW\tCOL\tVALUE\n");
    for(int i=0;i<terms+1;i++){
        printf("%d\t%d\t%d",sparse[i].row,sparse[i].col,sparse[i].value);
        printf("\n");
    }
    
}
void convertTranspose(Matrix sparse[],Matrix transpose[]){
    int t = sparse[0].value;
    transpose[0].row=sparse[0].col;
    transpose[0].col=sparse[0].row;
    transpose[0].value=t;
    if(t>0){
        int k=1;
        for(int i=0;i<sparse[0].col;i++){
            for(int j=1;j<=t;j++){
                if(sparse[j].col==i){
                    transpose[k].row=sparse[j].col;
                    transpose[k].col=sparse[j].row;
                    transpose[k].value=sparse[j].value;
                    k++;
                }
            }
        }
    }
    

}
int main(){
    Matrix sparse[50];
    Matrix transpose[50];
    int col,row,n=0;
    printf("enter the number of rows:\n");
    scanf("%d",&row);
    printf("enter the number of column:\n");
    scanf("%d",&col);
    int matrix[row][col];

    for(int i=0;i<row;i++){
        printf("enter the elements of row %d",i);
        for(int j=0;j<col;j++){
            scanf("%d",&matrix[i][j]);
            if(matrix[i][j]!=0){
                n++;
            }

        }
    }
    displayMatrix(row,col,matrix);
    convert(row,col,matrix,n,sparse);
    displaySparseMatrix(sparse);
    convertTranspose(sparse,transpose);
    printf("transpose:\n");
    displaySparseMatrix(transpose);
    return 0;
}