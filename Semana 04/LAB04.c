#include <stdio.h>

/* Este código recebe do usuário um número de 1 até 12. Com isso
o programa informa qual mês se refere aquele número e quantos dias
esse mês possui
*/

int main (){
    //Declaração das variáveis
    int mes;

    //Atribuioção de Valores iniciais
    mes=0;

    //Entrada dos valores pelo usuário
    printf("Informe um numero entre 1 e 12 que represente um mes do ano: ");
    scanf("%d", &mes);
    printf("\nVoce informou:\n");
    printf("==============\n");

    //Testa qual mes foi informado
    switch (mes){
        case 1:
            printf("Janeiro (31 dias)");
            break;
        case 2:
            printf("Fevereiro (28 dias)");
            break;
        case 3:
            printf("Marco (31 dias)");
            break;
        case 4:
            printf("Abril (30 dias)");
            break;
        case 5:
            printf("Maio (31 dias)");
            break;
        case 6:
            printf("Junho (30 dias)");
            break;
        case 7:
            printf("Julho (31 dias)");
            break;
        case 8:
            printf("Agosto (31 dias)");
            break;
        case 9:
            printf("Setembro (30 dias)");
            break;
        case 10:
            printf("Outubro (31 dias)");
            break;
        case 11:
            printf("Novembro (30 dias)");
            break;
        case 12:
            printf("Dezembro (31 dias)");
            break;
        default:
            printf("Numero invalido! Por favor informe um numero inteiro entre 1 e 12.");
    }

    printf("\n\n");
    return 0;
}
