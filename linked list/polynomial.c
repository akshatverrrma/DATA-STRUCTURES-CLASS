#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int coef;
    int degree;
    struct node *next;
}poly;
int main()
{
    poly *root,*temp,*newnode;
    int hdegree,coef;
    root=NULL;
    printf("Enter the highest degree of polynomial:");
    scanf("%d",&hdegree);
    while(hdegree>=0)
    {
        printf("Enter cofficient of variable with degree %d:",hdegree);
        scanf("%d",&coef);
    if(coef!=0)
    {
        newnode=(poly*)malloc(sizeof(poly));
        newnode->coef=coef;
        newnode->degree=hdegree;
        newnode->next=NULL;
        if(root==NULL)
        {
            root=newnode;
            temp=root;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
        hdegree--;
    }
    printf("\n The Polynomial is:\n\n");
    temp=root;
    while(temp!=NULL)
    {
        if(temp->coef>0)
        printf("+(%dx^%d)",temp->coef,temp->degree);
        else
        printf("%dx^%d",temp->coef,temp->degree);
        temp=temp->next;
    }
    return 0;
}