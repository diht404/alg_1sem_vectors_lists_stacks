#include "stack_test.h"

double test1(Stack *stack)
{
    push1e6(stack);

    timeval start_time = {};
    gettimeofday(&start_time, NULL);

    test_iter9(stack);

    timeval end_time = {};
    gettimeofday(&end_time, NULL);

    return 1e6 * (end_time.tv_sec - start_time.tv_sec) +
        end_time.tv_usec - start_time.tv_usec;
}

double test2(Stack *stack)
{
    push1e6(stack);

    timeval start_time = {};
    gettimeofday(&start_time, NULL);

    test_repeat100(stack);
    test_iter9(stack);
    test_iter9(stack);

    timeval end_time = {};
    gettimeofday(&end_time, NULL);

    return 1e6 * (end_time.tv_sec - start_time.tv_sec) +
        end_time.tv_usec - start_time.tv_usec;
}

double test3(Stack *stack)
{
    push1e6(stack);

    timeval start_time = {};
    gettimeofday(&start_time, NULL);

    test_random_push_pop(stack);

    timeval end_time = {};
    gettimeofday(&end_time, NULL);

    return 1e6 * (end_time.tv_sec - start_time.tv_sec) +
        end_time.tv_usec - start_time.tv_usec;
}

void push1e6(Stack *stack)
{
    int elem_number = 1e6;

    for (int i = 0; i < elem_number; i++)
    {
        stackPush(stack, (void *) &i);
    }
}

void test_iter9(Stack *stack)
{
    int elem_number = 1e6;
    int num_delete = elem_number / 2;
    int num_push = elem_number / 4;
    do
    {
        for (int i = 0; i < num_delete; i++)
        {
            stackPop(stack);
        }
        for (int i = 0; i < num_push; i++)
        {
            stackPush(stack, (void *) &i);
        }
        elem_number = elem_number - num_delete + num_push;
        num_delete = elem_number / 2;
        num_push = elem_number / 4;
    }
    while (elem_number > 1e5);
}

void test_repeat100(Stack *stack)
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 1e4; j++)
        {
            stackPop(stack);
        }
        for (int j = 0; j < 1e4; j++)
        {
            stackPush(stack, (void *) &j);
        }
    }
}

void test_random_push_pop(Stack *stack)
{
    for (int i = 0; i < 1e6; i++)
    {
        int rand_value = rand() % 2 + 1; // randint [1, 2]
        if (rand_value == 1)
        {
            stackPush(stack, (void *) &i);
        }
        else
        {
            stackPop(stack);
        }
    }
}

int main()
{
    double test1time = 0;
    double test2time = 0;
    double test3time = 0;
    for (int i = 0; i < 10; i++)
    {
        Stack *stack1 = stack_ctr(1, sizeof(int));
        test1time += test1(stack1);
        stack_dtr(stack1);

        Stack *stack2 = stack_ctr(1, sizeof(int));
        test2time += test2(stack2);
        stack_dtr(stack2);

        Stack *stack3 = stack_ctr(1, sizeof(int));
        test3time += test3(stack3);
        stack_dtr(stack3);
    }

    printf("Tests mean execution time:\n");
    printf("Test 1 mean execution time: %lg ms\n", test1time / 10 / 1e3);
    printf("Test 2 mean execution time: %lg ms\n", test2time / 10 / 1e3);
    printf("Test 3 mean execution time: %lg ms\n", test3time / 10 / 1e3);

    return 0;
}