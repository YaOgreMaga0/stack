#include "Stack.h"

int StackDump(stack* stk, int ercode, const char* FileName, const int LineN, const char* FuncName)
{
    ErrorPos(FileName, LineN, FuncName);
    ErrorPrint(stk, ercode);
    StackPrint(stk);
}

int StackVerifier(stack* stk, const char* FileName, const int LineN, const char* FuncName)
{
    int ercode = NO_ERRORS;
    if(stk == NULL)
    {
        ercode = STACK_POINTER_IS_NULL;
        StackDump(stk, ercode, FileName, LineN, FuncName);
        return ercode;
    }
    if(stk->size <= 0)
        ercode += NEGATIVE_SIZE;
    if(stk->capacity < 0)
        ercode += NEGATIVE_CAPACITY;
    if(stk->data == NULL)
        ercode += DATA_POINTER_IS_NULL;
    if((stk->capacity) > (stk->size))
    {
        ercode += STACK_IS_FULL;
        StackDump(stk, ercode, FileName, LineN, FuncName);
        return ercode;
    }
    #ifdef WITHCANARY
    CanaryCheck(stk, &er);
    #endif //WITHCANARY
    if(ercode != 0)
        StackDump(stk, ercode, FileName, LineN, FuncName);
    return ercode;
}

int ErrorPrint(stack* stk, int ercode)
{
    if(ercode != 0)
    {
        fprintf(stderr, "\n!ERROR!\n");
        if(ercode == STACK_POINTER_IS_NULL)
        {
            fprintf(stderr,"stack pointer is NULL\n");
            return STACK_POINTER_IS_NULL;
        }
        if(ercode & NEGATIVE_SIZE)
            fprintf(stderr, "size is not a positive integer(1)\n");
        if(ercode & NEGATIVE_CAPACITY)
            fprintf(stderr, "capacity is not a positive integer(2)\n");
        if(ercode & STACK_IS_FULL)
            fprintf(stderr, "capacity is greater than size(3)\n");
        if(ercode & DATA_POINTER_IS_NULL)
            fprintf(stderr, "data pointer is NULL(4)\n");
        if(ercode & BEGIN_CANARY_DIED)
            fprintf(stderr, "begin canary died(5)\n");
        if(ercode & END_CANARY_DIED)
            fprintf(stderr, "end canary died(6)\n");
        if(ercode & HASH_ERROR)
            fprintf(stderr, "hash error(7)\n");
    }
    return ercode;
}

int StackPrint(stack* stk)
{
    fprintf(stderr, "stack <%s>[%x]\n",type_name, stk);
    fprintf(stderr, "{\n    size = %d\n", stk->size);
    fprintf(stderr, "    capacity = %d\n", stk->capacity);
    fprintf(stderr, "data[%x]\n{\n", stk->data);
    for(int i = 1; i <= stk->capacity; i++)
    {
        fprintf(stderr, "[%d] = %d", i, stk->data[i + canary_size]);
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "}\n}\n\n");
    return 0;
}

int ErrorPos(const char* FileName, const int LineN, const char* FuncName)
{
    fprintf(stderr, "In file %s\n", FileName);
    fprintf(stderr, "Line: %d\n", LineN);
    fprintf(stderr, "Function:%s\n", FuncName);
    return 0;
}

#ifdef WITHCANARY
int CanaryCheck(stack* stk, int* er)
{
    if(*stk->data != canary_value)
        *ercode += BEGIN_CANARY_DIED;
    if(*(stk->data + stk->size + 1) != canary_value)
        *ercode += END_CANARY_DIED;
}
#endif //WITHCANARY

#ifdef WITHHASH
int CheckHash(stack* stk)
 {
    if(GetHash(stk) != stk->hash)
        return HASH_ERROR;
    return 0;
}
#endif //WITHHASH
