#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
int searching(struct node* head, int item)
{
    struct node* current = head;  // Initialize current
    // traverse till then end of the linked list
    while (current!=NULL)
    {
        if (current->data == item)
        {
            return 0;
        }
        current = current->next;
    }
    return 1;
}
int traversal(struct node*ptr)
{
    while(ptr!=NULL)
    {
        printf("Element is :%d \n",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
int main()
{
    struct node * head=NULL;
    struct node * second=NULL;
    struct node * third=NULL;
    int item;
    
    //Allocating memory for node in list.
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    //first and second node
    head->data=7;
    head->next=second;
    //second and third node
    second->data=11;
    second->next=third;
    //terminatoing at third
    third->data=13;
    third->next=NULL;
    
    traversal(head);
    printf("Enter the element to search");
    scanf("%d",&item);
    
}