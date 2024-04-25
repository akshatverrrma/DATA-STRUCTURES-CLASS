#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node * prev;
    int data;
    struct node *next;
}node;
void insert_ATend(struct node *p,int data)
{
    struct node * new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    p->next=new;
    new->next=NULL;
    new->prev=p;
}
struct node * insert_ATbeg(struct node * head,int data)
{
    struct node * new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->prev=NULL;
    new->next=head;
    head->prev=new;
    head=new;
    return head;
}
void insert_ATrandom(struct node *p,int data)
{
     struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->next=p->next;
    new->prev=p;
    p->next=new;
    p=new->next;
    p->prev=new;
}
struct node * create(struct node *head,int n)
{
    struct node *p;
    int data;
    head=(struct node *)malloc(sizeof(struct node));
    head->next=NULL;
    head->prev=NULL;
    printf("\nEnter data for head node: ");
    scanf("%d",&head->data);
    p=head;
    for(int i=1;i<n;i++)
    {
        printf("Enter data for node (%d): ",i+1);
        scanf("%d",&data);
       insert_ATend(p,data);
       p=p->next;
    }
    return head;
}
void display_forward(struct node * head)
{
  struct node *p;
  p=head;
  printf("\nTraversing forwards:");
  while(p!=NULL)
  {
    if(p->next!=NULL)
    {
        printf("%d->",p->data);
    }
    else{
        printf("%d->NULL",p->data);
    }
    p=p->next;
  }
}
void display_back(struct node *head)
{
    struct node *p;
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    printf("\nTraversing backwards: ");
    while(p!=NULL)
    {
        if(p->prev!=NULL)
        {
            printf("%d->",p->data);
        }
        else{
            printf("%d->NULL",p->data);
        }
        p=p->prev;
    }
}
int main()
{
    struct node *head,*p;
    int x;
    int n,pos,ch;
    printf("\nEnter no of nodes: ");
    scanf("%d",&n);
    head=create(head,n);
    printf("\nThe linked list is: ");
    display_forward(head);
    display_back(head);
    printf("\nEnter data for the new node :");
    scanf("%d",&x);
    printf("\nEnter the position at which new node is to be inserted");
    printf("\nPress 1: To insert at first position");
    printf("\nPress 2: To insert at last position");
    printf("\nPress 3: To insert at any random position\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        head=insert_ATbeg(head,x);
        break;
        
        case 2:
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        insert_ATend(p,x);
        break;

        case 3:
        printf("Enter the random position: ");
        scanf("%d",&pos);
        if(pos>n)
        {
            printf("\nWrong input! Thera are only %d elements in the linked list currently",n);
            printf("\nEnter position again: ");
            scanf("%d",&pos);        
        }
            p=head;
            for(int i=1;i<pos-1;i++)
            {
                p=p->next;
            }
            insert_ATrandom(p,x);
            break;
    }  
    printf("\nThe new linked list is: ");
    display_forward(head);
    display_back(head);
    return 0;
}