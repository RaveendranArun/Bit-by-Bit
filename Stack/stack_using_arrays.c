#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct Stack
{
    int top;
    int data[MAX_STACK_SIZE];
}Stack;

bool stack_isEmpty(Stack* stack)
{
    if (stack->top == -1)
        return true;
    return false;
}   

bool stack_isFull(Stack* stack)
{
    if (stack->top == MAX_STACK_SIZE -1)
        return true;
    return false;
}

void stack_init(Stack* stack)
{
    stack->top = -1;
    memset(stack->data, 0, MAX_STACK_SIZE);
}

void stack_push(Stack* stack, int x)
{
    if (stack_isFull(stack))
    {
        printf("Stack is full\n");
        return;
    }

    stack->top++;
    stack->data[stack->top] = x;
}

bool stack_pop(Stack* stack, int* value)
{
    if (stack_isEmpty(stack))
    {
        printf("Stack is empty\n");
        return true;
    }

    *value = stack->data[stack->top];
    stack->top--;
    return true;
}

bool stack_peek(Stack* stack, int* value)
{
    if (stack_isEmpty(stack))
    {
        printf("Stack is empty\n");
        return false;
    }

    *value = stack->data[stack->top];
    return true;
}

void printStack(Stack* stack)
{
    for (int iter = stack->top; iter >= 0; --iter)
    {
        printf("stack value: %d \n", stack->data[iter]);
    }
    printf("\n");
}

int main()
{
    Stack st;
    int value = 0;

    stack_init(&st);
    stack_push(&st, 1);
    stack_push(&st, 2);
    stack_push(&st, 3);
    stack_peek(&st, &value);
    printf("peek value: %d\n", value);
    printStack(&st);
    stack_pop(&st, &value);
    printf("value poped: %d\n", value);
    printStack(&st);


    return 0;
}