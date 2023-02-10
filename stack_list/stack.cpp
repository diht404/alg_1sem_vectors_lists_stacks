#include "stack.h"

Stack *stack_ctr(size_t size, size_t element_size)
{
    Stack *stack = (Stack *) calloc(1, sizeof(stack[0]));
    stack->list = listCtor(element_size);

    return stack;
}

Stack *stack_dtr(Stack *stack)
{
    listDtor(stack->list);
    stack->list = nullptr;

    return nullptr;
}

int stackPush(struct Stack *stack, void *buffer)
{
    return listPush(stack->list, buffer);
}

int stackTop(struct Stack *stack, void *buffer)
{
    return listTop(stack->list, buffer);
}

int stackPop(Stack *stack)
{
    return listPop(stack->list);
}
