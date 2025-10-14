#include "StackFunc.h"

int main()
{
    stack stk = {};
    StackCtor(&stk, 10);


    StackDtor(&stk);
    return 0;
}
