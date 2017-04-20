#ifndef __CSV_H__
#define __CSV_H__

/********************************/
/********* COMPANY **************/
/********************************/

typedef struct company {

        char* CNPJ;
        char* registerDate;
        char* cancelDate;
        char* CNPJaudit;
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
void printCSV(CSV* csv); // prints csv contents
void deleteCSV(CSV* csv); // frees csv memory

#endif
