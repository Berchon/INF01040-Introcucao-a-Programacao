#include <stdio.h>

/* Este c�digo recebe do usu�rio a altura de 3 pessoas. Informa o
nro de pessoas que tem altura menor que 1.5 m  e o n�mero de pessoas
que tem altura maior ou igual a 1.5m. Ainda calcula a m�dia das alturas
e diz se essa m�dia � superior ou inferior a 1.5 m.


Assume-se que os valores de entrada sejam n�meros reais v�lidos
*/

int main (){
    //Declara��o das vari�veis
    float h1, h2, h3;
    float media;


    //Atribuio��o de Valores iniciais
    h1 = h2 = h3 = 0.0;


    //Entrada dos valores pelo usu�rio
    printf("Informe a altura da primeira pessoa : ");
    scanf("%f", &h1);
    printf("Informe a altura da segunda pessoa  : ");
    scanf("%f", &h2);
    printf("Informe a altura da terceira pessoa : ");
    scanf("%f", &h3);

    //C�lculo da m�dia das alturas
    media = (h1+h2+h3)/3;

    if (h1<1.5f && h2<1.5f && h3<1.5f){
        printf("\n3 pessoas possuem menos de 1.5 metros e nenhuma pessoa possui 1.5 metros ou mais");
    }else{
        if ((h1<1.5f && h2<1.5f) || (h1<1.5f && h3<1.5f) || (h2<1.5f && h3<1.5f)){
            printf("\n2 pessoas possuem menos de 1.5 metros e 1 pessoa possui 1.5 metros ou mais");
        }else{
            if (h1<1.5f || h2<1.5f || h3<1.5f){
                printf("\n1 pessoa possui menos de 1.5 metros e 2 pessoas possuem 1.5 metros ou mais");
            }else{
                printf("\nNenhuma pessoa possui menos de 1.5 metros e 3 pessoas possuem 1.5 metros ou mais");
            }
        }
    }

    printf("\nMedia entre as alturas: %.2f", media);

    //testa se a m�dia � < que 1.5 m
    if (media>1.5f){
        printf("\nMedia superior a 1.5 metros\n\n");
    }else{
        printf("\nMedia inferior a 1.5 metros\n\n");

        //Se a m�dia for 1.5 metros entrar� nessa condicao.

    }

    //Este programa calcula a m�dia corretamente at� a SEXTA CASA DECIMAL
    return 0;
}
