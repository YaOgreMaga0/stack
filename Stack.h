#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

const char type_name[7] = "int";
typedef int stack_type;

#ifdef WITHCANARY
const int canary_value = 52;
const int canary_size = 4;
#else
const int canary_size = 0;
#endif //WITHCANARY

typedef struct
{
    stack_type* data;
    int size;
    int capacity;
    #ifdef WITHHASH
    long long int hash;
    #endif //WITHHASH
}stack;

int StackCtor(stack* stk, int size);
int StackDtor(stack* stk);
int StackPush(stack* stk, stack_type c);
stack_type StackPop(stack* stk);

#ifdef WITHCANARY
int MakeCanary(stack* stk);
#endif //WITHCANARY

#endif //STACK_H
