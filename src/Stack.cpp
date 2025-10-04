#include "../src_h/StackVerify.h"
#include "../src_h/Stack.h"

int StackCtor(stack* stk, int size)
{
    if(stk == NULL)
        return STACK_POINTER_IS_NULL;
    if(size <= 0)
        return NEGATIVE_SIZE;
    stk->size = size;
    stk->capacity = 0;
    stk->data = (int*)calloc(size + 2, sizeof(stack_type));
    MakeCanary(stk);
    return 0;
}

int StackDtor(stack* stk)
{
    if(stk == NULL)
        return STACK_POINTER_IS_NULL;
    stk->capacity = -1;
    stk->size = -1;
    free(stk->data);
    stk->data == NULL;
    return 0;
}

int StackPush(stack* stk, stack_type a)
{
    if(stk->capacity < stk->size)
    {
        *(stk->data + stk->capacity + 1) = a;
        stk->capacity++;
        return 0;
    }
    else
    {
        return STACK_IS_FULL; //realoc
    }

    StackVerify(stk)
}

int StackPop(stack* stk)
{
    StackVerify(stk)
    char c = *(stk->data + stk->capacity);
    *(stk->data + stk->capacity - 2) = 0;
    stk->capacity--;
    return c;
}

int MakeCanary(stack* stk)
{
    *stk->data = canary_value;
    *(stk->data + stk->size + 1) = canary_value;
}
