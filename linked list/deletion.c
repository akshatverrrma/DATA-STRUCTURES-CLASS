//deletion of last element
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
node *delete(node * HEAD)
{
    node *p, *q;
    if (HEAD->next==NULL)
    {
        free(HEAD);
        HEAD=NULL;
        return(HEAD);
    }
    q=HEAD;
    while(q->next->next!=NULL)
    {
        q=q->next;
    }
    p=q->next;
    free(p);
    q->next=NULL;
    return(HEAD);
}

int main()
{
    node *HEAD, *P;
    int n, x, i;
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
    delete(HEAD);
    printf("\nAfter Deletion-\n");
    print(HEAD);
}