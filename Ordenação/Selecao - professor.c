/* programa_selecao_01.c */
#include <stdio.h>

void ordena_Selecao(int vetor[],int qtdEl)
{
 	 int i,j, min, aux;
	 for(i=0; i<qtdEl-1; i++)
	 {
	  	  min=i;
		  for(j=i+1; j<qtdEl; j++)
		  {
		   	   if (vetor[j] < vetor[min])
			   min=j;
		   }
  	 	   aux = vetor[i];
	 	   vetor[i] = vetor[min];
	 	   vetor[min] = aux;
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
	  int elementos[] = {13, 9, 2, 0, 6};
	  printf("Original: ");
	  imprime(elementos);
	  
	  ordena_Selecao(elementos, 5);
	  
	  printf("Ordenado:");
	  imprime(elementos);
	  return 0;
}
