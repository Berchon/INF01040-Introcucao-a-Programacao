#include<stdio.h>
#include <windows.h>
#include<time.h>



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


int main(){
    //inicializa a semente
    srand(time(NULL));

    int tecla;

    int juiz1_A, juiz2_A, juiz3_A;
    int juiz1_V, juiz2_V, juiz3_V;
    int pontos_A, pontos_V;
    pontos_A=0;
    pontos_V=0;

    int round;

    SetCor(0,15);
    box(43,0,75,27,2);
    gotoxy(0,0);
    gotoxy(45,1);
    printf("Luvas");
    SetCor(1,15);
    gotoxy(55,1);
    printf("Azul");
    SetCor(4,15);
    gotoxy(66,1);
    printf("Vermelho");

    for (round=1; round<=5; round++){
        SetCor(2,15);
        gotoxy(45,3 + 5*(round-1));
        printf("Round %d", round);
        SetCor(0,15);
        gotoxy(45,4 + 5*(round-1));
        printf("Juiz 1            X");
        gotoxy(45,5 + 5*(round-1));
        printf("Juiz 2            X");
        gotoxy(45,6 + 5*(round-1));
        printf("Juiz 3            X");

        juiz1_A=Sorteio();
        juiz2_A=Sorteio();
        juiz3_A=Sorteio();

        juiz1_V=Sorteio();
        juiz2_V=Sorteio();
        juiz3_V=Sorteio();

        SetCor(1,15);
        gotoxy(56,4 + 5*(round-1));
        printf("%d", juiz1_A);
        gotoxy(56,5 + 5*(round-1));
        printf("%d", juiz2_A);
        gotoxy(56,6 + 5*(round-1));
        printf("%d", juiz3_A);

        SetCor(4,15);
        gotoxy(69,4 + 5*(round-1));
        printf("%d", juiz1_V);
        gotoxy(69,5 + 5*(round-1));
        printf("%d", juiz2_V);
        gotoxy(69,6 + 5*(round-1));
        printf("%d", juiz3_V);

        pontos_A += juiz1_A + juiz2_A + juiz3_A;
        pontos_V += juiz1_V + juiz2_V + juiz3_V;
        SetCor(0,2);
        gotoxy(26,29);
        if (round!=5){
            printf("Pressione qualquer tecla para obter os resultados do proximo Round.");
        }
        else{
            printf("Pressione qualquer tecla para obter o resultado da Luta.           ");
        }
        tecla=getch();
    }
    SetCor(7,0);
    system("cls");
    if (pontos_A>pontos_V){
        SetCor(1,15);
        box(34,9,85,11,2);
        gotoxy(36,10);
        printf("O lutador Azul venceu a luta por %d a %d.", pontos_A, pontos_V);
    }
    else if (pontos_A<pontos_V) {
        SetCor(4,15);
        box(34,9,85,11,2);
        gotoxy(36,10);
        printf("O lutador VERMELHO venceu a luta por %d a %d.", pontos_V, pontos_A);
    }
    else{
        SetCor(2,15);
        box(34,9,85,11,2);
        gotoxy(36,10);
        printf("Houve um empate tecnico entre os lutadores.");
    }

    tecla=getch();
    SetCor(7,0);
    system("cls");
}

int Sorteio(){
    int rnd = rand()%4 + 7;
    return(rnd);
}
