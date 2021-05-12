#include<stdio.h>

void main(){
    char L1, L2;
    char nomeArq[256+4];
    char letra;

    printf("Informe a letra que deseja substituir no arquivo texto: ");
    scanf("%c", &L1);
    printf("Informe qual letra que deseja colocar no arquivo texto: ");
    fflush(stdin);
    scanf("%c", &L2);

    printf("Informe o nome do arquivo que sera efetuada a troca: ");
    scanf("%s", nomeArq);

    FILE *fpOrigem;
    FILE *fpDestino;
    fpOrigem = fopen(nomeArq, "r");
    fpDestino = fopen("teste.txt", "w");
    if (fpOrigem == NULL){
        printf("\n\nERRO! Nao foi possivel abrir o arquivo de dados.\n");
        system("pause");
        return;
    }
    if (fpDestino == NULL){
        printf("\n\nERRO! Nao foi possivel abrir o arquivo de dados.\n");
        system("pause");
        return;
    }

    while(!feof(fpOrigem)){
        letra = fgetc(fpOrigem);
        if (letra == L1)
            letra = L2;
        if (letra != EOF)
            fputc(letra, fpDestino);
        printf("%c", letra);
    }
    fclose(fpOrigem);
    fclose(fpDestino);
}
