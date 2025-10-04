#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

const char type_name[7] = "int";
typedef int stack_type;
const stack_type canary_value = pow(2,32) - 1;

typedef struct
{
    stack_type* data;
    int size;
    int capacity;
}stack;

int StackCtor(stack* stk, int size);
int StackDtor(stack* stk);
int StackPush(stack* stk, stack_type c);
stack_type StackPop(stack* stk);
int MakeCanary(stack* stk);

#endif //STACK_H
