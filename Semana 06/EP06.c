#include<stdio.h>
#include <windows.h>


int main(){

    int N=0;
    int soma=0;

    do{
        printf("Informe um numero inteiro maior que Zero: ");
        scanf("%d", &N);
    }while(N<=0);
    for(int i=1; i<N; i++){
        if (N%i == 0)
            soma+=i;
    }
    if (soma==N){
        printf("\nO numero %d eh um numero Perfeito\n\n", N);
    }
    else{
        printf("\nO numero %d nao eh um numero Perfeito\n\n", N);
    }
}

