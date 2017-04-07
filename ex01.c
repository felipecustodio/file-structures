/**
 * Organização de Arquivos
 * Exercício Prático 01
 * Felipe Scrochio Custódio
 * 9442688
**/

#include <stdio.h>
#include <stdlib.h>

/**
 * Registros e Campos de tamanho Fixo
**/

#define SIZE 30
#define FIELD 10

// UTILS
char* readString() {

	char* string = NULL;
    	char stop = '@';
	int counter = 0;

	while (stop != 10) {
		scanf("%c", &stop);
		string = (char*)realloc(string, sizeof(char) * counter + 1);
		string[counter] = stop;
		counter++;
	}

	string[counter-1] = '\0';
	return string;
}

// FILES FUNCTIONS

typedef struct registry {
	char field[FIELD];
} REGISTRY;

typedef struct


int byteOffset(int RRN) {
    return (RRN * SIZE);
}

int main(int argc, char *argv[]) {

	FILE* file = NULL;
	char* filename = NULL;

	printf("Filename ::: ");
	filename = readString();
	file = fopen(filename, "wb");
	if (!file) printf("ERROR CREATING FILE\n");

	int menu = -1;
	while (menu != 0) {

		printf("Escolha a opção desejada\n");
		printf("1 - Gravar dados\n");
		printf("2 - Recuperar dados\n");
		printf("3 - Busca por RRN\n");
		printf("0 - Sair\n");
		printf("::: ");
		scanf("%d", &menu);

		switch(menu) {
			case 1:
				// write data
				break;
			case 2:
				// get data
				break;
			case 3:
				// recover data
				break;
			case 0:
				printf("Au revoir!\n");
				break;
		}
	}

	fclose(file);

	return 0;
}
