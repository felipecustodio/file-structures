#ifndef __FILES_H__
#define __FILES_H__

#include <stdio.h>
#include "csv.h"

/********************************/
/************* FILES ************/
/********************************/

CSV* readFile(FILE* input);
void writeFile(CSV* csv, FILE* output);

#endif
