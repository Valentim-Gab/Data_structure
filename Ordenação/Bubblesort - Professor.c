/* programa_bubble_02.c */
#include <stdio.h>
#include <stdlib.h>

void bubble( int lista[], int QtdEl )
{
 	 int i,j;
	 int aux, Troca;
	 for(i=1;i<QtdEl;i++)
	 {
	     Troca = 0; /* falso */
	     for(j=QtdEl-1;j>=i;j--)
		 {
			if(lista[j-1] > lista[j])
			{
   			    aux = lista[j-1];
				lista[j-1] = lista[j];
				lista[j] = aux;
				Troca = 1; /* verdadeiro */
			}
		}
		if(Troca == 0)
		{
		 	return;
		}
    }
}

int main()
{
 	  int i;
 	  int lista[] = {13, 9, 2, 0, 6};
 	  printf("Original:");
	  for(i = 0; i < 5; i++)
	  {
			printf(" %d", lista[i]);
	  }
	  printf("\n");
	  bubble(lista, 5);
	  printf("Ordenado:");
	  for(i = 0; i < 5; i++)
	  {
			printf(" %d", lista[i]);
	  }
	  printf("\n");
	  return 0;
}
