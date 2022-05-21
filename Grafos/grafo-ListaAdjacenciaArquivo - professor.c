#include<stdio.h>
#define max 6

struct grafo
{
    int info;
    struct grafo *aresta[3];
    };

typedef struct grafo no;
no *g = NULL;
no *vetaux[max]; //vetor para guardar apenas os endere?os de mem?ria de todos os n?s. 

void criaNo (int i)
{
    int x = 0;
    no *novo = (no *) malloc (sizeof(no));
    novo->info = i;
    novo->aresta[0] = NULL; //inicialmente todas as posi??es do vetor aresta s?o nulas, ou seja, n?o apontam para nenhum outro n?
    novo->aresta[1] = NULL;
    novo->aresta[2] = NULL;
    while (vetaux[x] != NULL && x < max) // pesquisa pela primeira posi??o vazia do vetor auxiliar
    {
        x++;
        }
    vetaux[x] = novo;
    }

no *incidencia(no *g)
{
    system("cls");
    int a = 0, i, sucessor;
    char resp = 's';
    while (a < 3 && resp == 's')
    {
        printf("insira o %do sucessor do no %d: ", a+1, g->info);
        scanf("%d", &sucessor);
        i = 0; 
        while(vetaux[i]->info != sucessor && i < max)
        {
            i++;
        }
        if (i == max) // caso o la?o seja terminado com i = max, significa que o n? informado nao existe
        {
            printf("no' nao encontrado");
        }
        g->aresta[a] = vetaux[i];
        a++;
        if (a < 3)
        {
            printf("Deseja inserir mais um sucessor (s/n)? ");
            fflush(stdin);
            scanf("%c", &resp);
        }
    }
    return g;
}

void imprimeListaAdjacencia()
{
   
    int i = 0, j;
    no *p, *p2;
    while (i < max && vetaux[i] != NULL)
    {
        j = 0;
        p = vetaux[i];
        printf("%d - ", p->info);
        while (j < 3 && p->aresta[j] != NULL)
        {
            p2 = p->aresta[j];
            printf("%d - ", p2->info);
            j++;
        }
        i++;
        printf("\n");
    }
}
    
int main()
{
    char op, novo = 's';
    int i = 0, a, totalNos = 0, b;
    
    for (b=0; b<max; b++)
    {
        vetaux[b] = NULL; //Inicialmente com valores nulos para o vetor que guarda os endere?os de mem?ria dos n?s
    }
    
    while (novo == 's' && totalNos < max)
    {
        printf("insira o valor: ");
        scanf("%d", &a);
        criaNo(a);
        totalNos++;
        if(totalNos < max)
        {
            printf("Inserir novo no (s/n)? ");
            fflush(stdin);
            scanf("%c", &novo);
        }
    }
    
    printf("criar incidencias para um no (s/n)? ");
    fflush(stdin);
    scanf("%c", &op);
    g = vetaux[0];
    no *percorre = g; // ponteiro auxiliar para percorrer todos os n?s do grafo criando as incid?ncias
    while (i < max && op == 's')
    {
        percorre = incidencia(percorre); //cria as incidencias de um n?. Esta fun??o assume um n? predecessor e cria as liga??es com todos seus sucessores
        i++;
        percorre = vetaux[i];
        system("cls");
        printf("criar novas incidencias para um (s/n)? ");
        fflush(stdin);
        scanf("%c", &op);
    }
    imprimeListaAdjacencia();    

    return 0;
    }
