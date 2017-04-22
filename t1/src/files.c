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

CSV* readFile(FILE* input) {

	// CREATE CSV STRUCTURE
        CSV* csv = newCSV();

        while(!feof(input)) {

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

		printCompany(csv->companies[csv->size]);

		csv->size += 1;
        }
	
	printf("REACHED END OF FILE\n");
        return csv;
}

void writeFile(CSV* csv, FILE* output) {

}
