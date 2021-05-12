#include<stdio.h>
#include <windows.h>
#include<time.h>
#include<string.h>

#define TAMANHO 20
int main(){
    //inicializa a semente
    srand(time(NULL));


    char textoAleat[TAMANHO + 1];
    char textoUsuario[TAMANHO + 1];

    for (int i=0; i<TAMANHO; i++){
        textoAleat[i] = GeraAscii();
        //printf("%c %d \n", textoAleat[i], textoAleat[i]);
    }
    printf("STRING gerada aleatoriamente: %s\n", textoAleat);
    ordenaString(textoAleat);
    printf("STRING ordenada: %s\n", textoAleat);
    int flag;
    do{
        flag=1;
        fflush(stdin);
        printf("\nInforme um texto com %d caracteres (somente letras minusculas sem espacos): ", TAMANHO);
        scanf("%s", textoUsuario);
        if (strlen(textoUsuario)==TAMANHO){
            for (int i=0; i<TAMANHO; i++){
                if (textoUsuario[i]<97 || textoUsuario[i]>122){
                    flag=0;
                }
            }
        }
        else{
            flag=0;
        }
    } while(!flag);
    ordenaString(textoUsuario);
    printf("STRING do usuario ordenada: %s\n", textoUsuario);
    //if (strlen(textoAleat) == strlen(textoUsuario)){ //ou seja, tamanho = TAMANHO. Tbm significa que o usuario nao colocou um espaco
        if (!strcmp(textoAleat, textoUsuario)){
            printf("\n\nA string informada pelo usuario eh um anagrama da palavra gerada aleatoriamente\n\n");
        }
        else{
            printf("\n\nA string informada pelo usuario nao eh um anagrama da palavra gerada aleatoriamente\n\n");
        }
    //}
    //else{
    //    printf("\n\nA string informada pelo usuario nao eh um anagrama da palavra gerada aleatoriamente\n\n");
    //}
}

void ordenaString(char texto[TAMANHO+1]){
    int max = TAMANHO-1; //poderia ser strlen(texto)-1
    int flag;
    int troca;
    do{
        flag = 0;
        for (int j=0; j<max; j++){
            if (texto[j]>texto[j+1]){
                char temp = texto[j];
                texto[j] = texto[j+1];
                texto[j+1] = temp;
                flag = 1;
                troca = j;
            }
        }
        max = troca;
    } while (flag);
    //return(texto);
}

int GeraAscii(){
    int rnd;
    rnd = rand()%26 + 97;
    return(rnd);
}
