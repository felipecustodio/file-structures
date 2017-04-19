#ifndef __CSV_H__
#define __CSV_H__

/********************************/
/********* COMPANY **************/
/********************************/

typedef struct company {

        int CNPJ;
        int registerDate;
        int cancelDate;
        int CNPJaudit;
        char* socialName;
        char* fantasyName;
        char* reason;
        char* companyName;

} COMPANY;

COMPANY* newCompany(); // allocates memory for new company
void printCompany(COMPANY* company); // print company data
void deleteCompany(COMPANY* company); // frees company memory


/********************************/
/********* CSV ******************/
/********************************/

typedef struct csv {

        int size;
        COMPANY** companies;

} CSV;

CSV* newCSV(); // allocates memory for new csv
CSV* readCSV(FILE* file, char delim); // read CSV contents from file
void printCSV(CSV* csv); // prints csv contents
void deleteCSV(CSV* csv); // frees csv memory

#endif
