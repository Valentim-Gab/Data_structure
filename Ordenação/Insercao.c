#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include<math.h>

//Register


//Function
void funcao(int v[5]);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    //VAR
    int vet[5], qtd = 0;
    
    //INICIO
    printf("\n");
    
    funcao(vet);
    
    printf("\n\n");
    return 0;
}

void funcao(int v[5]) {
	//VAR
	int i, j, aux, qtd;
	
	//INICIO
	
	v[0] = 6;
    qtd++;
    v[1] = 2;
    qtd++;
    v[2] = 3;
    qtd++;
    v[3] = 7;
    qtd++;
    v[4] = 11;
    qtd++;
    v[5] = 0;
    qtd++;
    
	for (i=0; i<qtd; i++) {
		printf("  %d ", v[i]);
	}
	
	for (i=1; i<qtd; i++) {
		
		aux = v[i];
		
		for (j=i-1; j>=0 && aux < v[j]; j--) {
			
			v[j+1] = v[j];
		}
		v[j+1] = aux;
	}
	
	printf("\n");
	
	for (i=0; i<qtd; i++) {
		printf("  %d ", v[i]);
	}
}
