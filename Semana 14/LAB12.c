#include<stdio.h>
#include<string.h>

#define N 10

void imprime(int, char [N], char [N]);

void main(){

    char p[N+1]={};
    char q[N+1]={};

    printf("Informe a primeira palavra.: ");
    fflush(stdin);
    scanf("%s", p);

    printf("Informe a segunda palavra..: ");
    fflush(stdin);
    scanf("%s", q);

    printf("\n%s\n", p);
    printf("%s\n\n", q);

    imprime(N, p, q);
}

void imprime(int tam, char p1[tam], char p2[tam]){
    for (int i=0; i<N; i++){
        if (p1[i] != '\0'){
            printf("%c", p1[i]);
        }
        if (p2[i] != '\0'){
            printf("%c", p2[i]);
        }

    }
}
