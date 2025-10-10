#include "CalcFunc.h"

void PUSH(stack* stk, FILE* fp)
{
    stack_type arg = 0;
    fscanf(fp, "%d", &arg);
    StackPush(stk, arg);
}

void OUT(stack* stk)
{
    stack_type value = StackPop(stk);
    printf("%d ", value);
}

void ADD(stack* stk)
{
    stack_type value1 = StackPop(stk);
    stack_type value2 = StackPop(stk);
    StackPush(stk, value1 + value2);
}

void SUB(stack* stk)
{
    stack_type value1 = StackPop(stk);
    stack_type value2 = StackPop(stk);
    StackPush(stk, value1 - value2);
}

void MUL(stack* stk)
{
    stack_type value1 = StackPop(stk);
    stack_type value2 = StackPop(stk);
    StackPush(stk, value1 * value2);
}

void DIV(stack* stk)
{
    stack_type value1 = StackPop(stk);
    stack_type value2 = StackPop(stk);
    StackPush(stk, value1 / value2);
}

char* GetCommand(FILE* fp)
{
    char* command = (char*)calloc(10, sizeof(char));
    fscanf(fp, "%s", command);
    return command;
}

void CommSwitch(char* comm, stack* stk, FILE* fp)
{
    if(strncmp(comm, "PUSH", 4) == 0)
        PUSH(stk, fp);
    if(strncmp(comm, "OUT", 3) == 0)
        OUT(stk);
    if(strncmp(comm, "ADD", 3) == 0)
        ADD(stk);
    if(strncmp(comm, "SUB", 3) == 0)
        SUB(stk);
    if(strncmp(comm, "MUL", 3) == 0)
        MUL(stk);
    if(strncmp(comm, "DIV", 3) == 0)
        DIV(stk);
}
