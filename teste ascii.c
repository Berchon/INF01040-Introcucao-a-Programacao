#include<stdio.h>

#include<fcntl.h>
#include<io.h>


int main(){
    // Converte a página de codigos atual para o padrao americano

    system("chcp 437");
    printf("%c",3);
    _setmode(_fileno(stdout), 0x20000);
    wprintf(L"\x263a");
}

