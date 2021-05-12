#include <stdio.h>

/* Este código recebe do usuário a altura de 3 pessoas. Informa o
nro de pessoas que tem altura menor que 1.5 m  e o número de pessoas
que tem altura maior ou igual a 1.5m. Ainda calcula a média das alturas
e diz se essa média é superior ou inferior a 1.5 m.


Assume-se que os valores de entrada sejam números reais válidos
*/

int main (){
    //Declaração das variáveis
    float h1, h2, h3;
    float media;


    //Atribuioção de Valores iniciais
    h1 = h2 = h3 = 0.0;


    //Entrada dos valores pelo usuário
    printf("Informe a altura da primeira pessoa : ");
    scanf("%f", &h1);
    printf("Informe a altura da segunda pessoa  : ");
    scanf("%f", &h2);
    printf("Informe a altura da terceira pessoa : ");
    scanf("%f", &h3);

    //Cálculo da média das alturas
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

    //testa se a média é < que 1.5 m
    if (media>1.5f){
        printf("\nMedia superior a 1.5 metros\n\n");
    }else{
        printf("\nMedia inferior a 1.5 metros\n\n");

        //Se a média for 1.5 metros entrará nessa condicao.

    }

    //Este programa calcula a média corretamente até a SEXTA CASA DECIMAL
    return 0;
}
