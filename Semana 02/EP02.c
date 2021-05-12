#include <stdio.h>

/* Este código recebe do usuário um valor de velocidade
em km/h e converte para mi/h. Posteriormente essas duas
velocidades são exibidas na tela usando tabulação.

Assume-se que os valores de entrada sejam números reais válidos
*/

int main (){
    //Declaração das variáveis
    float velocidade_kph, velocidade_mph;

    //Atribuioção de Valores iniciais
    velocidade_kph = 0.0;


    //Entrada dos valores pelo usuário
    printf("Digite a velocidade em kph: ");
    scanf("%f", &velocidade_kph);


    //Cálculo da soma e do produto
    velocidade_mph = velocidade_kph / 1.609344;

    //Saída dos dados. Retorno dos dados para o usuário
    printf("\nkph \t\t\tmph\n");
    printf("%.2f\t\t\t%.2f\n\n", velocidade_kph, velocidade_mph);

    return 0;
}
