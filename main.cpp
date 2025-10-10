#define WITHCANARY
#define WITHHASH

#include "Stack.h"

int main()
{
    stack stk = {};
    StackCtor(&stk, 2);
    for(int i = 0; i < 10; i++)
        StackPush(&stk, i);
    for(int i = 0; i < 10; i++)
       printf("%d %d \n",i , StackPop(&stk));
    StackDtor(&stk);
    return 0;
}
