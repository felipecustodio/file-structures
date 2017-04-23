/********************************
*
*       SCC0215 - ORGANIZAÇÃO DE ARQUIVOS
*       TRABALHO 01
*
*
*
********************************/

#ifndef __FILES_H__
#define __FILES_H__

#include <stdio.h>
#include "csv.h"

/********************************/
/************* FILES ************/
/********************************/

CSV* readCSV(FILE* input);

/********************************/
/********** WRITING *************/
/********************************/

void writeString(FILE* output, char* string);
void writeInt(FILE* output, int number);
void writeFile(CSV* csv, FILE* output);

/********************************/
/********** READING *************/
/********************************/

void readFixedField(FILE* output);
void readVariableField(FILE* output);

/********************************/
/************ SEARCH ************/
/********************************/

void searchRRN(FILE* output);
void searchField(FILE* output, int field);

/********************************/
/*********** REMOVAL ************/
/********************************/

void removeRRN(FILE* output);
void removeField(FILE* output, int field);

/********************************/
/********** COMPACT *************/
/********************************/

void compacter(FILE* output);

#endif
