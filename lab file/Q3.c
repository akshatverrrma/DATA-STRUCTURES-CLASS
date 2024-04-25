#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
void insert_at_nth_position(struct Node** head, int data, int n) 
{
    if (n < 0) 
    {
        printf("Invalid position.\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (n == 0) 
    {
        new_node->next = *head;
        *head = new_node;
    } 
    else 
    {
        struct Node* prev_node = *head;
        for (int i = 0; i < n - 1 && prev_node != NULL; i++) 
        {
            prev_node = prev_node->next;
        }
        if (prev_node == NULL) 
        {
            printf("Invalid position.\n");
            return;
        }
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
    printf("Inserted %d at position %d.\n", data, n);
}
void delete_from_nth_position(struct Node** head, int n) 
{
    if (*head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    if (n == 0) 
    {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Deleted from position %d.\n", n);
        return;
    }
    struct Node* prev_node = *head;
    for (int i = 0; i < n - 1 && prev_node != NULL; i++) 
    {
        prev_node = prev_node->next;
    }
    if (prev_node == NULL || prev_node->next == NULL) 
    {
        printf("Invalid position.\n");
        return;
    }
    struct Node* temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
    printf("Deleted from position %d.\n", n);
}
void display(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;
    int data,position, position_del;
    int n=5,p=5;
    while(n!=0)
    {
        printf("Enter data and position");
        scanf(" %d ",&data);
        scanf(" %d ",&position);
        insert_at_nth_position(&head,data,position);
        n--;
    }
    while(p!=0)
    {
        printf("Enter position");
        scanf(" %d ",&position_del);
        delete_from_nth_position(&head,position_del);
        p--;
    }
    display(head);
    return 0;
}
