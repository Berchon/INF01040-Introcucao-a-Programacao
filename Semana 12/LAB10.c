#include<stdio.h>

int LerIdade(int NumeroAluno){
    int idade;
    do{
        printf("Informe a idade do Aluno %d (Entre 4 e 14):", NumeroAluno);
        scanf("%d", &idade);
        if (idade>=4 && idade<=14){
            return (idade);
        }else
            printf("\n\nAtencao!!! Voce deve informar uma idade entre 4 e 14 anos (inclusives).\n\n");
    } while(1);
}

void main(){
    int N = 5;
    int maior=0;
    int menor=15;
    float media=0;
    for (int i=0; i<N; i++){
        int idade;
        idade=LerIdade(i+1);
        media+=idade;
        if (maior<idade)
            maior = idade;
        if (menor>idade)
            menor=idade;
    }
    media = media/N;
    printf("\n\nA media de idade informada eh %.2f anos.", media);
    printf("\nA maior idade informada eh %d anos.", maior);
    printf("\nA menor idade informada eh %d anos.\n\n", menor);
}
