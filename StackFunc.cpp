#include "StackFunc.h"


int StackPush(stack* stk, int a)
{
    StackCheck(stk)

    if(stk->capacity < stk->size)
    {
        *(stk->data + stk->capacity) = a;
        stk->capacity++;
        return 0;
    }
    else
    {
        //printf("stack is full\n");  //realloc
        return 3;
    }
    StackCheck(stk)
}

int StackPop(stack* stk)
{
    StackCheck(stk)
    char c = *(stk->data + stk->capacity - 1);
    stk->capacity--;
    StackCheck(stk)
    return c;
}
