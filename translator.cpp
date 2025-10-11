#include <stdio.h>
#include <string.h>

void Translator(char* filenamein, char* filenameout);

void Translator(char* filenamein, char* filenameout)
{
    FILE* in = fopen(filenamein, "rb");
    FILE* out = fopen(filenameout, "wb");

}
