#include "CommandFunc.h"

void push(stack* stk)
{
    int ToPush = 0;
    scanf("%d", &ToPush);
    StackPush(stk, ToPush);
}

void out(stack* stk)
{
    stack_type value = StackPop(stk);
    printf("%d ", value);
}

void add(stack* stk)
{
    stack_type value1 = StackPop(stk);
    stack_type value2 = StackPop(stk);
    StackPush(stk, value1 + value2);
}

void sub(stack* stk)
{
    stack_type value1 = StackPop(stk);
    stack_type value2 = StackPop(stk);
    StackPush(stk, value1 - value2);
}

void mul(stack* stk)
{
    stack_type value1 = StackPop(stk);
    stack_type value2 = StackPop(stk);
    StackPush(stk, value1 * value2);
}

void div(stack* stk)
{
    stack_type value1 = StackPop(stk);
    stack_type value2 = StackPop(stk);
    StackPush(stk, value1 / value2);
}

int CommandSwitch(int command, stack* stk)
{
    switch(command)
    {
        case PUSH:
            push(stk);
            break;
        case OUT:
            out(stk);
            break;
        case ADD:
            add(stk);
            break;
        case SUB:
            sub(stk);
            break;
        case MUL:
            mul(stk);
            break;
        case DIV:
            div(stk);
            break;
        case HLT:
            break;
        default:
            fprintf(stderr, "unknown command\n");
            return HLT;
    }
    return command;
}

int GetCommand()
{
    char command[5] = "";
    scanf("%s", command);
    for(int i = 0; i < 8; i++)
    {
        if(strcmp(command, CommandCodes[i]) == 0)
            return i;
    }
    return -1;
}
