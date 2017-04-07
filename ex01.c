/**
 * Organização de Arquivos
 * Exercício Prático 01
 * Felipe Scrochio Custódio
 * 9442688
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Registros e Campos de tamanho Fixo
**/
#define SIZE 34
#define FIELD 10
#define DELIM '|'

// DATA
typedef struct data {

	char *name;
	char *street;
	int number;
	char *complement;

} DATA;

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

// DATA FUNCTIONS
DATA* createData() {
	DATA* d = (DATA*)malloc(sizeof(DATA));
	d->name = NULL;
	d->street = NULL;
	d->number = -1;
	d->complement = NULL;
	return d;
}

void printData(DATA* d) {
	printf("*** REGISTRO ***\n");
	printf("Nome: %s\n", d->name);
	printf("Endereço: %s\n", d->street);
	printf("Número: %d\n", d->number);
	printf("Complemento: %s\n", d->complement);
}

DATA* readData(DATA* d) {
	printf("*** INSERIR REGISTRO ***\n");
	printf("Nome: ");
	d->name = readString();
	printf("Endereço: ");
	d->street = readString();
	printf("Número: ");
	scanf("%d", &d->number);
	getchar();
	printf("Complemento: ");
	d->complement = readString();
	printf("***\n");
	return d;
}

// FILES FUNCTIONS

// WRITE DATA TO FILE
void writeFile(FILE* fp, DATA **d, int fields) {

	int i, j;
	for (i = 0; i < fields; i++) {

		// NOME
		for (j = 0; j < FIELD; j++) {
			if (j > strlen(d[i]->name) - 1) {
				fputc('$', fp);
			} else {
				fputc(d[i]->name[j], fp);
			}
		}

		// RUA
		for (j = 0; j < FIELD; j++) {
			if (j > strlen(d[i]->street)) {
				fputc('$', fp);
			} else {
				fputc(d[i]->street[j], fp);
			}
		}

		// NÚMERO
		fwrite(&d[i]->number, sizeof(int), 1, fp);

		// COMPLEMENTO
		for (j = 0; j < FIELD; j++) {
			if (j > strlen(d[i]->complement)) {
				fputc('$', fp);
			} else {
				fputc(d[i]->complement[j], fp);
			}
		}
	}
	rewind(fp);
}

// LIST ALL DATA FROM FILE
void readFile(FILE* fp) {

	char* field = NULL;
	field = (char*)malloc(sizeof(char) * FIELD);
	fread(field, sizeof(char), FIELD, fp);
	printf("I just read: ");
	printf("%s\n", field);

}

int byteOffset(int RRN) {
    return (RRN * SIZE);
}

// MAIN
int main(int argc, char *argv[]) {

	FILE* file = NULL;
	DATA** d = NULL;
	int fields = 0;
	char* filename = NULL;
	int menu = -1;

	while (menu != 0) {

		printf("Escolha a opção desejada\n");
		printf("1 - Inserir novo registro\n");
		printf("0 - Terminar inserção de dados\n");
		printf("::: ");
		scanf("%d", &menu);
		getchar();

		switch (menu) {
			case 1:
				// NOVO REGISTRO
				d = (DATA**)realloc(d, sizeof(DATA*) * fields + 1);
				d[fields] = createData();
				d[fields] = readData(d[fields]);
				fields++;
			case 0:
				// TERMINAR
				printf("Escrever no Arquivo\n");
				break;
			default:
				printf("Opção inválida!\n");
				break;
		}

	}

	menu = -1;
	printf("Filename ::: ");
	filename = readString();
	file = fopen(filename, "w");
	if (!file) printf("ERROR CREATING FILE\n");

	while (menu != 0) {

		printf("Escolha a opção desejada\n");
		printf("1 - Gravar dados no arquivo\n");
		printf("2 - Recuperar dados do arquivo\n");
		printf("3 - Busca por RRN\n");
		printf("0 - Sair\n");
		printf("::: ");
		scanf("%d", &menu);

		switch(menu) {
			case 1:
				// write data
				printf("Write data to file\n");
				writeFile(file, d, fields);
				break;
			case 2:
				printf("Get data from file\n");
				// get data
				break;
			case 3:
				printf("Recover data from RRNn\n");
				// recover data
				break;
			case 0:
				printf("Au revoir!\n");
				break;
			default:
				printf("Opção inválida!\n");
				break;
		}
	}

	readFile(file);
	fclose(file);

	return 0;
}
