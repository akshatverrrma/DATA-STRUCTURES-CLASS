#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node * next;
}*head;
void create_linkedlist(int n)
{
    int data;
    if(n==0)
    {
    printf("Enter valid no. of nodes");
    }
    else
    {
        head=(struct node * ) malloc (sizeof(struct node) );
        printf("Enter the data for node 1 :");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        struct node * temp ,* new_node;
        
        if(n>1)
        {
            temp=head;
            for(int i=1;i<n;i++)
            {
                new_node=(struct node *) malloc (sizeof(struct node) );
                printf("Enter the data for node %d :",i+1);
                scanf("%d",&data);
                new_node->data=data;
                new_node->next=NULL;
                temp->next=new_node;
                temp=new_node;
            }
        }
         temp=NULL;
    }
}
void display(struct node * a)
{
    while(a!=NULL)
    {
      printf("%d\n",a->data);
      a=a->next;  
    }
}
void insert_after(struct node * head,int data,int new_data)
{
    struct node * temp=head;
    while(temp)
    {
        if(temp->data==data)
        {
            struct node * new_node;
            new_node=(struct node *) malloc (sizeof(struct node));
            new_node->data=new_data;
            new_node->next=temp->next;
            temp->next=new_node;
            return;
        }
        temp=temp->next;
    }
}
void push(struct node ** head_ref,int data){
    if((*head_ref)==NULL)
    {
        printf("There exists no linked list ");
        return;
    }

    struct node * new_node;
    new_node=(struct node *) malloc (sizeof(struct node));
    new_node->data=data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}
void append(struct node ** head_ref,int new_data){
    struct node * new_node;
    new_node=(struct node *) malloc (sizeof(struct node));
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        new_node->data=new_data;
        new_node->next=NULL;
        return;
    }
    else{
        struct node * last=*head_ref;
        while(last->next!=NULL)
        {
            last=last->next;
        }
        new_node->data=new_data;
        new_node->next=NULL;
        last->next=new_node;
        return;
    }
}

int main()
{
     int n;
     printf("Enter the number of nodes you want to create in linked list :");
     scanf("%d",&n);
     create_linkedlist(n);
     display(head);
     push(&head,10);
     display(head);
     insert_after(head,10,20);
     display(head);
     append(&head,69);
     display(head);
     return 0;
}