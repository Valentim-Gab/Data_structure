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
no *vetaux[max]; //vetor para guardar apenas os endereços de memória de todos os nós. 

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
    	vetaux[b] = NULL; //Inicialmente com valores nulos para o vetor que guarda os endereços de memória dos nós
	}
	
	while (novo == 's' && totalNos < max) {
		printf("  Inisira o valor: ");
			scanf("%d", &a);
		criaNo(a);
		totalNos++;
		
		if (totalNos < max) {
			printf("  Inserir novo nó (s/n)? ");
			fflush(stdin);
				scanf("%c", &novo);
		}
	}
	
	printf("  Criar incidências para um no (s/n)? ");
	fflush(stdin);
		scanf("%c", &op);
	g = vetaux[0];
	no *percorre = g; //ponteiro auxiliar para percorrer todos os nós do grafo criando as incidências
	
	while (i < max && op == 's') {
		percorre = incidencia(percorre); //cria as incidencias de um nó. Esta função assume um nó predecessor e cria as ligações com todos seus sucessores
		i++;
		percorre = vetaux[i];
		system("cls");
		
		printf("  Criar novas incidencias para um nó (s/n)? ");
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
		printf("  Insira o %d° sucessor do nó %d: ", a+1, g->info);
			scanf("%d", &sucessor);
		i = 0;
		
		while (vetaux[i] -> info != sucessor && i < max) {
			i++;
		}
		if (i == max) { // caso o laço seja terminado com i = max, significa que o nó informado nao existe
			printf("  Nó não encontrado");
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
