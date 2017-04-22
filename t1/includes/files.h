#ifndef __FILES_H__
#define __FILES_H__

#include <stdio.h>
#include "csv.h"

/********************************/
/************* FILES ************/
/********************************/

CSV* readCSV(FILE* input);
void writeString(FILE* output, char* string);
void writeFile(CSV* csv, FILE* output);

#endif
