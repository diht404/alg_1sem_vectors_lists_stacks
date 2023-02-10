#include "list.h"

int main()
{
    List *list = listCtor(sizeof(int));
    for (int i = 0; i < 100; i++)
    {
        listPush(list, (void *) &i);
    }
    for (int i = 0; i < 100; i++)
    {
        int value = 0;
        int error_code = listTop(list, (void *) &value);
        printf("i = %d, value = %d, POP status: %s\n",
               i,
               value,
               error_code ? "Correct" : "Can't pop");
    }

    for (int i = 0; i < 100; i++)
    {
        listPush(list, (void *) &i);
    }
    for (int i = 0; i < 100; i++)
    {
        int error_code = listPop(list);
        printf("i = %d, POP status: %s\n",
               i,
               error_code ? "Correct" : "Can't pop");
    }
    for (int i = 0; i < 100; i++)
    {
        int error_code = listPop(list);
        printf("i = %d, POP status: %s\n",
               i,
               error_code ? "Correct" : "Can't pop");
    }
    listDtor(list);

    return 0;
}
