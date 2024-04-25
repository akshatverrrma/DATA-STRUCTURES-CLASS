#include <stdio.h>
#include <stdlib.h>

// Define a Node struct
struct Node {
    int data;
    struct Node* next;
};

// Create a new node with the specified data and next pointer
struct Node* createNode(int data, struct Node* next) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

// Example usage
int main() {
    // Create a new node with data=42 and next=NULL
    struct Node* node1 = createNode(42, NULL);

    // Create a new node with data=13 and next=node1
    struct Node* node2 = createNode(13, node1);

    // Print the data values of the nodes
    printf("node1 data: %d\n", node1->data);
    printf("node2 data: %d\n", node2->data);

    // Free the memory allocated for the nodes
    free(node1);
    free(node2);

    return 0;
}
