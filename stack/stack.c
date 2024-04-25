#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct 
{
  int top;
  int data[MAX_STACK_SIZE];
} Stack;

int peek(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int isempty(Stack *stack);
int isfull(Stack *stack);
int main()
{
    Stack stack;
    stack.top = -1;
    int n;
    int value;
    scanf("%d ",&n);
    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d ",&value);
        push(&stack, value);
    }
    
    peek(&stack);
    
    for(int i=1 ; i<=n ; i++)
    {
       printf("%d\n", pop(&stack)); 
    }

    return 0;
}
int peek (Stack *stack )
{
    if (isempty(stack)) 
    {
        printf("\n Stack is empty \n");
        exit(1);
    }

  return stack->data[stack->top];
}
void push(Stack *stack, int value)
{
    if(isfull(stack))
    {
        printf("\n Stack is empty \n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack)
{
    if(isempty(stack))
    {
        printf("\n Stack is empty \n");
        exit(1);
    }
    return stack->data[stack->top--];
}

int isfull(Stack *stack) 
{
  return stack->top == MAX_STACK_SIZE - 1;
}

int isempty(Stack *stack)
{
    return stack->top == -1;
}