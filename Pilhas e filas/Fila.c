#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include<math.h>

//Register
struct fila {
	int codInfo;
	char nomeInfo[20];
	struct pilha *prox;
};

typedef struct fila Fila;

//Function
Fila *criaFila();
Fila *INSERT(Fila *f, char nomeIns[20], int codIns);
void imprime(Fila *f);
Fila *REMOVE(Fila *f);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    //VAR
    
    
    //INICIO
    printf("\n");
    
    Fila *f;
    char nome[20], op;
    int cod;
    f = criaFila();
    
    do {
    	fflush(stdin);
    	printf("========================================================\n");
    	printf("  Nome: ");
    		gets(nome);
    	printf("  Código: ");
    		scanf("%d", &cod);
    		
    	f = INSERT(f, nome, cod);
    	
    	fflush(stdin);
    	printf("  Inserir outro? (s/n)");
    		scanf("%c", &op);
	} while (op == 's');
	
	imprime(f);
	f = REMOVE(f);
	
	printf("  LISTA FINAL: \n");
	imprime(f);
  	
    printf("\n\n");
    return 0;
}

Fila *criaFila(){
    return NULL;
}

Fila *INSERT(Fila *f, char nomeIns[20], int codIns) {
	Fila *novo;
	novo = (Fila*) malloc(sizeof(Fila));
	
	novo -> codInfo = codIns;
	strcpy(novo -> nomeInfo, nomeIns);
	novo -> prox = NULL;
	
	if (f == NULL) {
		return novo;
	} else {
		Fila *b = f;
		
		while (b->prox != NULL) {
			b = b->prox;
		}
		
		b->prox = novo;
		imprime(f);
		return f;
	}
}

void imprime(Fila *f) {
	Fila *b;
	
	printf("========================================================\n");
	for (b=f; b!=NULL; b=b->prox) {
			printf("\n  Código: %d \n  Nome: %s \n \n", b->codInfo, b->nomeInfo);
	}
	printf("========================================================\n");
}

Fila *REMOVE(Fila *f) {
	Fila *b = f;
	
	if (b == NULL) {
		printf("  Não há elementos na lista \n");
		return b;
		
	} else {
		printf("  Lista com elementos antes da remoção: \n");
        imprime(f);
        f = f->prox;
        free(b);
	}
		
	printf("  Lista com elementos após a remoção: \n");
    imprime(f);

    return f;
}
