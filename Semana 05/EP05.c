#include<stdio.h>
#include <windows.h>
#include <stdlib.h>


void gotoxy( int column, int line ){
    //Posiciona o cursor na tela
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
}

void box(int x1,int y1,int x2,int y2,int Linha){
    //Cria um retangulo na tela
    //1 = Borda Simples, 2 = Borda Dupla, Outro Valor = Sem Borda

    char Caracter1, Caracter2;
    if (Linha==2){
        Caracter1 = 205;
        Caracter2 = 186;
    }
    else if (Linha==1){
        Caracter1 = 196;
        Caracter2 = 179;
    }
    else{
        Caracter1 = ' ';
        Caracter2 = ' ';
    }
    int xMenor, xMaior, yMenor, yMaior;
    if (x1 > x2){
        xMaior = x1;
        xMenor = x2;
    }
    else{
        xMaior = x2;
        xMenor = x1;
    }
    if (y1>y2) {
        yMaior = y1;
        yMenor = y2;
    }
    else{
        yMaior = y2;
        yMenor = y1;
    }

    gotoxy(xMenor, yMenor);
    for (int i=0; i<(xMaior - xMenor);i++){
        printf("%c",Caracter1);
    }

    gotoxy(xMenor, yMaior);
    for (int i=0; i<(xMaior - xMenor);i++){
        printf("%c",Caracter1);
    }

    gotoxy(xMenor, yMenor+1);
    for (int i=0; i<(yMaior - yMenor-1);i++){
        gotoxy(xMenor, yMenor+1+i);
        printf("%c",Caracter2);
    }

    gotoxy(xMaior, yMenor);
    for (int i=0; i<(yMaior - yMenor-1);i++){
        gotoxy(xMaior, yMenor+1+i);
        printf("%c",Caracter2);
    }

    gotoxy(xMenor,yMenor);
    if (Linha==2){
        printf("%c",201);
    }
    else if (Linha==1){
        printf("%c",218);
    }
    else{
        printf("%c",' ');
    }

    gotoxy(xMaior,yMenor);
    if (Linha==2){
        printf("%c",187);
    }
    else if (Linha==1){
        printf("%c",191);
    }
    else{
        printf("%c",' ');
    }

    gotoxy(xMenor,yMaior);
    if (Linha==2){
        printf("%c",200);
    }
    else if (Linha==1){
        printf("%c",192);
    }
    else{
        printf("%c",' ');
    }

    gotoxy(xMaior,yMaior);
    if (Linha==2){
        printf("%c",188);
    }
    else if (Linha==1){
        printf("%c",217);
    }
    else{
        printf("%c",' ');
    }

    for (int j=yMenor+1; j<yMaior; j++){
        for(int i=xMenor+1; i<xMaior; i++){
            gotoxy(i, j);
            printf(" ");
        }
    }

}

void SetCor(int CorLetra, int CorFundo){
    /*
    0 - Preto       8  - Cinza
    1 - Azul        9  - Azul Claro
    2 - Verde       10 - Verde Claro
    3 - Ciano       11 - Ciano Claro
    4 - Vermelho    12 - Vermelho Claro
    5 - Rosa        13 - Rosa Claro
    6 - Amarelo     14 - Amarelo Claro
    7 - Branco      15 - Branco
    */
    int Cor;
    Cor = CorLetra + 16 * CorFundo;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cor);
}

void sombra(int x1, int y1, int x2, int y2, int Caracter){
    //cria um efeito de sombra em um retangulo
    int xMenor, xMaior, yMenor, yMaior;
    if (x1 > x2){
        xMaior = x1;
        xMenor = x2;
    }
    else{
        xMaior = x2;
        xMenor = x1;
    }
    if (y1>y2) {
        yMaior = y1;
        yMenor = y2;
    }
    else{
        yMaior = y2;
        yMenor = y1;
    }
    SetCor(1,0);
    for (int j=yMenor+1;j<yMaior+1;j++){
        gotoxy(xMaior+1,j);
        printf("%c%c",Caracter,Caracter);
    }
    gotoxy(xMenor+2,yMaior+1);
    for (int i=xMenor+2; i<xMaior+3; i++){
        printf("%c",Caracter);
    }
}

void info(char* texto){
    SetCor(3,15);
    gotoxy(15,29);
    for (int i=15;i<119;i++){
        printf(" ");
    }
    gotoxy(15,29);
    printf("%s", texto);
}

void ImprimeTela(){
    SetCor(3,15);
    gotoxy(119,29);
    printf(" ");
    for (int j=0; j<29; j++){
        gotoxy(0,j);
        for (int i=0; i<120; i++){
            printf("%c", 178);
        }
    }

    //Cabecalho
    box(9,1,109,6,0);
    //Imprime a sombra do Cabecalho
    //SetCor(1,0);
    sombra(9,1,109,6,178);

    SetCor(3,15);
    gotoxy(42,1);
    printf("INF01040 - Introducao a Programacao");
    gotoxy(44,2);
    printf("Modalidade a Distancia - 2018/2");
    gotoxy(49,3);
    printf("5%c Entrega Programada", 166);
    gotoxy(11,5);
    printf("Nome.........: Luciano da Silva Berchon");
    gotoxy(11,6);
    printf("Cartao UFRGS.: 00136478");

    //Rodape
    //box(0,29,118,29,0);
    gotoxy(0,29);
    for (int i=0;i<119;i++){
        printf(" ");
    }
    gotoxy(1,29);
    printf("Informacoes |");

    SetCor(3,15);
    box(4,11,34,18,2);
    box(6,14,32,17,1);
    //SetCor(1,0);
    sombra(4,11,34,18,178);

    SetCor(3,15);
    gotoxy(6,12);
    printf("GRENAL numero [");
    gotoxy(8,14);
    printf("Placar do GRENAL");
    gotoxy(8,15);
    printf("Gols do Gremio.:");
    gotoxy(8,16);
    printf("Gols do Inter..:");

    SetCor(15,3);
    gotoxy(25,15);
    printf("      ");
    SetCor(15, 7);
    gotoxy(25,16);
    printf("      ");

    SetCor(3,15);

}



int main(){
    //declaracao de variaveis
    int numeroGrenais=0;
    int vitoriasGremio=0;
    int vitoriasInter=0;
    int empates=0;
    int golsGremio=0;
    int golsInter=0;
    int flag = 1;
    int flag1= 1;
    int placarGremio = 0;
    int placarInter=0;
    //esse laco sera executado ate o usuario informar que não quer mais lancar os resultados dos grenais, que implica em flag=0
    while(flag){
        numeroGrenais++;
        ImprimeTela();
        SetCor(12,15);
        gotoxy(21,12);
        printf("%d",numeroGrenais);
        SetCor(3,15);
        printf("]");
        info("Informe o numero de gols que o Gremio fez durante a partida.");
        SetCor(15,3);
        //esse laco sera executado enquanto o usuario nao informar um numero positivo
        while (flag1){
            gotoxy(25,15);
            scanf("%d",&placarGremio);
            if (placarGremio>=0){
                flag1=0;
            }
            gotoxy(25,15);
            printf("      ");
        }
        SetCor(0,7);
        gotoxy(25,15);
        printf("      ");
        gotoxy(25,15);
        printf("%d",placarGremio);
        SetCor(15,3);
        gotoxy(25,16);
        printf("      ");
        flag1=1;
        info("Informe o numero de gols que o Inter fez durante a partida.");
        SetCor(15,3);

        //esse laco sera executado enquanto o usuario nao informar um numero positivo
        while (flag1){
            gotoxy(25,16);
            scanf("%d",&placarInter);
            if (placarInter>=0){
                flag1=0;
            }
            gotoxy(25,16);
            printf("      ");
        }
        SetCor(0,7);
        gotoxy(25,16);
        printf("      ");
        gotoxy(25,16);
        printf("%d",placarInter);
        flag1=1;
        //incremento das variaveis de interesse
        if (placarGremio>placarInter){
            vitoriasGremio++;
        }
        else if (placarGremio<placarInter){
            vitoriasInter++;
        }
        else{
            empates++;
        }
        golsGremio+=placarGremio;
        golsInter+=placarInter;

        SetCor(3,15);
        box(44,20,75,22,2);
        sombra(44,20,75,22,178);
        SetCor(3,15);
        gotoxy(46,21);
        printf("Novo grenal (1-sim 2-nao)? ");
        info("Informe \'1\' para seguir cadastrando GRENAIS ou \'0\' para sair");
        SetCor(15,3);

        //esse laco sera executado enquanto o usuario nao informar o numero 1 ou o 2
        while (flag1){
            gotoxy(73,21);
            printf(" ");
            gotoxy(73,21);
            scanf("%d",&flag);
            if (flag==1 || flag==2){
                flag1=0;
            }

        }
        flag1=1;
        //condicao para sair do laco
        if (flag==2){
            flag=0;
        }

    }




    SetCor(7,0);
    system("cls");

    //criacao de uma tabela com o resumo dos resultados
    SetCor(3,15);
    box(2,1,59,11,1);

    gotoxy(4,2);
    printf("\t\t\t\tGremio\t\t Inter");
    gotoxy(4,4);
    printf("Vitorias");
    gotoxy(4,5);
    printf("Empates");
    gotoxy(4,6);
    printf("Derrotas");
    gotoxy(4,7);
    printf("Gols Pro");
    gotoxy(4,8);
    printf("Gols Contra");
    gotoxy(4,10);
    printf("Numero de GRENAIS");

    SetCor(0,15);
    gotoxy(31,4);
    printf("%d\t\t%d",vitoriasGremio,vitoriasInter);
    gotoxy(31,5);
    printf("%d\t\t%d",empates,empates);
    gotoxy(31,6);
    printf("%d\t\t%d",vitoriasInter,vitoriasGremio);
    gotoxy(31,7);
    printf("%d\t\t%d",golsGremio,golsInter);
    gotoxy(31,8);
    printf("%d\t\t%d",golsInter,golsGremio);
    gotoxy(31,10);
    printf("%d",numeroGrenais);

    //cantos das bordas das tabelas
    SetCor(3,15);
    for (int i=3;i<59;i++){
        gotoxy(i,3);
        printf("%c",196);
        gotoxy(i,9);
        printf("%c",196);
    }

    gotoxy(2,3);
    printf("%c",195);
    gotoxy(2,9);
    printf("%c",195);

    gotoxy(59,3);
    printf("%c",180);
    gotoxy(59,9);
    printf("%c",180);


    for (int i=2;i<9;i++){
        gotoxy(26,i);
        printf("%c",179);
        gotoxy(43,i);
        printf("%c",179);
    }
    gotoxy(26,1);
    printf("%c",194);
    gotoxy(43,1);
    printf("%c",194);

    gotoxy(26,9);
    printf("%c",193);
    gotoxy(43,9);
    printf("%c",193);

    gotoxy(26,3);
    printf("%c",197);
    gotoxy(43,3);
    printf("%c",197);


    box(2,15,59,17,2);
    gotoxy(4,16);
    if (vitoriasGremio>vitoriasInter){
        printf("O Gremio ganhou a maioria dos Grenais");
    }
    else if (vitoriasGremio<vitoriasInter){
        printf("O Inter ganhou a maioria dos Grenais");
    }
    else{
        printf("Nao houve vencedor");
    }


    SetCor(15,0);
    gotoxy(0,20);
    printf("Programador.....: Luciano Berchon\n");
    printf("Cartao UFRGS....: 00136478\n");
    printf("Data de entrega.: 04/09/2018\n\n\n");
    SetCor(0,0);

}
