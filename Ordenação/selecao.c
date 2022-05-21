#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include<math.h>

//Register


//Function
void funcao(int v[], int qtd);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    //VAR
    int vet[5], qtd = 0;
    
    //INICIO
    printf("\n");
    
    vet[0] = 6;
    qtd++;
    vet[1] = 2;
    qtd++;
    vet[2] = 3;
    qtd++;
    vet[3] = 7;
    qtd++;
    vet[4] = 11;
    qtd++;
    
    funcao(vet, qtd);
    
    printf("\n\n");
    return 0;
}

void funcao(int v[], int qtd) {
	//VAR
	int i, j, min, aux;
	
	//INICIO
	for (i=0; i<qtd; i++) {
		printf("  %d ", v[i]);
	}
	
	for (i=0; i<qtd - 1; i++) {
		
		min = i;
		
		for (j=i+1; j<qtd; j++) {
			
			if (v[j] < v[min])
				min = j;
		}
		aux = v[i];
		v[i] = v[min];
		v[min] = aux;
	}
	
	printf("\n");
	
	for (i=0; i<qtd; i++) {
		printf("  %d ", v[i]);
	}
}
