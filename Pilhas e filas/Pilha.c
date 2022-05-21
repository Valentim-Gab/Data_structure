#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include<math.h>

//Register
struct pilha {
	int info;
	struct pilha *prox;
};

typedef struct pilha Pilha;
Pilha *p;

//Function
Pilha *inicializa();
Pilha *insere(Pilha *p);
void imprime(Pilha *p);
Pilha *retira(Pilha *p);
void menu();

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    //VAR
    int x;
    int op;
    
    //INICIO
    printf("\n");
    
  	p = inicializa();
  	
  	menu();
  	printf("  Opção: ");
  		scanf("%d", &op);
  	printf("========================================================\n");
  	
  	do {
  		if (op == 1) {
  			p = insere(p);
		}
		if (op == 2) {
  			p = retira(p);
		}
		menu();
		printf("  Opção: ");
			scanf("%d", &op);
	printf("========================================================\n");
	} while (op != 3);
	
	printf("  LISTA FINAL: \n");
	imprime(p);
	printf("========================================================\n");

    printf("\n\n");
    return 0;
}

Pilha *inicializa(){
    return NULL;
}

Pilha *insere(Pilha *p) {
	
	//VAR
	int i;
	
	//INICIO
	Pilha *novo;
	novo = (Pilha*) malloc(sizeof(Pilha));
	
	printf("  Digite um valor inteiro: ");
		scanf("%d", &i);
	novo -> info = i;
	novo -> prox = NULL;
	
	if (p == NULL) {
		return novo;
	} else {
		Pilha *b = p;
		
		while (b->prox != NULL) {
			b = b->prox;
		}
		
		b->prox = novo;
		imprime(p);
		return p;	
	}
}

void imprime (Pilha *p) {
	Pilha *b;
	
	printf("  ");
	for (b=p; b!=NULL; b=b->prox) {
		if (b->prox != NULL) {
			printf("%d - ", b->info);
		} else {
			printf("%d \n", b->info);
		}
		
	}
}

Pilha *retira(Pilha *p) {
	Pilha *b = p;
	
	if (b == NULL) {
		printf("  Não há elementos na lista \n");
		return b;
		
	} else if (b->prox == NULL) {
		p = NULL;
		free(b);
		printf("  A lista agora está vazia. \n");
		return p;
	} else {
		printf("  Lista com elementos antes da remoção: \n");
		imprime(p);
		
		Pilha *ant;
		
		while (b->prox != NULL) {
			ant = b;
			b = b->prox;
		}
		free(b);
		ant->prox = NULL;
	}
	
	printf("  Lista com elementos após a remoção: \n");
    imprime(p);

    return p;
}

void menu(){
	printf("========================================================\n");
    printf("  1. Inserir \n");
    printf("  2. Remover \n");
    printf("  3. Sair \n");
}  
