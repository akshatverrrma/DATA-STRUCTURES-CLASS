#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
    struct node * after;
}node;
void print1(struct node * head)
{
    struct node * ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\t", ptr->data);
        ptr=ptr->next;
    }
}
void print2(struct node * tail)
{
    struct node * ptr= tail;
    while(ptr!=NULL)
    {
        printf("%d\t", ptr->data);
        ptr=ptr->after;
    }
}
int main()
{
    int n;
    struct node * head, * p, * tail;
    head=(node *)malloc(sizeof(node));
    printf("Enter the number of element you want to enter:");
    scanf("%d", &n);
    scanf("%d", &(head->data));
    head->next=NULL;
    p=head;
    tail->after=NULL;
    tail=head;
    for(int i=1; i<n; i++)
    {
        p->next=(node *)malloc(sizeof(node));
        p=p->next;
        scanf("%d", &(p->data));
        p->next=NULL;
        p->after=tail;
        tail=p;
    }
    print1(head);
    printf("\n");
    print2(tail);
}