#include "vector.h"

int main()
{
    Vector *vector = vectorCtor(1, sizeof(int));
    for (int i = 0; i < 100; i++)
    {
        vectorPush(vector, (void *) &i);
    }
    for (int i = 0; i < 100; i++)
    {
        int value = 0;
        int error_code = vectorTop(vector, (void *) &value);
        printf("i = %d, value = %d, POP status: %s\n",
               i,
               value,
               error_code ? "Correct" : "Can't pop");
    }

    for (int i = 0; i < 100; i++)
    {
        vectorPush(vector, (void *) &i);
    }
    for (int i = 0; i < 100; i++)
    {
        int error_code = vectorPop(vector);
        printf("i = %d, POP status: %s\n",
               i,
               error_code ? "Correct" : "Can't pop");
    }
    for (int i = 0; i < 100; i++)
    {
        int error_code = vectorPop(vector);
        printf("i = %d, POP status: %s\n",
               i,
               error_code ? "Correct" : "Can't pop");
    }
    vectorDtor(vector);

    return 0;
}
