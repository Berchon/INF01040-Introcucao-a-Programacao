#include <stdio.h>

/* Este c�digo recebe do usu�rio dois valores  reais
e efetua a m�dia aritm�tica entre eles. Posteriormente
� testado se essa m�dia � superior ou igual a 6. Caso
verdadeiro � informado que o aluno PASSOU caso contr�rio
que o aluno REPETIU


Assume-se que os valores de entrada sejam n�meros reais v�lidos
*/

int main (){
    //Declara��o das vari�veis
    float N1, N2;


    //Atribuio��o de Valores iniciais
    N1 = N2 = 0.0;


    //Entrada dos valores pelo usu�rio
    printf("Informe a nota da primeira prova : ");
    scanf("%f", &N1);
    printf("Informe a nota da segunda prova  : ");
    scanf("%f", &N2);


    //Calcula a m�dia e testa se � >= a 6.0
    if ((N1 + N2)/2 >= 6.0){
        printf("\nAluno aprovado - Passou\n\n");
    }else{
        printf("\nAluno reprovado - Repetiu\n\n");
    }

    printf("\n%f\n", (N1 + N2)/2);

    //Este programa calcula a m�dia corretamente at� a SEXTA CASA DECIMAL
    return 0;
}
