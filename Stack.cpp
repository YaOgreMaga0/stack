#include "Stack.h"

int StackCtor(stack* stk, int size)
{
    assert(stk != NULL);
    if(size <= 0)
    {
        fprintf(stderr, "incorrect stack size\n");
        return 0;
    }
    stk->size = size;
    stk->data = (int*)calloc(size, sizeof(int));
    return 0;
}

int StackDtor(stack* stk)
{
    assert(stk != NULL);
    stk->capacity = 0;
    stk->size = 0;
    free(stk->data);
    stk->data == NULL;
    stk == NULL;
    return 0;
}

/*
errcodes:
-1 - stack pointer is NULL;
1 - size is not a positive integer;
2 - capacity is not a positive integer;
3 - capacity is greater than size;
4 - data pointer is NULL;
5 - no begin canary;
6 - no end canary;
*/


int StkDmp(stack* stk, int errcode, const char* filename, const int linen, const char* funcname)
{
    //ded сказал что можно здесь еще расписать имя файла, функции, линию и т.д., сказал опциональное задание, так что пока оставлю так
    if(errcode != 0 || stk == NULL) //позже заменю на функцию распечатывающую эрркоды
    {
        fprintf(stderr, "\n!ERROR!\n");
        if(errcode == -1)
            fprintf(stderr,"stack pointer is NULL\n");
        if(errcode % 2 == 1)
            fprintf(stderr, "size is not a positive integer(1)\n");
        errcode /= 2;
        if(errcode % 2 == 1)
            fprintf(stderr, "capacity is not a positive integer(2)\n");
        errcode /= 2;
        if(errcode % 2 == 1)
            fprintf(stderr, "capacity is greater than size(3)\n");
        errcode /= 2;
        if(errcode % 2 == 1)
            fprintf(stderr, "data pointer is NULL(4)\n");
    }
    fprintf(stderr, "stack <>[%x]\n"/*, stk->tp*/, stk);  //stack<type>[pointer] //так же можно заменить на функцию распечатыващую состав стека, так же сделаю позже)
    fprintf(stderr, "{\n    size = %d\n", stk->size);  //size
    fprintf(stderr, "    capacity = %d\n", stk->capacity);  //capacity
    fprintf(stderr, "data[%x]\n{\n", stk->data); //data pointer
    for(int i = 0; i < stk->size; i++) //print data members
    {
        fprintf(stderr, "[%d] = %d", i, stk->data[i]);
        if(stk->data[i] == 666)
            fprintf(stderr, "(poison))");
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "}\n}\n"); //print end
}

/*
errcodes:
-1 - stack pointer is NULL;
1 - size is not a positive integer;
2 - capacity is not a positive integer;
3 - capacity is greater than size;
4 - data pointer is NULL;
5 - no begin canary;
6 - no end canary;
*/

int IsStackCorrect(stack* stk)
{
    int errcode = 0;
    if(stk == NULL)
    {
        errcode = -1;
        StackDump(stk, errcode);
        return -1;
    }
    if(stk->size <= 0)
        errcode += 1;
    if(stk->capacity < 0)
        errcode += 2;
    if((stk->capacity) > (stk->size))
        errcode += 4;
    if(stk->data == NULL)
        errcode += 8;
    if(errcode != 0)
        StackDump(stk, errcode);
    return errcode;
}
