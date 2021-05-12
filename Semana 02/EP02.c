#include <stdio.h>

/* Este c�digo recebe do usu�rio um valor de velocidade
em km/h e converte para mi/h. Posteriormente essas duas
velocidades s�o exibidas na tela usando tabula��o.

Assume-se que os valores de entrada sejam n�meros reais v�lidos
*/

int main (){
    //Declara��o das vari�veis
    float velocidade_kph, velocidade_mph;

    //Atribuio��o de Valores iniciais
    velocidade_kph = 0.0;


    //Entrada dos valores pelo usu�rio
    printf("Digite a velocidade em kph: ");
    scanf("%f", &velocidade_kph);


    //C�lculo da soma e do produto
    velocidade_mph = velocidade_kph / 1.609344;

    //Sa�da dos dados. Retorno dos dados para o usu�rio
    printf("\nkph \t\t\tmph\n");
    printf("%.2f\t\t\t%.2f\n\n", velocidade_kph, velocidade_mph);

    return 0;
}
