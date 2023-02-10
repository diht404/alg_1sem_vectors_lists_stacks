#ifndef STACKS_VECTOR__VECTOR_H
#define STACKS_VECTOR__VECTOR_H

#include "../common.h"

struct Vector
{
    void *data = nullptr;
    size_t elem_size = 0;

    size_t size = 0;
    size_t capacity = 0;
};

Vector *vectorCtor(size_t size, size_t elem_size);

void vectorDtor(Vector *vector);

void *vectorResize(Vector *vector);

int vectorPush(Vector *vector, void *buffer);

int vectorTop(Vector *vector, void *buffer);

int vectorPop(Vector *vector);

#endif STACKS_//VECTOR__VECTOR_H
