#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include<math.h>

//Register
struct lista {
	int info;
	struct lista *prox;
};

typedef struct lista Lista;

//Function
Lista *insere(Lista *l, int i);
void imprime (Lista *l);
Lista *retira(Lista *l, int v);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    //VAR
    int leu;
    
    //INICIO
    printf("\n");
    
  	Lista *l;
  	l = NULL;
  	l = insere(l, 43);
  	l = insere(l, 75);
  	l = insere(l, 30);
  	l = insere(l, 12);
  	printf("  Insira mais um valor: ");
  	scanf("%d", &leu);
  	l = insere(l, leu);
  	imprime(l);
  	
  	l = retira(l, 75);
  	printf("\n");
  	imprime(l);

    printf("\n\n");
    return 0;
}

Lista *insere(Lista *l, int i) {
	Lista *novo;
	novo = (Lista*) malloc(sizeof(Lista));
	novo -> info = i;
	novo -> prox = l;
	return novo;
}

void imprime (Lista *l) {
	Lista *p;
	
	printf("  ");
	for (p=l; p!=NULL; p=p->prox) {
		if (p->prox != NULL) {
			printf("%d - ", p->info);
		} else {
			printf("%d", p->info);
		}
		
	}
}

Lista *retira(Lista *l, int v) {
	Lista *ant = NULL;
	Lista *p = l;
	
	while (p != NULL && p->info != v) {
		ant = p;
		p = p ->prox;
	}
	
	if (p == NULL) {
		return l;
	}
	
	if (ant == NULL) {
		l = p->prox;
	} else {
		ant ->prox = p->prox;
	}
	
	free(p);
	return l;
}
