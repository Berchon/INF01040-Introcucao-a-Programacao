#include <stdio.h>

/* Este código recebe do usuário três valores  reais
e efetua a soma e o produto deles. Posteriormente
essa soma e produto são exibidos na tela com  uma
precisão de duas casas decimais.


Assume-se que os valores de entrada sejam números reais válidos
*/

int main (){
    //Declaração das variáveis
    float R1, R2, R3;
    float Soma, Produto;

    //Atribuioção de Valores iniciais
    R1 = R2 = R3 = 0.0;


    //Entrada dos valores pelo usuário
    printf("Informe o primeiro valor: ");
    scanf("%f", &R1);
    printf("Informe o segundo valor : ");
    scanf("%f", &R2);
    printf("Informe o terceiro valor: ");
    scanf("%f", &R3);

    //Cálculo da soma e do produto
    Soma = R1 + R2 + R3;
    Produto = R1 * R2 * R3;

    //Saída dos dados. Retorno dos dados para o usuário
    printf("\n \nSoma dos dos tres valores informados   : %.2f ", Soma);
    printf("\nProduto dos dos tres valores informados: %.2f \n\n", Produto);
    /*
    Para valores muito grandes de R1, R2 ou R3 pode ocorrer de haver contaminacao do resultado pelo truncamento.
    Ainda, usando float resultados próximos à 8 bytes apresentam esse problema.
    */

    return 0;
}
