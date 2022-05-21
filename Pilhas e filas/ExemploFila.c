/*
Este exemplo apresenta uma lista encadeada que segue o conceito de Filas, ou seja,
elementos são inseridos no fim da fila e são removidos do início.
*/

#include <stdio.h>
struct lista
{
    int info;
    struct lista *prox;
    };

typedef struct lista Lista;
Lista *l;

//FUNÇÃO PARA CRIAR A LISTA VAZIA
Lista *inicializa(){ // tipo de retorno ? Lista pois vai retornar o ponteiro para NULL
    return NULL;
}

//FUNÇÃO PARA IMPRIMIR ELEMENTOS DA LISTA
void imprime (Lista *l)
{
     Lista *p;
     for (p=l; p!=NULL; p=p->prox){
        printf("%d ", p->info);
     }
     printf("\n");    
}
     

//FUNÇÃO PARA INSERIR NO FINAL DA LISTA
Lista *insere(Lista *l) // recebe como par?metros a lista para inser??o e o valor do novo elemento
{
    Lista *novo; // cria um novo elemento, que tem a estrutura de Lista
    novo = (Lista*) malloc(sizeof(Lista)); // aloca espa?o na mem?ria para o novo elemento
      
    int i;
    printf("Digite um valor inteiro: ");
    scanf("%d", &i);
    novo->info = i;
    novo->prox = NULL;

    if (l == NULL){ // se a lista estava vazia, "novo" será o primeiro elemento
        return novo;
    }

    else{
        Lista *p = l; // ponteiro para varrer a lista até encontrar o último elemento

        while(p->prox != NULL){
            p = p->prox;
        }

        p->prox = novo;
        imprime(l);
        return l;     
    }
}

//FUNÇÃO PARA RETIRAR O PRIMEIRO ELEMENTO DA LISTA
Lista *retira(Lista *l)
{
    Lista *p = l; //ponteiro para percorrer a lista

    if (p == NULL){
        printf("Não há elementos na lista\n");
        return p; //Lista vazia

    }
    else {
        printf("  Lista com elementos antes da remoção: \n");
        imprime(l);
        l = l->prox;
        free(p);
    }

    printf("Lista com elementos após a remoção: \n");
    imprime(l);

    return l; // retorna a lista depois de ter retirado um elemento
}

void menu(){
    printf("1. Inserir \n");
    printf("2. Remover \n");
    printf("3. Sair \n");
}

int main()
{
    int x;
    int op;
    l = inicializa();

    menu();
    scanf("%d", &op);
    do {
        if (op == 1){
            l = insere(l);
        }
        if (op == 2){
            l = retira(l);
        }
        menu();
        scanf("%d", &op);
    }while (op != 3);



    
    imprime(l);
    return 0;
}
