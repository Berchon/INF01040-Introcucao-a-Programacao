#include<stdio.h>
#include <windows.h>



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

#define N 3

int main(){
    int A[N][N];

    Tela();

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            gotoxy(14, 29);
            printf("Informe um valor inteiro entre 1 e 30 (inclusives) para o elemento da %d%c linha e %d%c coluna da matriz A.", i+1, 166, j+1, 166);
            do{
                gotoxy(37+20*j,5+i*2);
                printf("          ");
                gotoxy(37+20*j,5+i*2);
                scanf("%d", &A[i][j]);
            } while(A[i][j]<1 || A[i][j]>30);
        }
    }

    Tela2();
    SetCor(15,9);
    for (int j=0; j<N; j++){
        int maior = 0;
        for (int i=0; i<N; i++){
            if (A[i][j]>maior){
                maior = A[i][j];
            }
        }
        for (int i=0; i<N; i++){
            if (A[i][j]==maior){
                SetCor(15,9);
            }
            else{
                SetCor(0,15);
            }
            gotoxy(12+4*j,18+2*i);
            printf("%2d", A[i][j]);
        }
    }

    int tecla;
    Status("Pressione qualquer tecla para sair.");
    tecla=getch();
    SetCor(7,0);
    system("cls");
}

void Status(char texto[]){
    SetCor(15,12);
    gotoxy(14, 29);
    printf("                                                                                                         ");
    gotoxy(14, 29);
    printf("%s", texto);
}

void Tela2(){
    SetCor(9,15);
    box(4,16,56,24,1);
    gotoxy(6,20);
    printf("A =");
    for (int i=0; i<N; i++){
        SetCor(9,15);
        for (int k=0; k<2; k++){
            gotoxy(10,18+i*2+k);
            printf("%c", 186);
            gotoxy(23,18+i*2+k);
            printf("%c", 186);
        }
    }
    gotoxy(10,17);
    printf("%c%c", 201, 205);
    gotoxy(22,17);
    printf("%c%c", 205, 187);
    gotoxy(10,23);
    printf("%c%c", 200, 205);
    gotoxy(22,23);
    printf("%c%c", 205, 188);

    SetCor(0,15);
    gotoxy(26,18);
    printf("LEGENDA");
    gotoxy(26,19);
    printf("=======");
    gotoxy(29,20);
    printf("Maior valor de cada coluna");

    gotoxy(26,20);
    SetCor(15,9);
    printf("##");
}

void Tela(){
    SetCor(12,15);
    box(29,3,90,11,1);
    gotoxy(31,7);
    printf("A =");


    for (int i=0; i<N; i++){
        SetCor(12,15);
        for (int k=0; k<2; k++){
            gotoxy(35,5+i*2+k);
            printf("%c", 186);
            gotoxy(88,5+i*2+k);
            printf("%c", 186);
        }
        SetCor(15,12);
        for(int j=0; j<N; j++){
            gotoxy(37+20*j,5+i*2);
            printf("          ");
        }
    }
    SetCor(12,15);
    gotoxy(35,4);
    printf("%c%c", 201, 205);
    gotoxy(87,4);
    printf("%c%c", 205, 187);
    gotoxy(35,10);
    printf("%c%c", 200, 205);
    gotoxy(87,10);
    printf("%c%c", 205, 188);

    SetCor(15,12);
    for (int i=0; i<120; i++){
        gotoxy(i, 29);
        printf(" ");
    }
    gotoxy(0,0);
    gotoxy(1, 29);
    printf("Informacao %c", 179);

}
