#include "../src_h/ByteCode.h"

int ByteCode(char* filename)
{
    stack stk = {};
    StackCtor(&stk, 10);
    FILE* fp = fopen(filename, "rb");
    while(true)
    {
        int command = GetByte(fp);
        if(command == HLT)
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


int GetByte(FILE* fp)
{
    int command = 0;
    fscanf(fp, "%d", command);
    return command;
}
