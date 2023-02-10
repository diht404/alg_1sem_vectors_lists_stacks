#ifndef STACKS_STACK_VECTOR_STACK_H
#define STACKS_STACK_VECTOR_STACK_H

#include "../vector/vector.h"

struct Stack
{
    Vector *vector = {};
};

Stack* stack_ctr(size_t size, size_t element_size);

Stack* stack_dtr(Stack *stack);

int stackPush(struct Stack* stack, void* buffer);

int stackTop(struct Stack* stack, void* buffer);

int stackPop(Stack *stack);

#endif //STACKS_STACK_VECTOR_STACK_H
