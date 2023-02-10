#include "vector.h"

Vector *vectorCtor(size_t size, size_t elem_size)
{
    Vector *vector = (Vector *) calloc(1, sizeof(vector[0]));
    if (vector == nullptr)
        return nullptr;

    vector->elem_size = elem_size;
    vector->data = calloc(size, elem_size);
    if (vector->data == nullptr)
    {
        free(vector);
        return nullptr;
    }

    vector->size = 0;
    vector->capacity = size;
    return vector;
}

void vectorDtor(Vector *vector)
{
    free(vector->data);
    vector->elem_size = 0;
    vector->size = 0;
    vector->capacity = 0;
}

void *vectorResize(Vector *vector)
{
    if (vector->data == nullptr)
    {
        vector->capacity = 2;
        vector->data = calloc(vector->capacity, vector->elem_size);
        if (vector->data == nullptr)
            return nullptr;
    }
    if (vector->capacity < 1)
    {
        vector->data = realloc(vector->data,
                               vector->elem_size * 2);
        if (vector->data == nullptr)
            return nullptr;
        vector->capacity = 2;
    }
    if (vector->capacity - vector->size <= 1)
    {
        vector->capacity *= 2;
        vector->data = realloc(vector->data,
                               vector->elem_size * vector->capacity);
        if (vector->data == nullptr)
            return nullptr;

    }
    else if (vector->size * 4 <= vector->capacity
        && vector->capacity > 1)
    {
        vector->capacity /= 2;
        vector->data = realloc(vector->data,
                               vector->elem_size * vector->capacity);
        if (vector->data == nullptr)
            return nullptr;
    }
    return vector;
}

int vectorPush(Vector *vector, void *buffer)
{
    if (vectorResize(vector) == nullptr)
        return 0;

    memcpy((char *) vector->data + vector->elem_size * vector->size,
           buffer,
           vector->elem_size);
    vector->size++;
    return 1;
}

int vectorTop(Vector *vector, void *buffer)
{
    if (vector->size == 0)
        return 0;

    char *top_elem =
        (char *) vector->data + vector->elem_size * (vector->size - 1);
    memcpy(buffer, top_elem, vector->elem_size);
    vector->size--;
    
    if (vectorResize(vector) == nullptr)
        return 0;

    return 1;
}

int vectorPop(Vector *vector)
{
    if (vector->size == 0)
        return 0;

    vector->size--;

    if (vectorResize(vector) == nullptr)
        return 0;

    return 1;
}