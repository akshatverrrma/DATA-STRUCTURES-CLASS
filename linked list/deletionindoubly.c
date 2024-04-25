#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    struct node *prev;
    int data;
    struct node * next;
}node;
struct node * create(struct node * head,int n)
{
    struct node *new,*p;
    head=(struct node * )malloc(sizeof(struct node ));
    printf("Enter data for node(1): ");
    scanf("%d",&head->data);
    head->prev=NULL;
    head->next=NULL;
    p=head;
    for(int i=1;i<n;i++)
    {
    new=(struct node * )malloc(sizeof(struct node ));   
    printf("Enter data for node(%d): ",i+1);
    scanf("%d",&new->data);
    new->next=NULL;
    p->next=new;
    new->prev=p;
    p=p->next;    
    }
    return head;
}
struct node * del_FROMbeg(struct node *head)
{
    struct node *p;
    p=head;
    head=head->next;
    p->next=NULL;
    head->prev=NULL;
    free(p);
    return head;
}
void del_FROMend(struct node *p)
{
    struct node * q;
    q=p;
    p=p->prev;
    p->next=NULL;
    q->prev=NULL;
    free(q);
}
void del_FROMrandom(struct node *p)
{
    struct node *q;
    q=p->next;
    p->next=q->next;
    q->next->prev=p;
    q->prev=NULL;
    q->next=NULL;
    free(q);
}
void display(struct node *head)
{
    struct node *p;
    p=head;
    printf("\nTraversing forwards:\n");
    while(p!=NULL)
    {
        if(p->next!=NULL)
        {
        printf("%d->",p->data);
        }
        else{
            printf("%d->NULL\n",p->data);
        }
        p=p->next;
    }
    p=head;
    printf("\nTraversing backwards: \n");
    while(p->next!=NULL)
    {
        p=p->next;
    }
while(p!=NULL)
    {
        if(p->prev!=NULL)
        {
        printf("%d->",p->data);
        }
        else{
            printf("%d->NULL\n",p->data);
        }
        p=p->prev;
    }
}
int main()
{
    struct node *head,*p;
    int n,ch,pos;
    printf("enter no of nodes: ");
    scanf("%d",&n);
    head=create(head,n);
    printf("The linked list is: \n");
    display(head);
    printf("\nDELETION:\n ");
    printf("\nEnter the position from which element is to be deleted:\n ");
    printf("\nPress 1: To delete first element\n");
    printf("\nPress 2: To delete last element\n");
    printf("\nPress 3: To delete element from any other position\n");
    printf("\nYour choice: \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
               head=del_FROMbeg(head);
               break;
        case 2:
                p=head;
                while(p->next!=NULL)
                {
                    p=p->next;
                }
                 del_FROMend(p);
               break;
        case 3:
        printf("\nEnter position : ");
        scanf("%d",&pos);
        while(pos>=n || pos==1)
        {
            printf("Wrong input!\n");
            printf("Enter position again: ");
            scanf("%d",&pos);
        }
               p=head;
               for(int i=1;i<pos-1;i++)
               {
                p=p->next;
               }
               del_FROMrandom(p);
               break;
    }
    printf("\nThe linked list after deletion is: \n");
    display(head);
    return 0;
}