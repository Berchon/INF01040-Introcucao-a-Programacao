#include <stdio.h>

/* Este código recebe do usuário dois valores  reais
e efetua a média aritmética entre eles. Posteriormente
é testado se essa média é superior ou igual a 6. Caso
verdadeiro é informado que o aluno PASSOU caso contrário
que o aluno REPETIU


Assume-se que os valores de entrada sejam números reais válidos
*/

int main (){
    //Declaração das variáveis
    float N1, N2;


    //Atribuioção de Valores iniciais
    N1 = N2 = 0.0;


    //Entrada dos valores pelo usuário
    printf("Informe a nota da primeira prova : ");
    scanf("%f", &N1);
    printf("Informe a nota da segunda prova  : ");
    scanf("%f", &N2);


    //Calcula a média e testa se é >= a 6.0
    if ((N1 + N2)/2 >= 6.0){
        printf("\nAluno aprovado - Passou\n\n");
    }else{
        printf("\nAluno reprovado - Repetiu\n\n");
    }

    printf("\n%f\n", (N1 + N2)/2);

    //Este programa calcula a média corretamente até a SEXTA CASA DECIMAL
    return 0;
}
