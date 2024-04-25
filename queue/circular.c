#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() 
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

// Function to check if the queue is empty
int isEmpty() 
{
    if (front == -1) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

// Function to add an element to the queue
void enqueue() 
{
    if (isFull()) 
    {
        printf("Queue is full.\n");
    } 
    else 
    {
        int data;
        if (front == -1) 
        {
            front = 0;
        }
        printf("Inset the element in queue : ");
        scanf("%d", &data);
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = data;
    }
}

// Function to remove an element from the queue
int dequeue() 
{
    int data;
    if (isEmpty()) 
    {
        printf("Queue is empty.\n");
        return -1;
    } 
    else 
    {
        data = queue[front];
        if (front == rear) 
        {
            front = -1;
            rear = -1;
        } 
        else 
        {
            front = (front + 1) % MAX_SIZE;
        }
        return data;
    }
}

void peek()
{
    if (front == - 1 || front > rear)
        printf("Queue is empty \n");
    else
    {
        printf("%d ", queue[front]);
        printf("\n");
    }
} 

// Function to display the elements of the queue
void display() 
{
    int i;
    if (isEmpty()) 
    {
        printf("Queue is empty.\n");
    } 
    else 
    {
        printf("Elements in the queue are: ");
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) 
        {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]);
    }
}

// Main function
int main() 
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display the topmost element of queue \n");
        printf("4.Display all the elements\n");
        printf("5.To exit the loop and end the program ");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            exit(1);
            default:
            printf("Wrong choice \n");
        } 
    }
    return 0;
}
