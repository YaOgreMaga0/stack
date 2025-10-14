#include "../src_h/translator.h"

int Translator(char* filenamein, char* filenameout)
{
    BufAndIndexInf Inf = FileReadAndMakeBuf(filenamein);

    if(Inf.buf == NULL || Inf.CntLines == -1 || Inf.index == NULL)
    {
        fprintf(stderr, "incorrect input file\n");
        MemoryFree(&Inf);
        return 1;
    }



    if(FillByteOutput(Inf.index, filenameout, Inf.CntLines) == 1)
    {
        printf("incorrect output file\n");
        MemoryFree(&Inf);
        return 1;
    }

    MemoryFree(&Inf);
    return 0;
}

int FillByteOutput(struct Line* index, const char* filename, int  len)
{
    assert(index != NULL);
    assert(filename != NULL);
    assert(len > 0);

    FILE* outfile = fopen(filename, "w");
    if(outfile == NULL)
    {
        fprintf(stderr, "Error file open\n");
        return 1;
    }

    for(int i = 0; i < len; i++)
    {
        const int len = index[i].len;
        const char* string = index[i].string;
        fputs(string, outfile);
    }
    fclose(outfile);
    return 0;
}
