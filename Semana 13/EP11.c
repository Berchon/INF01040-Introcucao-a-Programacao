#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ler_jogada(){
    int escolha;
    int flag = 1;
    printf("Digite 1 para escolher PEDRA\n");
    printf("Digite 2 para escolher PAPEL\n");
    printf("Digite 3 para escolher TESOURA\n\n");

    printf("Informe sua jogada: ");
    scanf("%d", &escolha);
    if (escolha<1 || escolha>3){
        printf("\n\n\nEscolha invalida!!! Informe o numero 1, 2 ou 3.\n\n");
        escolha = ler_jogada();
    }
    return (escolha);
}

void imprime_jogada(int numeroUsuario, int flag){
    if (flag){
        printf("Voce ");
    }
    else{
        printf("O computador ");
    }
    switch (numeroUsuario){
        case 1:
            printf("escolheu PEDRA!\n");
            break;
        case 2:
            printf("escolheu PAPEL!\n");
            break;
        case 3:
            printf("escolheu TESOURA!\n");
            break;
    }
}

int calcula_resultado(int jogadaUsuario, int jogadaComputador){
    if ((jogadaUsuario==1 && jogadaComputador==2) || (jogadaUsuario==2 && jogadaComputador==1)){
        printf("\nPapel cobre pedra");
    }
    else if ((jogadaUsuario==1 && jogadaComputador==3) || (jogadaUsuario==3 && jogadaComputador==1)){
        printf("\nPedra amassa tesoura");
    }
    else if ((jogadaUsuario==3 && jogadaComputador==2) || (jogadaUsuario==2 && jogadaComputador==3)){
        printf("\nTesoura corta papel");
    }

    if (jogadaUsuario==jogadaComputador){
        return(1);
    }
    else if ((jogadaUsuario==1 && jogadaComputador==3) ||
             (jogadaUsuario==2 && jogadaComputador==1) ||
             (jogadaUsuario==3 && jogadaComputador==2)){
        return (2);
    }
    else if ((jogadaUsuario==1 && jogadaComputador==2) ||
             (jogadaUsuario==2 && jogadaComputador==3) ||
             (jogadaUsuario==3 && jogadaComputador==1)){
        return(3);
    }
}

int sorteia_jogada(){
    return(rand()%3 + 1);
}

void main(){
    //inicializa a semente
    srand(time(NULL));

    int jogadaUsuario, jogadaComputador, resultado, flag;
    do{
        jogadaUsuario=ler_jogada();
        jogadaComputador=sorteia_jogada();

        printf("\n");
        imprime_jogada(jogadaUsuario, 1);
        imprime_jogada(jogadaComputador, 0);

        resultado=calcula_resultado(jogadaUsuario, jogadaComputador);
        printf("\n\n");
        switch (resultado){
            case 1:
                printf("Houve empate!");
                flag=1;
                getch();
                system("cls");
                break;
            case 2:
                printf("O usuario venceu!");
                flag=0;
                break;
            case 3:
                printf("O computador venceu!");
                flag=0;
                break;
        }
        printf("\n\n");
    } while(flag);
}
