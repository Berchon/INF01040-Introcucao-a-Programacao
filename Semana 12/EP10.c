#include<stdio.h>
#include<time.h>

int Dados(){
    return(rand()%6);
}

#define N 1000
void main(){
    //inicializa a semente
    srand(time(NULL));

    int resultados[6]={};
    int a;
    for(int i=0; i<N; i++){
        //a = Dados();
        //resultados[a]++;
        //printf("%d\n", a+1);
        resultados[Dados()]++;

    }

    for(int i=0; i<6; i++){
        printf("O numero %d saiu em %.2f %% das jogadas (%d vezes).\n", i+1, (float)100*resultados[i]/N, resultados[i]);
    }

}
