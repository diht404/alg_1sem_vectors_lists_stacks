#ifndef STACKS_LIST__LIST_H
#define STACKS_LIST__LIST_H

#include "../common.h"

struct Node
{
    void *value = nullptr;
    Node *next = nullptr;
};

Node *nodeCtor(void *value, size_t elem_size, Node *next);

struct List
{
    Node *data = nullptr;
    size_t elem_size = 0;
};

void listCtor(List *list, size_t elem_size);

void listDtor(List *list);

int listPush(List *list, void *buffer);

int listTop(List *list, void *buffer);

int listPop(List *list);

#endif //STACKS_LIST__LIST_H
