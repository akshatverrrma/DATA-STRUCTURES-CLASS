#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
int main()
{
    node *head,*p;
    int n,x=0,i;
    printf("enter no of elements to be inserted:");
    scanf("%d",&n);
    head=(node*)malloc(sizeof(node));
    printf("enter elments:");
    scanf("%d",&(head->data));
    head->next=NULL;
    p=head;
    for(i=1;i<n;i++)
    {
        p->next=(node*)malloc(sizeof(node));
        p=p->next;
        p->next=NULL;
        scanf("%d",&(p->data));
    }
    printf("\n enter node to be searched:");
    scanf("%d",&x);
    p=head;
    while(p!=NULL)
    {
        if(p->data==x)
        {
            printf("node found");
        break;
        }
    p=p->next;
    }
}