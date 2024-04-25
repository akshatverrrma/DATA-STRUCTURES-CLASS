#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

void print_list(struct node *head) 
{
    printf("List: ");
    while (head != NULL) {
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
    new_node->prev = NULL;
    return new_node;
}

void add_to_beginning(struct node **head, int data) 
{
    struct node *new_node = create_node(data);
    new_node->next = *head;
    if (*head != NULL) 
    {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void add_to_end(struct node **head, int data) 
{
    struct node *new_node = create_node(data);
    if (*head == NULL) 
    {
        *head = new_node;
        return;
    }
    struct node *last_node = *head;
    while (last_node->next != NULL) 
    {
        last_node = last_node->next;
    }
    last_node->next = new_node;
    new_node->prev = last_node;
}

void delete_node(struct node **head, struct node *node_to_delete) 
{
    if (*head == NULL || node_to_delete == NULL) 
    {
        return;
    }
    if (*head == node_to_delete) 
    {
        *head = node_to_delete->next;
    }
    if (node_to_delete->next != NULL) 
    {
        node_to_delete->next->prev = node_to_delete->prev;
    }
    if (node_to_delete->prev != NULL) 
    {
        node_to_delete->prev->next = node_to_delete->next;
    }
    free(node_to_delete);
}

int main() 
{
    struct node *head = NULL;
    int data;
    char choice;
    do 
    {
        printf("Enter the data for the node: ");
        scanf("%d", &data);
        add_to_end(&head, data);
        printf("Do you want to add another node? (Y)es or (N)o: ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
    print_list(head);
    return 0;
}
