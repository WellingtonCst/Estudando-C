#include <stdio.h>

int main(){
    int vidas = 3; // Inicialização com 3 vidas
    int resposta;

    printf("Bem-vindo ao Quiz!\n");

    //pergunta 1
    printf("\nPergunta 1: Qual e a capital do Brasil?\n");
    printf("1. Sao Paulo\n2. Brasilia\n3. Rio de Janeiro\n");
    scanf("%d", &resposta);

    if(resposta == 2){
        printf("Resposta correta! Voce ganhou uma vida.\n");
        vidas++;
    }else{
        printf("Resposta Incorreta! Voce perdeu uma vida.\n");
        vidas--;
    }

    printf("Vidas restantes: %d\n", vidas);

    //pergunta 2
    printf("\nPergunta 2: Qual e o maior planeta do nosso sistema solar?\n");
    printf("1. Terra\n2. Marte\n3. Jupiter\n");
    scanf("%d", &resposta);

    if(resposta == 3){
        printf("Resposta correta! Voce ganhou uma vida.\n");
        vidas++;
    }else{
        printf("Resposta Incorreta! Voce perdeu uma vida.\n");
        vidas--;
    }

    printf("Vidas restantes: %d\n", vidas);

    //adicione mais perguntas...

    printf("\nPergunta 3: Quem foi o primeiro e unico samurai negro no japao no periodo feudal, segundo a lenda?\n");
    printf("1. Yasuke\n2. Yusuke\n3. Yugito\n");
    scanf("%d", &resposta);

    if(resposta == 1){
        printf("Resposta correta! Voce ganhou uma vida.\n");
        vidas++;
    }else{
        printf("Resposta incorreta! Voce perdeu uma vida.\n");
        vidas--;
    }

    printf("\nVidas restantes: %d\n", vidas);
        if(vidas == 0){
            printf("\nGame Over, voce nao tem mais vida\n");
        }

    printf("\nFim do Quiz\n");

    return 0;

}