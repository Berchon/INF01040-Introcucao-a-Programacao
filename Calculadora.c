#include<stdio.h>
#include <windows.h>

#define ENTER 13
#define ESC 27
#define BACKSPACE 8

#define ZERO 48
#define UM 49
#define DOIS 50
#define TRES 51
#define QUATRO 52
#define CINCO 53
#define SEIS 54
#define SETE 55
#define OITO 56
#define NOVE 57

#define PONTO 46

#define MAIS 43
#define MENOS 45
#define VEZES 42
#define DIVIDIR 47


void gotoxy( int column, int line ){
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
}

void box(int x1,int y1,int x2,int y2,char Caracter1, char Caracter2){
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
    if (Caracter1==-51){
        printf("%c",201);
    }
    else{
        printf("%c",218);
    }

    gotoxy(xMaior,yMenor);
    if (Caracter1==-51){
        printf("%c",187);
    }
    else{
        printf("%c",191);
    }

    gotoxy(xMenor,yMaior);
    if (Caracter1==-51){
        printf("%c",200);
    }
    else{
        printf("%c",192);
    }

    gotoxy(xMaior,yMaior);
    if (Caracter1==-51){
        printf("%c",188);
    }
    else{
        printf("%c",217);
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

void imprimeTecla(char tecla,int x, int y, int sombra){
    SetCor(15,9);
    gotoxy(x, y);
    printf("     %c     ", tecla);
    if (sombra){
        SetCor(8,15);
        printf("%c",220);
        gotoxy(x+1, y+1);
        for (int i=0; i<(11);i++){
            printf("%c",223);
        }
    }
}

void ImprimeTela(){
    SetCor(9,15);
    box(1,2,72,25,205,186);
    box(6,4,67,8,196,179);
    gotoxy(1, 10);
    printf("%c",204);
    for (int i=0; i<(70);i++){
        printf("%c",205);
    }
    printf("%c",185);

    imprimeTecla('7', 6, 13, 1);
    imprimeTecla('4', 6, 16, 1);
    imprimeTecla('1', 6, 19, 1);
    imprimeTecla('0', 6, 22, 1);
    imprimeTecla('8', 23, 13, 1);
    imprimeTecla('5', 23, 16, 1);
    imprimeTecla('2', 23, 19, 1);
    imprimeTecla('.', 23, 22, 1);
    imprimeTecla('9', 40, 13, 1);
    imprimeTecla('6', 40, 16, 1);
    imprimeTecla('3', 40, 19, 1);

    imprimeTecla('=', 40, 22, 1);

    imprimeTecla(246, 57, 13, 1); // dividir
    imprimeTecla(158, 57, 16, 1); // vezes
    imprimeTecla('-', 57, 19, 1);
    imprimeTecla('+', 57, 22, 1);

    gotoxy(40,26);
    printf("%c%c%c",176,177,178);
}

void pressiona(char tecla,int x, int y){
    SetCor(9,15);
    gotoxy(x,y);
    printf("            ");
    gotoxy(x,y+1);
    printf("            ");
    imprimeTecla(tecla, x+1, y, 0);
    for (int i=0; i<30000000; i++){
        //Para dar o efeito do desaparecimento da sombra
    }
    SetCor(9,15);
    gotoxy(x,y);
    printf("            ");
    gotoxy(x,y+1);
    printf("            ");
    imprimeTecla(tecla, x, y, 1);
}

int main(){
    ImprimeTela();

    int coluna = 8;
    int linha = 6;
    int indice = 0;


    int tecla;
    int flag = 0;

    char* numero;

    while(tecla!=ESC) {
        //gotoxy(1,1);
        //printf("%d", indice);
        gotoxy(coluna,linha);
        tecla=getch();
        //printf("%d", tecla);

        switch (tecla){
            case ZERO:
                pressiona('0',6, 22);
                flag = 1;
                break;
            case UM:
                pressiona('1',6, 19);
                flag = 1;
                break;
            case DOIS:
                pressiona('2',23, 19);
                flag = 1;
                break;
            case TRES:
                pressiona('3',40, 19);
                flag = 1;
                break;
            case QUATRO:
                pressiona('4',6, 16);
                flag = 1;
                break;
            case CINCO:
                pressiona('5',23, 16);
                flag = 1;
                break;
            case SEIS:
                pressiona('6',40, 16);
                flag = 1;
                break;
            case SETE:
                pressiona('7',6, 13);
                flag = 1;
                break;
            case OITO:
                pressiona('8',23, 13);
                flag = 1;
                break;
            case NOVE:
                pressiona('9',40, 13);
                flag = 1;
                break;
            case PONTO:
                pressiona('.',23,22);
                flag=1;
                break;
            case ENTER:
                pressiona('=',40,22);
                break;
            case BACKSPACE:
                if (indice>0){
                    coluna--;
                    indice--;
                    numero[indice]=0;
                    gotoxy(coluna,linha);
                    printf(" ");
                }
                break;
            case MAIS:
                pressiona('+',57,22);
                break;
            case MENOS:
                pressiona('-',57, 19);
                break;
            case VEZES:
                pressiona(158,57, 16);
                break;
            case DIVIDIR:
                pressiona(246,57, 13);
                break;
        }

        if (flag && indice <= 15){
            SetCor(9,15);
            gotoxy(coluna,linha);
            printf("%c", tecla);
            coluna++;
            numero[indice]=tecla;
            indice++;
            flag = 0;
        }
    }
    gotoxy(80,20);
    printf("%s", numero);
}
