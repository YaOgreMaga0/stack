#include "LanguageCode.h"

void LanguageCode(char* filename)
{
    stack stk = {};
    StackCtor(&stk, 10);
    FILE* fp = fopen(filename, "rb");
    while(true)
    {
        char* command = GetCommand(fp);
        if(strncmp(command, "HLT", 3) == 0)
        {
            fclose(fp);
            StackDtor(&stk);
            return 0;
        }
        CommSwitch(command, &stk, fp);
    }
    fclose(fp);
    StackDtor(&stk);
    return 1;
}
