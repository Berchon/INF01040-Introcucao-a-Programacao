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

#define NOTAS 5 // a media do aluno sera guardade junto com as notas
#define ALUNOS 6

int main(){
    float mediaTurma = 0;
    float notas[ALUNOS][NOTAS];
    for (int i=0; i<ALUNOS; i++){
        box(0,0+i*4,53,2+i*4,1);
        gotoxy(2,0+i*4);
        printf(" Informe as notas [0-10] do Aluno %d ", i+1);
        gotoxy(2,1+i*4);
        printf("P1:");
        gotoxy(12,1+i*4);
        printf("P2:");
        gotoxy(22,1+i*4);
        printf("P3:");
        gotoxy(32,1+i*4);
        printf("P4:");
        gotoxy(42,1+i*4);
        printf("Media:");
        notas[i][NOTAS-1] = 0.f;
        for (int j=0; j<NOTAS-1; j++){ // no ultimo elemento sera armazenado a media
            do{
                gotoxy(5+j*10,1+i*4);
                scanf("%f", &notas[i][j]);
            } while (notas[i][j]<0 || notas[i][j]>10);
            notas[i][NOTAS-1] += notas[i][j];
        }
        notas[i][NOTAS-1] /= (float)(NOTAS-1);
        gotoxy(48,1+i*4);
        printf("%.2f", notas[i][NOTAS-1]);
        mediaTurma += notas[i][NOTAS-1];
    }



    SetCor(7,15);
    system("cls");

    SetCor(15,9);
    for (int i=0; i<ALUNOS; i++){
        box(0,0+i*4,53,2+i*4,1);
        gotoxy(2,0+i*4);
        printf(" Notas do Aluno %d ", i+1);
        gotoxy(42,1+i*4);
        printf("Media:");
        for (int j=0; j<NOTAS-1; j++){ // no ultimo elemento sera armazenado a media
                gotoxy(2+j*10,1+i*4);
                printf("P%d:%.2f", j+1, notas[i][j]);
        }
        gotoxy(48,1+i*4);
        printf("%.2f", notas[i][NOTAS-1]);
    }





    box(58,0,112,3,1);

    mediaTurma /= (float)ALUNOS;

    gotoxy(60,1);
    printf("Media da Turma: %.2f", mediaTurma);

    int contador = 0;
    for (int i=0; i<ALUNOS; i++){
        if (notas[i][NOTAS-1]<mediaTurma)
            contador++;
    }

    gotoxy(60,2);
    printf("Numero de alunos com nota final inferior a media: %d", contador);

    int tecla;
    tecla=getch();
    SetCor(7,0);
    system("cls");
}
