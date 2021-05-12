#include<stdio.h>
#include <windows.h>
#include<string.h>

#define TAMANHO 100
int main(){

    char textoInvertido[TAMANHO + 1];
    char textoUsuario[TAMANHO + 1];

    printf("Informe um texto com ate %d caracteres (somente letras minusculas sem espacos): ", TAMANHO);
    gets(textoUsuario);
    int len = strlen(textoUsuario)-1;
    for (int i=0; i<=len; i++){
        textoInvertido[i] = textoUsuario[len-i];
    }
    textoInvertido[len+1] = '\0';
    printf("\nString invertida: ");
    //fflush(stdin);
    puts(textoInvertido);

    if (strcmp(textoUsuario, textoInvertido)){
        printf("\n\nA string digitada pelo usuario nao eh um palindromo\n\n");
    }
    else{
        printf("\n\nA string digitada pelo usuario eh um palindromo\n\n");
    }
}
