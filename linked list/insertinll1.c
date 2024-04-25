#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
void display(struct node * a)
{
    while(a!=NULL)
    {
        printf("%d\n",a->data);
        a=a->next;
    }
}
void insert(struct node **a, int data)
{
    struct node* b = (struct node * ) malloc (sizeof(struct node));
    b->data = data;
    b->next = *a;
    *a = b; 
}
void delete(struct node **a)
{
    
}
int main()
{
    struct node *head = NULL;
    insert(&head,5);
    insert(&head,4);
    insert(&head,3);
    insert(&head,2);
    insert(&head,1);
    display(head);
    return 0;
}