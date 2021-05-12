#include <stdio.h>

/* Este c�digo recebe do usu�rio tr�s valores  reais
e efetua a soma e o produto deles. Posteriormente
essa soma e produto s�o exibidos na tela com  uma
precis�o de duas casas decimais.


Assume-se que os valores de entrada sejam n�meros reais v�lidos
*/

int main (){
    //Declara��o das vari�veis
    float R1, R2, R3;
    float Soma, Produto;

    //Atribuio��o de Valores iniciais
    R1 = R2 = R3 = 0.0;


    //Entrada dos valores pelo usu�rio
    printf("Informe o primeiro valor: ");
    scanf("%f", &R1);
    printf("Informe o segundo valor : ");
    scanf("%f", &R2);
    printf("Informe o terceiro valor: ");
    scanf("%f", &R3);

    //C�lculo da soma e do produto
    Soma = R1 + R2 + R3;
    Produto = R1 * R2 * R3;

    //Sa�da dos dados. Retorno dos dados para o usu�rio
    printf("\n \nSoma dos dos tres valores informados   : %.2f ", Soma);
    printf("\nProduto dos dos tres valores informados: %.2f \n\n", Produto);
    /*
    Para valores muito grandes de R1, R2 ou R3 pode ocorrer de haver contaminacao do resultado pelo truncamento.
    Ainda, usando float resultados pr�ximos � 8 bytes apresentam esse problema.
    */

    return 0;
}
