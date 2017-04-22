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
#include "../includes/interface.h"

int main(int argc, char const *argv[]) {

        // CONTENT
        CSV* csv = newCSV();

        // I/O FILES
        FILE* in = fopen("./companies.csv", "r");
        FILE* out = fopen("./out", "wb");

        // FAIL TEST
        if (!in) {
                printf("CAN'T OPEN INPUT FILE\n");
                return EXIT_FAILURE;
        }
        if (!out) {
                printf("CAN'T CREAT OUTPUT FILE\n");
                return EXIT_FAILURE;
        }

        // READ CSV CONTENTS TO RAM
        csv = readCSV(in);

        // CLOSE INPUT FILE
        fclose(in);
        in = NULL;

        // WRITE CSV CONTENTS TO BINARY OUTPUT FILE
        // writeFile(csv, out);

        // MENU INTERFACE

        // FREE MEMORY
        deleteCSV(csv);

        // CLOSE I/O FILES
        fclose(out);
        out = NULL;

        return 0;
}
