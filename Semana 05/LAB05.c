#include<stdio.h>
#include <windows.h>
#include <stdlib.h>


void gotoxy( int column, int line ){
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
}

void box(int x1,int y1,int x2,int y2,int Linha){
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

void Sombra(int x1, int y1, int x2, int y2, int Caracter){
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
    for (int j=yMenor+1;j<yMaior+1;j++){
        gotoxy(xMaior+1,j);
        printf("%c%c",Caracter,Caracter);
    }
    gotoxy(xMenor+2,yMaior+1);
    for (int i=xMenor+2; i<xMaior+3; i++){
        printf("%c",Caracter);
    }
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
    SetCor(1,0);
    Sombra(9,1,109,6,178);

    SetCor(3,15);
    gotoxy(42,1);
    printf("INF01040 - Introducao a Programacao");
    gotoxy(44,2);
    printf("Modalidade a Distancia - 2018/2");
    gotoxy(48,3);
    printf("5%c Laboratorio Virtual", 248);
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
    gotoxy(15,29);
    printf("Informe um numero inteiro positivo \'n\' para obter o \'somatorio(n)\'. Para sair informe o numero 0.");

    box(4,20,57,22,1);
    SetCor(1,0);
    Sombra(4,20,57,22,178);

    SetCor(3,15);
    box(4,15,57,17,1);
    SetCor(1,0);
    Sombra(4,15,57,17,178);

    SetCor(3,15);
    gotoxy(6,16);
    printf("Informe um valor para n: ");

    SetCor(15,3);
    printf("                         ");

    SetCor(3,15);

}



int main(){
    unsigned long long int soma, n;
    n=0;
    soma=0;





    do{
        ImprimeTela();

        gotoxy(6,21);
        printf("Somatorio(");
        SetCor(12,15);
        printf("%llu",n);
        SetCor(3,15);
        printf(") = ");
        SetCor(12,15);
        printf("%llu", soma);

        //limpando as variaveis
        n=0;
        soma=0;

        SetCor(15,3);
        gotoxy(31,16);
        scanf("%llu", &n);
        for (unsigned long long i=n; i>0; i--){
            gotoxy(27,10);
            printf("%llu",n);
            soma = soma + i;
        }
    } while (n!=0);

    SetCor(7,0);
    system("cls");
    SetCor(9,0);
    gotoxy(0,3);
    printf("Programador.....: Luciano Berchon\n");
    printf("Cartao UFRGS....: 00136478\n");
    printf("Data de entrega.: 04/09/2018\n\n\n");




}
