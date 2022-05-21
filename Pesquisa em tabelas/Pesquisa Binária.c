#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include<math.h>

//Register
struct tabela {
    int matricula;
    char nome[30];
    float nota1;
    float nota2;
    float media;
};

typedef struct tabela universidade;

//Function
void  insere (universidade aluno[]) {
    aluno[0].matricula = 1001; strcpy(aluno[0].nome, "Maria"); aluno[0].nota1 = 7.1; aluno[0].nota2 = 6.9; aluno[0].media = (aluno[0].nota1 + aluno[0].nota2)/2;
    aluno[1].matricula = 1010; strcpy(aluno[1].nome, "Joao"); aluno[1].nota1 = 2; aluno[1].nota2 = 6.5; aluno[1].media = (aluno[1].nota1 + aluno[1].nota2)/2;
    aluno[2].matricula = 1204; strcpy(aluno[2].nome, "Carlos"); aluno[2].nota1 = 3.5; aluno[2].nota2 = 4.9; aluno[2].media = (aluno[2].nota1 + aluno[2].nota2)/2;
    aluno[3].matricula = 2598; strcpy(aluno[3].nome, "Jorge"); aluno[3].nota1 = 10; aluno[3].nota2 = 5.5; aluno[3].media = (aluno[3].nota1 + aluno[3].nota2)/2;
    aluno[4].matricula = 3520; strcpy(aluno[4].nome, "Bia"); aluno[4].nota1 = 2.9; aluno[4].nota2 = 1.8; aluno[4].media = (aluno[4].nota1 + aluno[4].nota2)/2;
    aluno[5].matricula = 3587; strcpy(aluno[5].nome, "Maria"); aluno[5].nota1 = 4; aluno[5].nota2 = 10; aluno[5].media = (aluno[5].nota1 + aluno[5].nota2)/2;
    aluno[6].matricula = 4571; strcpy(aluno[6].nome, "Carlos"); aluno[6].nota1 = 8.9; aluno[6].nota2 = 6.1; aluno[6].media = (aluno[6].nota1 + aluno[6].nota2)/2;
}

void imprime (universidade aluno[10]) {
    int i;
    for (i=0; i<7; i++) {
        printf ("  %d \t", aluno[i].matricula);
        printf ("%s \t", aluno[i].nome);
        printf ("%.1f \t", aluno[i].nota1);
        printf ("%.1f \t", aluno[i].nota2);
        printf ("%.1f", aluno[i].media);
        printf ("\n");
    }
}

int buscaBinaria (universidade aluno[]) {
	//VAR
	int i = 0, m, fim = 6, meio;
	
	//INICIO
	fflush(stdin);
	printf("\n  Digite uma matrícula para pesquisar: ");
		scanf("%d", &m);
	
	while (i <= fim) {
		meio = (i+fim)/2;		
        if (m == aluno[meio].matricula) {	
        	return meio;
		} else if (m > aluno[meio].matricula) {
			i = meio+1;
		} else {
			fim = meio-1;
		}
    }
    
    printf("\n");
    
	return -1;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	//VAR
	universidade aluno[10];
	int retorno, i;
	
	//INICIO
    insere(aluno);
    imprime(aluno);
    
    retorno = buscaBinaria(aluno);
    i = retorno;
    
    if (i != -1) {
	    printf("===============================================\n");
	   	printf("  %d \t", aluno[i].matricula);
	    printf("%s \t", aluno[i].nome);
	    printf("%.1f \t", aluno[i].nota1);
		printf("%.1f \t", aluno[i].nota2);
	    printf("%.1f", aluno[i].media);
        printf("\n");
	    printf("===============================================\n");
	} else {
		printf("==============================================================\n");
		printf("  Não existe nenhum aluno com esse número de matrícula! \n");
		printf("==============================================================\n");
	}
    
    return 0;
}
