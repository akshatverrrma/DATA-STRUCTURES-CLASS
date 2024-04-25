#include <stdio.h>
#include <stdlib.h>

// Define a deque node structure
struct DequeNode {
    int data;
    struct DequeNode* next;
    struct DequeNode* prev;
};

// Define a deque structure
struct Deque {
    struct DequeNode* front;
    struct DequeNode* rear;
};

// Create an empty deque
struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = NULL;
    dq->rear = NULL;
    return dq;
}

// Check if the deque is empty
int isEmpty(struct Deque* dq) {
    return (dq->front == NULL && dq->rear == NULL);
}

// Insert an element at the front of the deque
void insertFront(struct Deque* dq, int item) {
    struct DequeNode* node = (struct DequeNode*)malloc(sizeof(struct DequeNode));
    node->data = item;
    node->next = NULL;
    node->prev = NULL;
    if (isEmpty(dq)) {
        dq->front = node;
        dq->rear = node;
    } else {
        node->next = dq->front;
        dq->front->prev = node;
        dq->front = node;
    }
}

// Insert an element at the rear of the deque
void insertRear(struct Deque* dq, int item) {
    struct DequeNode* node = (struct DequeNode*)malloc(sizeof(struct DequeNode));
    node->data = item;
    node->next = NULL;
    node->prev = NULL;
    if (isEmpty(dq)) {
        dq->front = node;
        dq->rear = node;
    } else {
        node->prev = dq->rear;
        dq->rear->next = node;
        dq->rear = node;
    }
}

// Delete an element from the front of the deque
int deleteFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque underflow\n");
        exit(1);
    }
    int item = dq->front->data;
    struct DequeNode* temp = dq->front;
    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    } else {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }
    free(temp);
    return item;
}

// Delete an element from the rear of the deque
int deleteRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque underflow\n");
        exit(1);
    }
    int item = dq->rear->data;
    struct DequeNode* temp = dq->rear;
    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    } else {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }
    free(temp);
    return item;
}

// Display the elements of the deque
void display(struct Deque* dq) 
{
    if (isEmpty(dq)) 
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    struct DequeNode* curr = dq->front;
    while (curr != NULL) 
    {
        printf("%d ", curr->data);
            curr = curr->next;
    }
    printf("\n");
}

// Main function to test the deque implementation
int main() 
{
    struct Deque* dq = createDeque();
    insertFront(dq, 10);
    insertRear(dq, 20);
    insertFront(dq, 30);
    insertRear(dq, 40);
    display(dq);
    printf("Deleted element from the front: %d\n", deleteFront(dq));
    printf("Deleted element from the rear: %d\n", deleteRear(dq));
    display(dq);
    return 0;
}