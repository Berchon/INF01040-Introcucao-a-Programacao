#include<stdio.h>

#define N 5

typedef struct {
    char nome[50];
    int cavalos;
    float preco;
} carro;

carro ler_carro();
void imprime_carro(carro);

void main(){
    carro car[N];
    float max_val;
    for (int i=0; i<N; i++){
        printf(" CARRO %d\n", i+1);
        printf("=========\n");
        car[i] = ler_carro();
        //imprime_carro(car[i]);
    }
    printf("Informe o valor maximo que voce deseja gastar (R$): ");
    fflush(stdin);
    scanf("%f", &max_val);

    int contador=0;
    for (int i=0; i<N; i++){
        if (car[i].preco<=max_val)
            contador++;
    }

    if (contador == 0){
        printf("\n\nCom o valor de R$ %.2f voce nao conseguira comprar nenhum carro!!!", max_val);
    }
    else{
        printf("\n\nVoce conseguira comprar os seguintes carros:\n");
        for (int i=0; i<N; i++){
            if (car[i].preco<=max_val)
                printf("\t%s\n", car[i].nome);
        }
    }
    printf("\n\n");
}

carro ler_carro(){
    carro carro;
    printf("Informe o nome do carro: ");
    fflush(stdin);
    gets(carro.nome);
    printf("Informe quantos cavalos possui o carro (CV): ");
    fflush(stdin);
    scanf("%d", &carro.cavalos);
    printf("Informe o preco do carro (R$): ");
    fflush(stdin);
    scanf("%f", &carro.preco);
    printf("\n\n");
    return carro;
}

void imprime_carro(carro carro){
    printf("\nO nome do carro eh %s", carro.nome);
    printf("\nO carro possui %d cavalos", carro.cavalos);
    printf("\nO preco do carro eh R$ %.2f\n\n", carro.preco);
}
