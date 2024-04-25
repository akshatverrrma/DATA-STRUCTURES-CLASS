#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
}head;
void create_linkedlist(int n)
{
    int data;
    if(n==0)
    {
    printf("Enter valid no. of nodes");
    }
    else
    {
        head=(struct node*) malloc (sizeof(struct node*));
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
    return 
}
void print_list(struct node *head) 
{
    printf("List: ");
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct node *create_node(int data) 
{
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_to_beginning(struct node **head, int data) 
{
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void add_to_middle(struct node *prev_node, int data) 
{
    if (prev_node == NULL) 
    {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void add_to_end(struct node **head, int data) 
{
    struct node *new_node = create_node(data);
    struct node *last_node = *head;
    if (*head == NULL) 
    {
        *head = new_node;
        return;
    }
    while (last_node->next != NULL) 
    {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

int main() 
{
    struct node *head = NULL;
    int data, position;
    int choice;
    char choiceyn;
    int n;
     printf("Enter the number of nodes you want to create in linked list :");
     scanf("%d",&n);
     create_linkedlist(n);
    do 
    {
        printf("Enter the data for the node: ");
        scanf("%d", &data);
        printf("Where do you want to add the node? (1)Beginning, (2)Middle, or (3)End: ");
        scanf(" %d",&choice);
        if (choice == 1) 
        {
            add_to_beginning(&head, data);
        } 
        else if (choice == 2) 
        {
            printf("Enter the position after which you want to add the node: ");
            scanf("%d", &position);
            add_to_middle(head, data & position);
        } 
        else if (choice == 3) 
        {
            add_to_end(&head, data);
        } 
        else 
        {
            printf("Invalid choice\n");
        }
        printf("Do you want to add another node? (Y)es or (N)o: ");
        scanf(" %c", &choiceyn);
    } while (choiceyn == 'Y' || choiceyn == 'y');
    print_list(head);
    return 0;
}
