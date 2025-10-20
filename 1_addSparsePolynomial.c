#include <stdio.h>
typedef struct{
    int coefficient;
    int exponent;

}term;
#define max 50
int addPoly(term p1[],int n,term p2[],int m,term res[]){
    int i=0,j=0,k=0;

    while (i<n && j<m){
        if(p1[i].exponent == p2[j].exponent){
            res[k].coefficient = p1[i].coefficient+p2[j].coefficient;
            res[k].exponent=p1[i].exponent;
            i++,j++,k++;
        }else if(p1[i].exponent>p2[j].exponent){
            res[k]=p1[i];
            i++,k++;
        }else{
            res[k]=p2[j];
            j++,k++;
        }
    }
    while(i<n){
        res[k]=p1[i];
        i++,k++;
    }
    while (j<m){
        res[k]=p2[j];
        j++,k++;
    }
    return k;
}
int main(){
    int n,m,nres;
    printf("enter the number of terms in first and second polynomial: ");
    scanf("%d %d",&n,&m);
    term p1[n];
    term p2[m];
    term res[n+m];
    int a,b;
    printf("enter the terms of first polynomial (coefficient exponent): ");
    for (int i=0;i<n;i++){
        printf("enter the %d term",i+1);
        scanf("%d %d",&a,&b);
        p1[i].coefficient=a;
        p1[i].exponent=b;
    }
    printf("enter the terms of second polynomial (coefficient exponent): ");
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        p2[i].coefficient=a;
        p2[i].exponent=b;
    }
    nres=addPoly(p1,n,p2,m,res);
    printf("sum of polynomialss\n:");

    for(int i=0;i<nres;i++){
        printf("%dx^%d",res[i].coefficient,res[i].exponent);
        if(i!=nres-1){
            printf("+");
        }
    }
    printf("\n");
}