#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include<math.h>

//Register


//Function
void imprime(int v[7], int q);
void ordena(int *v, int a, int b);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    //VAR
    int vet[7] = {7, 4, 6, 5, 0, 3, 2} , qtd = 7, i, meio, x, retorno;
    
    //INICIO
    printf("\n");
    
    printf("  Números fora de ordem: \n");
    imprime(vet, qtd);
    
    ordena(vet, 0, 6);
    
    printf("\n\n");
    
    printf("  Números em ordem: \n");
    imprime(vet, qtd);
    
    printf("\n\n");
    return 0;
}

//BODY_FUNCTION
void ordena(int *v, int a, int b) {
	//VAR
	int i, j, x, pivo, y;
	pivo = (a+b)/2;
	i = a;
	j = b;
	x = v[pivo];
	
	//INICIO
	do {
		while (v[i] < x && i < b) {
			i++;
		}
		while (x < v[j] && j > a) {
			j--;
		}
		
		if (i <= j) {
			y = v[i];
			v[i] = v[j];
			v[j] = y;
			i++;
			j++;
		}
	} while (i <= j);
	
	if (a < j) {
		ordena(v, a, j);
	}
	if (i < b) {
		ordena(v, i, b);
	}
}

void imprime(int v[7], int q) {
	//VAR
	int i;
	
	//INICIO
	for (i=0; i<q; i++) {
		printf("  %d ", v[i]);
	}
	printf("\n");
}
