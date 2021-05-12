#include<stdio.h>

void main(){
    FILE *fp;

    fp = fopen("dados.txt", "w");
    if (fp == NULL){
        printf("Erro ao criar o arquivo!");
        return;
    }
    for (int i=1; i<101; i++){
        if (i==100)
            fprintf(fp, "%d", i);
        else
            fprintf(fp, "%d\n", i);
    }
    fclose(fp);
    return;
}
