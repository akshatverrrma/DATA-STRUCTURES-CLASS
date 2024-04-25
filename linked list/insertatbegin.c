#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int value;
    struct Node* next;
};

void insert_at_beginning(struct Node** head_ref, int new_value) 
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->value = new_value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() 
{
    struct Node* head = NULL;

    insert_at_beginning(&head, 3);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 1);

    printf("List: ");
    struct Node* current = head;
    while (current != NULL) 
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    return 0;
}
