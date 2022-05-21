#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include<math.h>
#define max 6

//Register
struct grafo {
	int info;
	struct grafo *aresta[3];
};

typedef struct grafo no;
no *g = NULL;
no *vetaux[max]; //vetor para guardar apenas os endere�os de mem�ria de todos os n�s. 

//Function
void criaNo (int i);
no *incidencia(no *g);
void imprimeListaAdjacencia();

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    //VAR
    char op, novo = 's';
    int i = 0, a, totalNos = 0, b;
    
    //INICIO
    printf("\n");
    
    for (b=0; b<max; b++) {
    	vetaux[b] = NULL; //Inicialmente com valores nulos para o vetor que guarda os endere�os de mem�ria dos n�s
	}
	
	while (novo == 's' && totalNos < max) {
		printf("  Inisira o valor: ");
			scanf("%d", &a);
		criaNo(a);
		totalNos++;
		
		if (totalNos < max) {
			printf("  Inserir novo n� (s/n)? ");
			fflush(stdin);
				scanf("%c", &novo);
		}
	}
	
	printf("  Criar incid�ncias para um no (s/n)? ");
	fflush(stdin);
		scanf("%c", &op);
	g = vetaux[0];
	no *percorre = g; //ponteiro auxiliar para percorrer todos os n�s do grafo criando as incid�ncias
	
	while (i < max && op == 's') {
		percorre = incidencia(percorre); //cria as incidencias de um n�. Esta fun��o assume um n� predecessor e cria as liga��es com todos seus sucessores
		i++;
		percorre = vetaux[i];
		system("cls");
		
		printf("  Criar novas incidencias para um n� (s/n)? ");
		fflush(stdin);
			scanf("%c", &op);
	}
	imprimeListaAdjacencia();
  	
    printf("\n\n");
    return 0;
}

//Body Function
void criaNo (int i) {
	
	//VAR
	int x = 0;
	no *novo = (no *) malloc (sizeof(no));
	
	//INICIO
	novo -> info = i;
	novo -> aresta[0] = NULL; //inicialmente todas as posi??es do vetor aresta s?o nulas, ou seja, n?o apontam para nenhum outro n?
    novo -> aresta[1] = NULL;
    novo -> aresta[2] = NULL;
    
    while (vetaux[x] != NULL && x < max) {
    	x++;
	}
	vetaux[x] = novo;
}

no *incidencia(no *g) {
	system("cls");
	
	//VAR
	int a = 0, i, sucessor;
	char resp = 's';
	
	//INICIO
	while (a < 3 && resp == 's') {
		printf("  Insira o %d� sucessor do n� %d: ", a+1, g->info);
			scanf("%d", &sucessor);
		i = 0;
		
		while (vetaux[i] -> info != sucessor && i < max) {
			i++;
		}
		if (i == max) { // caso o la�o seja terminado com i = max, significa que o n� informado nao existe
			printf("  N� n�o encontrado");
		}
		g -> aresta[a] = vetaux[i];
		a++;
		
		if (a < 3) {
			printf("  Deseja inserir mais um sucessor (s/n)? ");
			fflush(stdin);
				scanf("%c", &resp);
		}
	}
	return g; 
}

void imprimeListaAdjacencia() {
	//VAR
	int i = 0, j;
	no *p, *p2;
	
	while (i < max && vetaux[i] != NULL) {
		j = 0;
		p = vetaux[i];
		printf("  %d - ", p -> info);
		
		while (j < 3 && p -> aresta[j] != NULL) {
			p2 = p -> aresta[j];
			printf("   %d - ", p2 -> info);
			j++;
		}
		i++;
		printf("\n");
	}
}
