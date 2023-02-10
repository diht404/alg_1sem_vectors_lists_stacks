#include "stack.h"

Stack *stack_ctr(size_t size, size_t element_size)
{
    Stack *stack = (Stack *) calloc(1, sizeof(stack[0]));
    stack->vector = vectorCtor(size, element_size);

    return stack;
}

Stack *stack_dtr(Stack *stack)
{
    vectorDtor(stack->vector);
    stack->vector = nullptr;

    return nullptr;
}

int stackPush(struct Stack *stack, void *buffer)
{
    return vectorPush(stack->vector, buffer);
}

int stackTop(struct Stack *stack, void *buffer)
{
    return vectorTop(stack->vector, buffer);
}

int stackPop(Stack *stack)
{
    return vectorPop(stack->vector);
}
