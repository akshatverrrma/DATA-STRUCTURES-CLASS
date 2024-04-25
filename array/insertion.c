#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

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
    add_to_end(&head, 1);
    add_to_end(&head, 3);
    add_to_beginning(&head, 0);
    add_to_middle(head->next, 2);
    add_to_end(&head, 4);
    print_list(head);
    return 0;
}
