#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct 
{
  int top;
  int data[MAX_STACK_SIZE];
} Stack;

// Function prototypes
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
int is_empty(Stack *stack);
int is_full(Stack *stack);

int main() 
{
  Stack stack;
  stack.top = -1;

  // Push some values onto the stack
  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  peek(&stack);

  // Pop the values off the stack
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));

  return 0;
}

// Push a value onto the stack
void push(Stack *stack, int value) 
{
  if (is_full(stack)) 
  {
    printf("Stack is full\n");
    exit(1);
  }

  stack->data[++stack->top] = value;
}

// Pop a value off the stack
int pop(Stack *stack) 
{
  if (is_empty(stack)) 
  {
    printf("Stack is empty\n");
    exit(1);
  }

  return stack->data[stack->top--];
}

// Peek at the top value on the stack without removing it
int peek(Stack *stack) 
{
  if (is_empty(stack)) 
  {
    printf("Stack is empty\n");
    exit(1);
  }

  return stack->data[stack->top];
}

// Check if the stack is empty
int is_empty(Stack *stack) 
{
  return stack->top == -1;
}

// Check if the stack is full
int is_full(Stack *stack) 
{
  return stack->top == MAX_STACK_SIZE - 1;
}
