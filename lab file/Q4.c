#include <stdio.h>
#include <stdlib.h>

// Define a node of the linked list
struct Node 
{
    int data;
    struct Node* next;
};

// Initialize the top of the stack to NULL
struct Node* top = NULL;

// Insert a new node at the top of the stack
void push(int data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = top;
    top = new_node;
    printf("Pushed %d onto the stack.\n", data);
}

// Delete the top node of the stack
void pop() 
{
    if (top == NULL) 
    {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
    printf("Popped element from the stack.\n");
}

// Display the stack
void display() 
{
    if (top == NULL) 
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    struct Node* temp = top;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    // Push elements onto the stack
    push(1);
    push(2);
    push(3);
    push(4);
    display();

    // Pop elements from the stack
    pop();
    pop();
    display();

    return 0;
}
