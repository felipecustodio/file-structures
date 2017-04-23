/********************************
*
*       SCC0215 - ORGANIZAÇÃO DE ARQUIVOS
*       TRABALHO 01
*
*
*
********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/csv.h"
#include "../includes/files.h"

/********************************/
/*********** DEFINES ************/
/********************************/

#define DELIM ';'

/********************************/
/************* UTILS ************/
/********************************/

// READ STRING FROM FILE STREAM
char* readfString(FILE* fp, char end) {
	char* string = NULL;
	char value = '@';
	int counter = 0;

	// READ UNTIL DELIMITER
	while (value != end) {
		fscanf(fp, "%c", &value);
		string = (char*)realloc(string, sizeof(char) * counter + 1);
		string[counter] = value;
		counter++;
	}

	string[counter-1] = '\0';
	return string;
}

/********************************/
/************* FILES ************/
/********************************/

CSV* readCSV(FILE* input) {

	char buffer;
	// CREATE CSV STRUCTURE
        CSV* csv = newCSV();

        do {

		// CREATE NEW COMPANY
		csv->companies = (COMPANY**)realloc(csv->companies, sizeof(COMPANY*) * csv->size + 1);
		csv->companies[csv->size] = (COMPANY*)malloc(sizeof(COMPANY));

		// READ DATA
		csv->companies[csv->size]->CNPJ = readfString(input, DELIM);
		csv->companies[csv->size]->socialName = readfString(input, DELIM);
		csv->companies[csv->size]->fantasyName = readfString(input, DELIM);
		csv->companies[csv->size]->registerDate = readfString(input, DELIM);
		csv->companies[csv->size]->cancelDate = readfString(input, DELIM);
		csv->companies[csv->size]->reason = readfString(input, DELIM);
		csv->companies[csv->size]->companyName = readfString(input, DELIM);
		// LAST VALUE ENDS ON NEWLINE
		csv->companies[csv->size]->CNPJaudit = readfString(input, '\n');
		csv->size += 1;

		// CHECK FOR END OF FILE
		buffer = fgetc(input);
		if (buffer != EOF) {
			// IF NEXT CHAR ISN'T EOF
			// GO BACK 1 BYTE
			fseek(input, -1, SEEK_CUR);
		}

        } while(!feof(input));

        return csv;
}

/********************************/
/************* WRITING **********/
/********************************/

void writeString(FILE* output, char* string) {
	fwrite(string, strlen(string), 1, output);
}

void writeInt(FILE* output, int number) {
	fprintf(output, "%d", number);

}

void writeFile(CSV* csv, FILE* output) {

	int i;

	char* delimiter = (char*)malloc(sizeof(char) * 1);
	delimiter[0] = '|';

	char* separator = (char*)malloc(sizeof(char) * 1);
	separator[0] = '\\';

	// WRITE NUMBER OF REGISTRIES
	writeInt(output, csv->size);
	writeString(output, delimiter); // field delimiter

	for (i = 0; i < csv->size; i++) {

		// CNPJ - Fixed
		writeString(output, csv->companies[i]->CNPJ);
		writeString(output, delimiter); // field delimiter

	        // socialName - Variable
	        writeInt(output, strlen(csv->companies[i]->socialName)); // field size
		writeString(output, csv->companies[i]->socialName);
		writeString(output, delimiter); // field delimiter

	        // fantasyName - Variable
		writeInt(output, strlen(csv->companies[i]->fantasyName)); // field size
		writeString(output, csv->companies[i]->fantasyName);
		writeString(output, delimiter); // field delimiter

	        // registerDate - Fixed
		writeString(output, csv->companies[i]->registerDate);
		writeString(output, delimiter); // field delimiter

	        // cancelDate - Fixed
		writeString(output, csv->companies[i]->cancelDate);
		writeString(output, delimiter); // field delimiter

	        // reason - Variable
	        writeInt(output, strlen(csv->companies[i]->reason)); // field size
		writeString(output, csv->companies[i]->reason);
		writeString(output, delimiter); // field delimiter

	        // companyName - Variable
	        writeInt(output, strlen(csv->companies[i]->companyName)); // field size
		writeString(output, csv->companies[i]->companyName);
		writeString(output, delimiter); // field delimiter

	        // CNPJaudit - Fixed
		writeString(output, csv->companies[i]->CNPJaudit);

		// End of registry
		writeString(output, separator);

	}
}

/********************************/
/************* READING **********/
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
