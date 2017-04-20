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
#include "../includes/files.h"

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

        // INTERFACE
        int menu = -1;
        while (menu != 0) {
                printf("\n\n:::\tASSIGNMENT 1\t:::\n\n");
                printf("::: CHOOSE OPTION\n");
                printf("[1] PRINT DATA FROM FILE\n");
                printf("[2] SEARCH DATA\n");
                printf("[3] GET DATA FROM ID\n");
                printf("[4] GET FIELD FROM REGISTRY\n");
                printf("::: ");
                scanf("%d", &menu);

                switch(menu) {
                        case 1:
                                break;
                        case 2:
                                break;
                        case 3:
                                break;
                        case 4:
                                break;
                        case 0:
                                printf("\n\nEXITING\n\n");
                                break;
                        default:
                                printf("\n\nINVALID OPTION!\n\n");
                                break;
                }

        }

        // FREE MEMORY
        deleteCSV(csv);

        // CLOSE I/O FILES
        fclose(in);
        fclose(out);
        in = NULL;
        out = NULL;

        return 0;
}
