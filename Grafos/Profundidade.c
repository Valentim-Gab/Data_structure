#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include<math.h>

//Register


typedef struct NULL;

//Function
void profundidade(int totalNos, int atual);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    //VAR
    
    
    //INICIO
    printf("\n");
    
    
  	
    printf("\n\n");
    return 0;
}

void profundidade(int totalNos, int atual) {
	//VAR
	int i;
	
	//INICIO
	printf("  %d ", atual); //ou chama função para processar atual
	
	visitado[atual] = true;
	
	for (i=0, i < totalNos; i++) {
		if (mat[atual][i] == 1 && !visitado[i]) {
			profundidade(totalNos, i);
		}
	}
}
