/* programa_insercao_01.c */
#include <stdio.h>

void ordena_Insercao(int lista[], int qtdEl)
{
 	 int i,j, aux;
 	 for( i=1; i<qtdEl; i++)
	 {
	  	  aux = lista[i];
	  	  for( j=i-1; j>=0 && aux < lista[j]; j--)
		  {
		   	   lista[j+1]=lista[j];
	      }
		  lista[j+1]=aux;
     }
}

void imprime (int vet[]){
	int cont;
	for(cont = 0; cont < 5; cont++)
	{
		printf(" %d ", vet[cont]);
    }
	printf("\n");
}

int main()
{
 	int cont;
 	int vet[] = {13, 9, 2, 0, 6 };
	printf("Original:");
	imprime(vet);
	
	ordena_Insercao(vet, 5);
	
	printf("Ordenado:");
	imprime(vet);
	
	return 0;
}
