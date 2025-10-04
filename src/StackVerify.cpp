#include "../src_h/StackVerify.h"

int StackDump(stack* stk, int er, const char* filename, const int linen, const char* funcname)
{
    ErrorPos(filename, linen, funcname); //ded сказал что можно здесь еще расписать имя файла, функции, линию и т.д., сказал опциональное задание, так что пока оставлю так
    ErrorPrint(stk, er);
    StackPrint(stk);
}

int IsStackCorrect(stack* stk, const char* filename, const int linen, const char* funcname)
{
    int er = NO_ERRORS;
    if(stk == NULL)
    {
        er = STACK_POINTER_IS_NULL;
        StackDump(stk, er, filename, linen, funcname);
        return er;
    }
    if(stk->size <= 0)
        er += NEGATIVE_SIZE;
    if(stk->capacity <= 0)
        er += NEGATIVE_CAPACITY;
    if((stk->capacity) > (stk->size))
        er += STACK_IS_FULL;
    if(stk->data == NULL)
        er += DATA_POINTER_IS_NULL;
    CanaryCheck(stk, &er);
    if(er != 0)
        StackDump(stk, er, filename, linen, funcname);
    return er;
}

int ErrorPrint(stack* stk, int er)
{
    if(er != 0)
    {
        fprintf(stderr, "\n!ERROR!\n");
        if(er == STACK_POINTER_IS_NULL)
            fprintf(stderr,"stack pointer is NULL\n");
        if(er & NEGATIVE_SIZE == 1)
            fprintf(stderr, "size is not a positive integer(1)\n");
        if(er & NEGATIVE_CAPACITY == 1)
            fprintf(stderr, "capacity is not a positive integer(2)\n");
        if(er & STACK_IS_FULL == 1)
            fprintf(stderr, "capacity is greater than size(3)\n");
        if(er & DATA_POINTER_IS_NULL == 1)
            fprintf(stderr, "data pointer is NULL(4)\n");
        if(er & BEGIN_CANARY_DIED == 1)
            fprintf(stderr, "begin canary died(5)\n");
        if(er & END_CANARY_DIED == 1)
            fprintf(stderr, "begin canary died(6)\n");
    }
    return 0;
}

int StackPrint(stack* stk)
{
    fprintf(stderr, "stack <%s>[%x]\n",type_name, stk);
    fprintf(stderr, "{\n    size = %d\n", stk->size);
    fprintf(stderr, "    capacity = %d\n", stk->capacity);
    fprintf(stderr, "data[%x]\n{\n", stk->data);
    for(int i = 1; i <= stk->size; i++)
    {
        fprintf(stderr, "[%d] = %d", i, stk->data[i]);
        if(stk->data[i] == 666)
            fprintf(stderr, "(poison))");
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "}\n}\n");
    return 0;
}

int ErrorPos(const char* filename, const int linen, const char* funcname)
{
    printf("In file %s\n", filename);
    printf("Line: %d\n", linen);
    printf("Function:%s\n", funcname);
    return 0;
}

int CanaryCheck(stack* stk, int* er)
{
    if(*stk->data != canary_value)
        *er += BEGIN_CANARY_DIED;
    if(*(stk->data + stk->size + 1) != canary_value)
        *er += END_CANARY_DIED;
}
