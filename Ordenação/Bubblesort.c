#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include<math.h>

//Register


//Function
void funcao(int v[5], int qtd);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    //VAR
    int vet[5], qtd = 0, i;
    
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
    
    printf("\n");
    for (i=0; i<qtd; i++) {
		printf("  %d ", vet[i]);
	}
    
    printf("\n\n");
    return 0;
}

void funcao(int v[5], int qtd) {
	//VAR
	int i, j, aux, troca;
	
	//INICIO
	for (i=0; i<qtd; i++) {
		printf("  %d ", v[i]);
	}
	
	for (i=0; i<qtd; i++) {
		
		troca = 0;
		
		for (j=0; j<qtd-1; j++) {
			
			if (v[j] > v[j+1]) {
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				troca = 1;
			}
		}
		if (troca == 0) return;
	}
}
