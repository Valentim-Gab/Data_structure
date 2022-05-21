#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include<math.h>

//Register


//Function
int soma (int a, int b);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    //VAR
    int x = 1, y = 2;
    
    //INICIO
    printf("\n");
    
    x = soma(x, y);
    
    printf("Valor de x final: %d", x);
  	
    printf("\n\n");
    return 0;
}

//Body Function
int soma (int a, int b) {
	//VAR
	
	//INICIO
	
	if (a == 10) {
		return a;
	} else {
		printf("x(%d) + y(%d) = ", a, b);
		a += b;
		printf("x(%d) \n\n", a);
		
		printf("y(%d) + 1 = ", b);
		b++;
		printf("y(%d) \n\n", b);
		
		a = soma(a, b);
	}
	return a;
}
