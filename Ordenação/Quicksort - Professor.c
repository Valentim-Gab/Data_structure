#include <stdio.h>

void imprime(int v[7]) {
    int i;
    for (i=0; i<7; i++) {
		printf("%d ", v[i]);
    }
	printf("\n");
}

void quicksort(int *v, int a, int b) {
	int i, j, x, pivo, y;
	pivo = (a + b) / 2;
    i = a;
    j = b;
    x = v[pivo];
	do 
    {
		while(v[i] < x && i < b) {
			i++;
        }
        while(x < v[j] && j > a) {
			j--;
        }
        if(i <= j) 
        {
			y = v[i];
			v[i] = v[j];
			v[j] = y;
			i++;
			j--;
		}
	} while(i <= j);
	if(a < j) {
		quicksort(v, a, j);
    }
	if(i < b) {
		quicksort(v, i, b);
    }
}

	
int main() {
	int i, Vetor[7]= {7,2,12,9,6,1,0};
	printf("elementos fora de ordem: ");
	imprime(Vetor);
	
	quicksort(Vetor, 0, 6); /* na primeira chamada, os par?metros iniciais s?o os extremos da matriz */
	
	printf("elementos ordenados: ");
	imprime(Vetor);
	return 0;
}


