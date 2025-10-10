#ifndef CALCFUNC_H
#define CALCFUNC_H

#include <string.h>
#include <stdio.h>
#include "Stack.h"

char* GetCommand(FILE* fp);
void PUSH(stack*stk, FILE* fp);
void OUT(stack* stk);
void ADD(stack* stk);
void SUB(stack* stk);
void MUL(stack* stk);
void DIV(stack* stk);
void CommSwitch(char* comm, stack* stk, FILE* fp);


#endif //CALCFUNC_H
