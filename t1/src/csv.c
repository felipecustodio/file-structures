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
#include "../includes/csv.h"

/********************************/
/********* COMPANY **************/
/********************************/

COMPANY* newCompany() {
        COMPANY* company = (COMPANY*)malloc(sizeof(COMPANY));
        company->CNPJ = NULL;
        company->registerDate = NULL;
        company->cancelDate = NULL;
        company->CNPJaudit = NULL;
        company->socialName = NULL;
        company->fantasyName = NULL;
        company->reason = NULL;
        company->companyName = NULL;
        return company;
}

void printCompany(COMPANY* company) {
        printf("************\n");
        printf("Social Name: %s\n", company->socialName);
        printf("Fantasy Name: %s\n", company->fantasyName);
        printf("Reason for shutdown: %s\n", company->reason);
        printf("Audit company: %s\n", company->companyName);
        printf("CNPJ: %s\n", company->CNPJ);
        // TODO: format dates
        printf("Register date: %s\n", company->registerDate);
        printf("Cancellation date: %s\n", company->cancelDate);
        printf("Audit company CNPJ: %s\n", company->CNPJaudit);
}

void deleteCompany(COMPANY* company) {
        free(company->socialName);
        free(company->fantasyName);
        free(company->reason);
        free(company->companyName);
        free(company);
        company = NULL;
}

/********************************/
/************* CSV **************/
/********************************/

CSV* newCSV() {
        CSV* csv = (CSV*)malloc(sizeof(CSV));
        csv->size = 0;
        csv->companies = NULL;
        return csv;
}

void printCSV(CSV* csv) {
        int i;
        printf("\n\n****\tCSV CONTENTS\t****\n\n");
        for (i = 0; i < csv->size; i++) {
                printCompany(csv->companies[i]);
        }
}

void deleteCSV(CSV* csv) {
        int i;
        for (i = 0; i < csv->size; i++) {
                deleteCompany(csv->companies[i]);
        }
        free(csv);
        csv = NULL;
}
