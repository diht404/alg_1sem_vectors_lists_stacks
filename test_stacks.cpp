#include "stdlib.h"

int main()
{
    system("cmake --build . --target stackVectorTest");
    system("cmake --build . --target stackListTest");

    system("echo Testing vector-based stack...");
    system("./stackVectorTest");

    system("echo Testing list-based stack...");
    system("./stackListTest");
    return 0;
}