#include "list.h"

Node *nodeCtor(void *value, size_t elem_size, Node *next)
{
    Node *node = (Node *) calloc(1, sizeof(Node));
    if (node == nullptr)
        return nullptr;

    node->next = next;

    node->value = calloc(1, elem_size);
    if (node->value == nullptr)
    {
        free(node);
        return nullptr;
    }

    memcpy(node->value, value, elem_size);

    return node;
}

List *listCtor(size_t elem_size)
{
    List *list = (List *) calloc(1, sizeof(list[0]));
    if (list == nullptr)
        return nullptr;

    list->data = nullptr;
    list->elem_size = elem_size;
    return list;
}

void listDtor(List *list)
{
    if (list->data == nullptr)
    {
        list->elem_size = 0;
        return;
    }

    Node *current_node = list->data;
    Node *next_node = current_node->next;
    while (next_node != nullptr)
    {
        free(current_node->value);
        free(current_node);
        current_node = next_node;
        next_node = current_node->next;
    }
}

int listPush(List *list, void *buffer)
{
    if (list->data == nullptr)
    {
        list->data = nodeCtor(buffer, list->elem_size, nullptr);
        if (list->data == nullptr)
            return 0;
    }

    list->data = nodeCtor(buffer, list->elem_size, list->data);
    return 1;
}

int listTop(List *list, void *buffer)
{
    if (list->data == nullptr)
        return 0;

    memcpy(buffer, list->data->value, list->elem_size);
    list->data = list->data->next;
    return 1;
}

int listPop(List *list)
{
    if (list->data == nullptr)
        return 0;

    list->data = list->data->next;
    return 1;
}
