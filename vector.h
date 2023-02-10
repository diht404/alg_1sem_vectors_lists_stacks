#ifndef TASK2__VECTOR_H
#define TASK2__VECTOR_H

#include "common.h"

struct Vector
{
    void *data = nullptr;
    size_t elem_size = 0;

    size_t size = 0;
    size_t capacity = 0;
};

void vectorCtor(Vector *vector, size_t elem_size);

void vectorDtor(Vector *vector);

void vectorResize(Vector *vector);

int vectorPush(Vector *vector, void *buffer);

int vectorTop(Vector *vector, void *buffer);

int vectorPop(Vector *vector);

#endif //TASK2__VECTOR_H
