#include "CommandFunc.h"
#define WITHCANARY
#define WITHHASH

int main()
{
    stack stk = {};
    StackCtor(&stk, stack_size);
    while(true)
    {
        if(CommandSwitch(GetCommand(), &stk) == HLT)
            return 0;
    }
    StackDtor(&stk);
    return 1;
}
