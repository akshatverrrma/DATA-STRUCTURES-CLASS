//polynomial representation in linked list:
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int coef;
    int pow;
    struct node *next;
}poly;
int main()
{
    //enter the values of coeff and power of the variables
    poly *root,*temp,*newnode;
    root=NULL;
    int hdegree,coeff;
    printf("Enter the highest degree of the polynomial:");
    scanf("%d",&hdegree);
    while(hdegree>=0)
    {
    
        printf("Enter the coffecient of the %d degree:",hdegree);
        scanf("%d",&coeff);
        newnode=(poly*)malloc(sizeof(poly));
        newnode->coef=coeff;
        newnode->pow=hdegree;

        if(coeff!=0)
        {
            if(root==NULL)
            {
                temp=root=newnode;
            }
            else
            {
                temp->next=newnode;
                temp=newnode;
            }
        }
        hdegree--;
    }
    //printing of the elements in the the linked list:
    temp=root;
    while(temp!=NULL)
    {
        if(temp->coef>0)
        printf("+%dx%d",temp->coef,temp->pow);
        else
        printf("-%dx%d",temp->coef,temp->pow);
        temp=temp->next;
    }
    return 0;
}