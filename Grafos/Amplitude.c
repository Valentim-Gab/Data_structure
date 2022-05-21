#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include<math.h>

//Register


typedef struct NULL;

//Function
void amplitude (int atual);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    //VAR
    
    
    //INICIO
    printf("\n");
    
    
  	
    printf("\n\n");
    return 0;
}

void amplitude (int atual) {
	//VAR
	int i;
	
	//INICIO
	for (i=0; i<6; i++) {
		visitado[i] = false; // nenhum nó foi visitado até aqui
	}
	printf("  %d", atual);
	
	visitado[atual] = true;
	
	while (atual != -1) {
		for (i=0; i<6; i++) {
			if (grafo[atual][i] == 1 && !visitado[i]) {
				printf("  %d", i);
				visitado[i] = true;
				incluir(i); //na fila
			}
		}
		atual = retirar(); //Da fila
	}
}
