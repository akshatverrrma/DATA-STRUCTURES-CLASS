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
int main()
{
    struct node * head = (struct node *) malloc (sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    struct node * second = (struct node *) malloc (sizeof(struct node));
    second->data = 2;
    second->next = NULL;
    head->next = second;

    struct node * third = (struct node *) malloc (sizeof(struct node));
    third->data = 3;
    third->next = NULL;
    second->next = third;

    struct node * fourth = (struct node *) malloc (sizeof(struct node));
    fourth->data = 4;
    fourth->next = NULL;
    third->next = fourth;

    struct node * five = (struct node *) malloc (sizeof(struct node));
    five->data = 5;
    five->next = NULL;
    fourth->next = five;

    display(head);
}