/////////////////////////////////////////////////////////////////////////////////
//


#include<stdio.h>

#define Nro_Alunos 1
#define Nro_Notas 15

void imprime(int, float []);
float MenorValor(int, float []);
float MaiorValor(int, float []);
float Nro_Ocorrencias(float, int, float []);
void media(int, float []);
float somarValores(int, float []);

void main(){
    float notas[Nro_Notas];
    for (int i=0; i<Nro_Alunos; i++){
        printf(" Aluno %d\n=========\n", i+1);
        printf("Informe as notas do Aluno\n\n");
        for (int j=0; j<Nro_Notas; j++){
            printf(" Nota %d: ", j+1);
            scanf(" %f", &notas[j]);

        }
        printf("\n\n");
    }
    media(Nro_Notas, notas);


}

float somarValores(int tam, float v[tam]){
    float soma=0;
    for (int i=0; i<tam; i++){
        soma += v[i];
    }
    printf("soma %f\n", soma);
    return soma;
}

void media(int tam, float v[tam]){
    //imprime(tam, v);

    int nro_ocorrencias_maior, nro_ocorrencias_menor;
    float menor, maior, media, soma=0;
    menor = MenorValor(tam, v);
    maior = MaiorValor(tam, v);

    nro_ocorrencias_menor = Nro_Ocorrencias(menor, tam, v);
    nro_ocorrencias_maior = Nro_Ocorrencias(maior, tam, v);

    soma = somarValores(tam, v) - menor*nro_ocorrencias_menor - maior*nro_ocorrencias_maior;
    printf("soma %f\n", soma);
    printf("tam %d   %f   %f\n", tam, menor*nro_ocorrencias_menor, maior*nro_ocorrencias_maior);
    media = (float) soma / (tam - nro_ocorrencias_menor - nro_ocorrencias_maior);

    printf("Menor %f - %d\n", menor, nro_ocorrencias_menor);
    printf("Maior %f - %d\n", maior, nro_ocorrencias_maior);
    printf("Media %.2f", media);
}

float Nro_Ocorrencias(float valor, int tam, float v[tam]){
    int Nro_Ocorrencias=0;
    for (int i=0; i<tam; i++){
        if(v[i]==valor)
            Nro_Ocorrencias++;
    }
    return Nro_Ocorrencias;
}

float MaiorValor(int tam, float v[tam]){
    float maior=v[0];
    for (int i=0; i<tam; i++){
        if(v[i]>maior)
            maior=v[i];
    }
    return maior;

}

float MenorValor(int tam, float v[tam]){
    float menor=v[0];
    for (int i=0; i<tam; i++){
        if(v[i]<menor)
            menor=v[i];
    }
    return menor;

}
void imprime(int tam, float v[tam]){
    for (int i=0; i<tam; i++){
        printf("%f\n", v[i]);
    }
}
