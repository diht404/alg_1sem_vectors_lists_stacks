#ifndef STACKS_STACK_LIST__STACK_H
#define STACKS_STACK_LIST__STACK_H
#include "../list/list.h"

struct Stack
{
    List *list = {};
};

Stack* stack_ctr(size_t size, size_t element_size);

Stack* stack_dtr(Stack *stack);

int stackPush(struct Stack* stack, void* buffer);

int stackTop(struct Stack* stack, void* buffer);

int stackPop(Stack *stack);

#endif //STACKS_STACK_LIST__STACK_H
