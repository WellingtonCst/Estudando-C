#include <stdio.h>

int main(){
    float num1, num2, num3;
    float media;

    //entrada do usuario
    printf("Digite um numero: ");
    scanf("%f", &num1);

    printf("Digite outro numero: ");
    scanf("%f", &num2);

    printf("Digite outro numero: ");
    scanf("%f", &num3);

    //calculo da media
    media = (num1 + num2 + num3) /3;

    //saida
    printf("A media dos tres numeros e: %.2f\n", media);

    return 0;
}