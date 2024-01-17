#include <stdio.h>
#include <stdlib.h>

int main(){
    int num1,num2;
    int resultado;

    printf("\nDigite um valor: ");
    scanf("%d", &num1);

    printf("\nDigite outro valor: ");
    scanf("%d", &num2);

    resultado = num1+num2;

    printf("A Soma dos valores e igual a: %d", resultado);
    
    return 0;
}