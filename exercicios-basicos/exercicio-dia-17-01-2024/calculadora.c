#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    //configurando a localização para pt-br
    setlocale(LC_ALL, "Portuguese_Brazil.1252");


    int num1, num2, resultado;
    char operador;

    //solicitar ao usuário o primeiro
    printf("Digite o primeiro valor: ");
    scanf("%d", &num1);

    //solicitar ao usuário o operador
    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &operador); // O espaço antes de %c evita que o caractere de nova linha seja consumido

    //solicitar ao usuário o segundo número
    printf("Digite o segundo valor: ");
    scanf("%d", &num2);

    //verificar o operador e realizar a operação correspondente
    switch (operador){
        case '+':
            resultado = num1 + num2;
            printf("A soma dos valores é: %d\n", resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("A subtração dos valores é: %d\n", resultado);
            break;
        case'*':
            resultado = num1 * num2;
            printf("A multiplicação dos valores é; %d\n", resultado);
        case '/':
            if(num2 != 0){
                resultado = num1 / num2;
                printf("A divisão dos valores é: %d\n", resultado);
            }else {
                printf("Erro: Divisão por zero!\n");
            }            
            break;
        default:
            printf("Operador invalido!\n");
            break;    
    }
    return 0;
}