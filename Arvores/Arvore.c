#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include<math.h>

//Register
struct arvore {
	int v;
	struct arvore *esq;
	struct arvore *dir;
};

typedef struct arvore arv;

//Function
arv* insere(arv *r, int c);
void pre_imprime (arv *a);
void sim_imprime (arv *a);
void pos_imprime (arv *a);
int busca (arv *a, int c);
arv *folha(arv *no);
arv *retira(arv *raiz, arv *r, arv *ant, int c);
int search(arv *raiz, arv *a, arv *ant, int c);
arv *removeRaiz (arv *raiz);

int i = 0;

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    //VAR
    arv *r = NULL;
    int x, v;
    
    //INICIO
    printf("\n");
    
    r = insere(r, 5);
    r = insere(r, 2);
    r = insere(r, 1);
    r = insere(r, 4);
    r = insere(r, 7);
    r = insere(r, 6);
    r = insere(r, 8);
    
    printf("Pr�-fixado: \n");
	pre_imprime(r);
	printf("\n");
	
	printf("Sim�trico: \n");
	sim_imprime(r);
	printf("\n");
	
	printf("P�s-fixado: \n");
	pos_imprime(r);
	printf("\n");
	
	printf("===============================\n");
	
	
	if (busca(r, 20) == 1) {
		printf("O valor existe na �rvore! \n");
	} else {
		printf("O valor n�o existe na �rvore! \n");
	}
	
	
	if (busca(r, 6) == 1) {
		printf("O valor existe na �rvore! \n");
	} else {
		printf("O valor n�o existe na �rvore! \n");
	}
	printf("===============================\n");
    
    printf("Digite um valor para buscar: ");
    	scanf("%d", &v);
    if (r->v == v) { //fun��o para remover elemento da raiz.
    	r = removeRaiz(r);
	} else {
		x = search(r, r, NULL, v);
		if (x==1) {
			printf("\n  Existe na �rvore!\n");
		}
	}
    
    printf("Pr�-fixado p�s remo��o: \n");
	pre_imprime(r);
	printf("\n");
    
    printf("\n\n");
    return 0;
}

//Body Function
arv* insere(arv *r, int c) {
	
	//VAR
	arv *novo = (arv*) malloc(sizeof(arv));
	
	//INICIO 
	novo -> v = c;
	novo -> esq = NULL;
	novo -> dir = NULL;
	
	if (r == NULL) {
		r = novo;
	} else {
		arv *aux = r, *ult;
		while (aux != NULL) {
			ult = aux;
			
			if (c < aux -> v)
				aux = aux -> esq;
			else
				aux = aux -> dir;
		}
		aux = ult;
		
		if (c < aux -> v)
			aux -> esq = novo;
		else
			aux -> dir = novo;	
	}
	return r;
}

void pre_imprime(arv *a) {
	//INICIO
	if (a != NULL) {
		printf("%d \n", a->v);
		
		if (a->esq != NULL)
			pre_imprime(a->esq);
			
		if (a->dir != NULL)
			pre_imprime(a->dir);
	}
}

void sim_imprime(arv *a) {
	//INICIO
	if (a != NULL) {
		if (a->esq != NULL)
			sim_imprime(a->esq);
			
		printf("%d \n", a->v);
		
		if (a->dir != NULL)
			sim_imprime(a->dir);
	}
}

void pos_imprime(arv *a) {
	//INICIO
	if (a != NULL) {
		if (a->esq != NULL)
			pos_imprime(a->esq);
			
		if (a->dir != NULL)
			pos_imprime(a->dir);
			
		printf("%d \n", a->v);
	}
}

int busca (arv *a, int c) {
	if (a == NULL) {
		return 0;
	} else {
		if (c == a->v) {
			return 1;
		} else if (busca(a->esq, c) == 1) {
			return 1;
		} else {
			return busca(a->dir, c);
		}
	}	
}

arv *folha(arv *no) {
	arv *aux;
	if (no->esq == NULL && no->dir == NULL) {
		return no;
	} else {
		if (no->esq != NULL) {
			aux = folha(no->esq);
		}
		if (no->dir != NULL) {
			aux = folha (no->dir);
		}
		return aux;
	}
}

arv *retira(arv *raiz, arv *r, arv *ant, int c) {
	arv *aux = r;
	int teste;
	arv *no;
	arv *auxEsquerda = r -> esq;
	arv *auxDireita = r -> dir;
	
	//caso 1: remover folha
	if (r->esq == NULL && r->dir == NULL) {
		if (ant->esq == r) {
			ant -> esq =NULL;
		} else if (ant->dir == r) {
			ant->dir = NULL;
		}
		free(r);
	} else {
		if (ant->esq == r) {
			if (r->esq != NULL && r->dir == NULL) { //testa se h� apenas um filho e est� na subarvore da esquerda
				ant->esq = r->esq;
				free(r);
				return raiz;
			} else if (r->esq == NULL && r->dir != NULL) {
				ant->esq = r->dir;
				free(r);
				return raiz;
			}
		} else if (ant->dir == r) {
			if (r->esq != NULL && r->dir == NULL) { //testa se h� apenas um filho e est� na subarvore da direita
				ant->dir = r->esq;
				free(r);
			} else if (r->esq == NULL && r->dir != NULL) {
				ant->dir = r->dir;
				free(r);
			}
			return raiz;
		}
		
		//remover elementos com dois filhos
		if (r->esq != NULL && r->dir != NULL) {
			if (auxEsquerda->dir != NULL) { //substituir o removido pelo elemento mais a direita da sub-�rvore da esquerda
				no = folha(auxEsquerda->dir); //encontra o n� folha para substituir o removido
				no->esq = r->esq;
				no->dir = r->dir;
				auxEsquerda->dir = NULL;
				
				if (ant->esq == r) {
					ant->esq = no;
				} else if (ant->dir == r) {
					ant->dir = no;
				}
				free(r);
			} else if (auxDireita->esq != NULL) {
				no = folha(auxDireita -> esq); //encontra o n� folha para substituir o removido
				no->esq = r->esq;
				no->dir = r->dir;
				auxDireita->esq = NULL;
				
				if (ant->esq == r) {
					ant->esq = no;
				} else if (ant->dir == r) {
					ant->dir = no;
				}
				free(r);
				
			//remover n� que n�o n�o se enquadra nos itens anteriores (aula 8.3, slide 7)
			} else {
				if (r->esq == no) {
					no->dir = r->dir;
					free(r);
				} else if (r->dir == no) {
					no->esq = r->esq;
					free(r);
				}
			}
		}
	}
	return raiz;
}

int search(arv *raiz, arv *a, arv *ant, int c) {
	int r;
	if (a == NULL) {
		return 0; //arvore vazia
	} else {
		if (c == a->v) {
			printf("Valor encontrado. Deseja remover (1. sim/ 2. n�o): ");
				scanf("%d", &r);
				if(r == 1) {
					raiz = retira(raiz, a, ant, c);
					printf("Valor removido. \n");
					return 0;
				}
		} else if (search(raiz, a->esq, a, c) == 1) { // entra no ELSE IF se o retorno for 1
			return 1;
		} else {
			return search(raiz, a->dir, a, c);
		}
	}
}

arv *removeRaiz (arv *raiz) {
	arv *r = raiz;
	
	if (raiz->esq == NULL && raiz->dir == NULL) { //se a ra�z n�o tem filhos, apenas remover
		free(raiz);
		return NULL; // pois a �rvore ficar� vazia.
	} else if (raiz->esq != NULL && raiz->dir == NULL) { // testa se raiz tem apenas filho da esquerda
		raiz = raiz->esq;
		free(r);
		return raiz;
	} else if (raiz->esq == NULL && raiz->dir != NULL) { // testa se raiz tem apenas filho da direita
		raiz = raiz->dir;
		free(r);
		return raiz;
	} else { // se tiver dois filhos
	
		if(r->esq != NULL && r->dir != NULL){
            if(r->dir != NULL){ //substituir o removido pelo elemento mais a direita da sub-�rvore da esquerda
                raiz = folha(r->dir); //encontra o n� folha para substituir o removido
                raiz->esq = r->esq;
                raiz->dir = r->dir;
                r->dir = NULL;

                if (r->esq == r){
                    r->esq = raiz;
                }
                else if (r->dir == r){
                    r->dir = raiz;
                }
                free(r);
            }
            else if(r->esq != NULL){
                raiz = folha(r->esq); //encontra o n� folha para substituir o removido
                raiz->esq = r->esq;
                raiz->dir = r->dir;
                r->esq = NULL;

                if (r->esq == r){
                    r->esq = raiz;
                }
                else if (r->dir == r){
                    r->dir = raiz;
                }
                free(r);
            }
            
            //remover n� que n�o n�o se enquadra nos itens anteriores (aula 8.3, slide 7)
            else{
                if (r->esq == raiz){
                    raiz->dir = r->dir;
                    free(r);
                }
                else if(r->dir == raiz){
                   	raiz->esq = r->esq;
                    free(r);
                }
            }
        }
	}
}
