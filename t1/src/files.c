#include <stdio.h>
#include <stdlib.h>
#include "../includes/csv.h"
#include "../includes/files.h"

/********************************/
/*********** DEFINES ************/
/********************************/

#define DELIM ';'

/********************************/
/************* UTILS ************/
/********************************/

/* read string from file */
char* readfString(FILE* fp, char end) {
	char* string = NULL;
	char value = '@';
	int counter = 0;

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

CSV* readFile(FILE* input) {

        CSV* csv = newCSV();

        // TODO: create companies

        while(!feof(input)) {

        }

        return csv;
}

void writeFile(CSV* csv, FILE* output) {

}
