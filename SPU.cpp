#include "translator.h"
#include "LanguageCode.h"
#include "ByteCode.h"

int main(int argc, char* argv)
{
    if(argc >= 3)
    {
        if(argv[1] == "--language")
        {
            LanguageCode(argv[2]);
        }
        if(argv[1] == "--byte")
        {
            ByteCode(argv[2]);
        }
        if(argv[1] == "--translator")
        {
            Translator(argv[2], argv[3]);
        }
    }
}
