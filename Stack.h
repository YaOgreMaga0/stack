#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define StackDump(stk, errcode) StkDmp(stk, errcode, __FILE__, __LINE__, __FUNCTION__)
#define StackCheck(stk) IsStackCorrect(stk);
/*typedef enum type_t
{
    char,
    int
};*/

typedef struct stack_t
{
    int* data;
    int size;
    int capacity;
    //type tp;
}stack;

int StackCtor(stack* stk, int size);
int StackDtor(stack* stk);
int StkDmp(stack* stk, int errcode, const char* filename, const int linen, const char* funcname);
int IsStackCorrect(stack* stk);
#endif //STACK_H
