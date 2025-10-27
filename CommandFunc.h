#ifndef CALCFUNC_H
#define CALCFUNC_H

#include <string.h>
#include <stdio.h>
#include "Stack.h"

typedef enum
{
    PUSH = 1,
    OUT = 2,
    ADD = 3,
    SUB = 4,
    MUL = 5,
    DIV = 6,
    HLT = 0
}command;

const char* CommandCodes[] = {"HLT", "PUSH", "OUT", "ADD", "SUB", "MUL", "DIV"};

int CommandSwitch(int comm, stack* stk);
void push(stack* stk);
void out(stack* stk);
void add(stack* stk);
void sub(stack* stk);
void mul(stack* stk);
void div(stack* stk);
int GetCommand();

#endif //CALCFUNC_H
