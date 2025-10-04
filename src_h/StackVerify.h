#ifndef STACK_VERIFY_H
#define STACK_VERIFY_H
#include "../src_h/Stack.h"
#define StackVerify(stk) IsStackCorrect(stk, __FILE__, __LINE__, __FUNCTION__);

typedef enum
{
    NO_ERRORS = 0,
    STACK_POINTER_IS_NULL = -1,
    NEGATIVE_SIZE = 1,
    NEGATIVE_CAPACITY = 2,
    STACK_IS_FULL = 4,
    DATA_POINTER_IS_NULL = 8,
    BEGIN_CANARY_DIED = 16,
    END_CANARY_DIED = 32
}ErrCode;

int StackDump(stack* stk, int er, const char* filename, const int linen, const char* funcname);
int IsStackCorrect(stack* stk, const char* filename, const int linen, const char* funcname);
int ErrorPrint(stack* stk, int er);
int StackPrint(stack* stk);
int ErrorPos(const char* filename, const int linen, const char* funcname);
int CanaryCheck(stack* stk, int* er);

#endif //STACK_VERIFY_H
