#include "vector.h"

void vectorCtor(Vector *vector, size_t elem_size)
{
    vector->elem_size = elem_size;
    vector->size = 0;
    vector->capacity = 0;
    vectorResize(vector);
}

void vectorDtor(Vector *vector)
{
    free(vector->data);
    vector->elem_size = 0;
    vector->size = 0;
    vector->capacity = 0;
}

void vectorResize(Vector *vector)
{
    if (vector->data == nullptr)
    {
        vector->capacity = 2;
        vector->data = calloc(vector->capacity, vector->elem_size);
    }
    if (vector->capacity < 1)
    {
        vector->data = realloc(vector->data,
                               vector->elem_size * 2);
        vector->capacity = 2;
    }
    if (vector->capacity - vector->size <= 1)
    {
        vector->capacity *= 2;
        vector->data = realloc(vector->data,
                               vector->elem_size * vector->capacity);

    }
    else if (vector->size * 4 <= vector->capacity
        && vector->capacity > 1)
    {
        vector->capacity /= 2;
        vector->data = realloc(vector->data,
                               vector->elem_size * vector->capacity);
    }
}

int vectorPush(Vector *vector, void *buffer)
{
    vectorResize(vector);

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
    vectorResize(vector);

    return 1;
}

int vectorPop(Vector *vector)
{
    if (vector->size == 0)
        return 0;

    vector->size--;
    vectorResize(vector);

    return 1;
}