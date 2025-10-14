#include "../src_h/LanguageCode.h"

int LanguageCode(char* filename)
{
    stack stk = {};
    StackCtor(&stk, 10);
    FILE* fp = fopen(filename, "rb");
    while(true)
    {
        int command = GetCommand(fp);
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


int GetCommand(FILE* fp)
{
    char* command = (char*)calloc(10, sizeof(char));
    fscanf(fp, "%s", command);
    fprintf(stderr, "%s\n", command);
    if(strncmp(command, "PUSH", 4) == 0 )
        return PUSH;
    if(strncmp(command, "OUT", 3) == 0 )
        return OUT;
    if(strncmp(command, "ADD", 3) == 0 )
        return ADD;
    if(strncmp(command, "SUB", 3) == 0 )
        return SUB;
    if(strncmp(command, "MUL", 3) == 0 )
        return MUL;
    if(strncmp(command, "DIV", 3) == 0 )
        return DIV;
    if(strncmp(command, "HLT", 3) == 0 )
        return HLT;
}
