#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int data;
    struct stack * next;
} node;
struct stack *rear=NULL,*front=NULL;
int isempty()
{
    if(front==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue()
{
    printf("Enter data: \n");
    if(front==NULL)
    {
        front=(struct stack *)malloc(sizeof(struct stack));
        scanf("%d",&front->data);
        front->next=NULL;
        rear=front;
    }
    else
    {
        rear->next=(struct stack *)malloc(sizeof(struct stack));
        rear=rear->next;
        scanf("%d",&rear->data);
        rear->next=NULL;
    }
}
int dequeue()
{ 
    int val;
    struct stack *temp;
    if (isempty())
    {
        printf("\nQueue underflow \n ");
        exit(1);
    }
    temp=front;
    front=front->next;
    temp->next=NULL;
    val=temp->data;
    free(temp);
    return(val);
}
int peek()
{
    if(isempty())
    {
        printf("\nQueue is empty \n");
        exit(1);
    }
    return (front->data);
}
void display()
{
    struct stack *p=front;
    if(isempty())
    {
        printf("\nQueue is empty  \n");
        exit(1);
    }
    printf("\nQueue as a linked list :  \n");
    while(p!=NULL)
    {
        if(p->next!=NULL){
        printf("%d->",p->data);
        }
        else{
            printf("%d->NULL \n",p->data);
        }
        p=p->next;
    }
}
int main()
{
int ch;
    while(1)
    {
    printf("\n1.Insert");
    printf("\n2.Delete");
    printf("\n3.Peek");
    printf("\n4.Display");
    printf("\n5.exit \n");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        enqueue();
        break;
        case 2:
        printf("The deleted element is: %d \n",dequeue());
        break;
        case 3:
        printf("\nThe topmost element is: %d \n",peek());
        break;
        case 4:
        display();
        break;
        case 5:
        exit(1);
    }
    }
}