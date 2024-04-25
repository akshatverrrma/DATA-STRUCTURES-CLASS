#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define a queue
struct Queue 
{
    int front, rear;
    char items[MAX_SIZE];
};

// Create an empty queue
struct Queue* createQueue() 
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) 
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Enqueue an element into the queue
void enqueue(struct Queue* q, char ch) 
{
    if (q->rear == MAX_SIZE - 1) 
    {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = ch;
}

// Dequeue an element from the queue
char dequeue(struct Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue underflow\n");
        exit(1);
    }
    char item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) 
    {
        q->front = -1;
        q->rear = -1;
    }
    return item;
}

// Check if a string is a palindrome or not
int isPalindrome(char str[]) 
{
    int len = strlen(str);
    struct Queue* q = createQueue();
    int i;
    for (i = 0; i < len; i++) 
    {
        enqueue(q, str[i]);
    }
    for (i = 0; i < len; i++) 
    {
        if (str[i] != dequeue(q)) 
        {
            return 0;
        }
    }
    return 1;
}

int main() 
{
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str)) 
    {
        printf("%s is a palindrome.\n", str);
    } 
    else 
    {
        printf("%s is not a palindrome.\n", str);
    }
    return 0;
}
