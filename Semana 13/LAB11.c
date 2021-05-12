#include<stdio.h>

int linha(int N, int M, char carac){
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            printf("%c", carac);
        }
        printf("\n");
    }
}

void main(){
    int N,M;
    char carac;
    printf("Informe o Caracter a ser impresso: ");
    scanf("%c", &carac);
    printf("Informe o numero de linhas a ser impresso: ");
    scanf("%d", &M);
    printf("Informe o numero de repeticoes do caracter em cada linha: ");
    scanf("%d", &N);

    printf("\n\n");
    linha(N, M, carac);
}
