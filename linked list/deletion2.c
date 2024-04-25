//deletion between 
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
}node;
void print(struct node * P)
{
    while(P!=NULL)
    {
        printf("%d\t", P->data);
        P=P->next;
    }
}
node * del(node * HEAD, int LOC){
    node * p, * q;
    int i;
    if(LOC==1)
    {
        p=HEAD;
        HEAD=HEAD->next;
        free(p);
        return(HEAD);
    }
    q=HEAD;
    for(i=1; i<LOC-1;i++)
    {
        q=q->next;
    }
    if(q==NULL)
    {
        printf("underflow");
        return(HEAD);
    }
    p=q->next;
    q->next=p->next;
    free(p);
    return(HEAD);
}

int main()
{
    node *HEAD, *P;
    int n, x, i, LOC;
    printf("Enter the no. of element:");
    scanf("%d", &n);
    HEAD=(node*)malloc(sizeof(node));
    scanf("%d", &(HEAD->data));
    HEAD->next=NULL;
    P=HEAD;
    for(i=1; i<n; i++)
    {
        P->next=(node*)malloc(sizeof(node));
        P=P->next;
        P->next=NULL;
        scanf("%d", &(P ->data));
    }
    print(HEAD);
    printf("\nEnter the LOC:");
    scanf("%d", &LOC);
    del(HEAD, LOC);
    printf("\nAfter Deletion-\n");
    print(HEAD);
}