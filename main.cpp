#include <stdio.h>
#include "StackFunc.h"

int main()
{
    int a = 0;
    stack stk = {};
    StackCtor(&stk, 2);
    for(int i = 0; i < 2; i++)
        a = StackPush(&stk, i + 1);
    for(int i = 0; i < 3; i++)
        StackPop(&stk);
    StackDtor(&stk);
    return 0;
}
