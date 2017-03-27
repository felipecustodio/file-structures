/**
 * Organização de Arquivos
 * Exercício Prático 01
 * Felipe Scrochio Custódio
 * 9442688
**/

#include <stdio.h>
#include <stdlib.h>

// Registry size
#define SIZE 40
// Field size
#define STRING_SIZE 12

// Registry
typedef struct data {
    
	char *name;
	char *street;
	int number;
	char *complements;

} DATA;

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

int byteOffset(int RRN) {
    return (RRN * SIZE);
}

DATA writeData();
void printData(DATA data);
void get(DATA data, int RRN);

DATA writeData() {
    
}

DATA readField() {
    DATA field;
    printf("Nome:\t");
    field.name = readString();
    printf("Rua:\t");
    field.street = readString();
    printf("Número:\t");
    scanf("%d", &field.number);
    getchar(); // keyboard buffer handling
    printf("Complemento:\t");
    field.complements = readString();
    return field;
}

void printField(DATA field, int i) {
    printf("*-----------*\n");
    printf("Registro %d\n", i);
    printf("Nome: %s\n", field.name);
    printf("Rua: %s\n", field.street);
    printf("Número: %d\n", field.number);
    printf("Complemento: %s\n", field.complements);
}

DATA* readData() {

    int menu = -1;
    int fields = 0;
    DATA* data = NULL;
    
    printf("Leitura de Dados\n");
    while (menu != 2) {
        printf("Selecione a opção desejada\n");
        printf("1) Inserir novo registro\n");
        printf("2) Terminar e escrever arquivo\n");
        printf(":::\t");
        scanf("%d", &menu);
        getchar();
        
        switch(menu) {
            case 1: 
                // Ler novo registro
                data = (DATA*)realloc(data, sizeof(DATA*) * fields + 1);
                data[fields] = readField();
                break;
            case 2:
                printf("Escrevendo arquivo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }
    return data;
}

void printFile() {

    
    
    
}

void get(DATA data, int RRN) {

}

int main(int argc, char *argv[]) {

	int menu = -1;
	int RRN = 0;
    FILE *fp = NULL;
    DATA* data = NULL;
    char* filename = NULL;
    
    printf("Insert filename ::: \t");
    filename = readString();
    
    fp = fopen("rw", filename);
    data = readData();
    
    // escrever dados no arquivo
    
    
	while (menu != 0) {
		printf("Select option:\n");
		printf("1) Print data\n");
		printf("2) Recover data via RRN\n");
		printf("0) Exit\n");
		printf(":::\t");
		
		scanf("%d", &menu);
		switch(menu) {
			case 1:
				printFile(fp);
				break;
			case 2:
				printf("Insert RRN :::\t");
				scanf("%d", &RRN);
				// get(data, RRN);
				break;
            case 0:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid option\n");
                break;
		}
	}
	return 0;
}


