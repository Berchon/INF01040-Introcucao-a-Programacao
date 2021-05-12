#include <stdio.h>
#include <windows.h>


#define ACIMA 72
#define ABAIXO 80
#define DIREITA 77
#define ESQUERDA 75

#define ENTER 13
#define ESC 27

void gotoxy( int column, int line ){
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
}

void box(int x1,int y1,int x2,int y2,int Linha){  //1 = Linha Simples, 2 = Linha Dupla
    char Caracter1, Caracter2;
    if (Linha==2){
        Caracter1 = 205;
        Caracter2 = 186;
    }
    else{
        Caracter1 = 196;
        Caracter2 = 179;
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
    else{
        printf("%c",218);
    }

    gotoxy(xMaior,yMenor);
    if (Linha==2){
        printf("%c",187);
    }
    else{
        printf("%c",191);
    }

    gotoxy(xMenor,yMaior);
    if (Linha==2){
        printf("%c",200);
    }
    else{
        printf("%c",192);
    }

    gotoxy(xMaior,yMaior);
    if (Linha==2){
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

int main(void)
{
    SetCor(6,4);
    box(10,20,88,26,2);
    gotoxy(42,21);
    printf("ATENCAO !!!");
    gotoxy(42,22);
    printf("===========");
    gotoxy(12,23);
    printf("O enunciado pede para entrar com um valor de 1 ate 10 (usando um scanf). No");
    gotoxy(12,24);
    printf("entanto, utilizei um menu no lugar, para demonstrar a facilidade dos menus.");
    gotoxy(12,25);
    printf("O codigo da forma que foi solicitado esta comentado nesse mesmo codigo.");


     char menu[10][25] = {"   Johnnie Walker       ",
                          "   Smirnoff             ",
                          "   Jack Daniels         ",
                          "   Captain Morgan       ",
                          "   Absolut              ",
                          "   Ballantines          ",
                          "   Jose Cuervo          ",
                          "   Concha y Toro        ",
                          "   Moet & Chandon       ",
                          "   Havana Club          "};
    float preco[10];
    preco[0] = 119.95f;
    preco[1] = 19.9f;
    preco[2] = 129.9f;
    preco[3] = 105.f;
    preco[4] = 99.f;
    preco[5] = 114.95f;
    preco[6] = 85.f;
    preco[7] = 84.9f;
    preco[8] = 387.9f;
    preco[9] = 75.9f;

    int indiceMenu = 0;
    int xMenu = 10;
    int yMenu = 2;

    SetCor(9,15);
    box(xMenu,yMenu,xMenu+25,yMenu+11,2);
    gotoxy(xMenu+1, yMenu+1);
    printf("%s", menu[0]);
    gotoxy(xMenu+1, yMenu+2);
    printf("%s", menu[1]);
    gotoxy(xMenu+1, yMenu+3);
    printf("%s", menu[2]);
    gotoxy(xMenu+1, yMenu+4);
    printf("%s", menu[3]);
    gotoxy(xMenu+1, yMenu+5);
    printf("%s", menu[4]);
    gotoxy(xMenu+1, yMenu+6);
    printf("%s", menu[5]);
    gotoxy(xMenu+1, yMenu+7);
    printf("%s", menu[6]);
    gotoxy(xMenu+1, yMenu+8);
    printf("%s", menu[7]);
    gotoxy(xMenu+1, yMenu+9);
    printf("%s", menu[8]);
    gotoxy(xMenu+1, yMenu+10);
    printf("%s", menu[9]);

    SetCor(15,9);
    gotoxy(xMenu+1, yMenu+1+indiceMenu);
    printf("%s", menu[indiceMenu]);

    int tecla;
    while(tecla!=ENTER) {

        tecla=getch();

        SetCor(9,15);
        gotoxy(xMenu+1, yMenu+1+indiceMenu);
        printf("%s", menu[indiceMenu]);

        switch (tecla){
            case ACIMA:
                indiceMenu--;
                break;
            case ABAIXO:
                indiceMenu++;
                break;
            case DIREITA:
                indiceMenu++;
                break;
            case ESQUERDA:
                indiceMenu--;
                break;
        }

        if (indiceMenu<0) indiceMenu=9;
        if (indiceMenu>9) indiceMenu=0;
        SetCor(15,9);
        gotoxy(xMenu+1, yMenu+1+indiceMenu);
        printf("%s", menu[indiceMenu]);

    }

    float qtd = 0.f;
    do{
        SetCor(9,15);
        box(40,2,100,6,2);
        box(42,3,98,5,1);
        gotoxy(44,4);
        printf("Informe a quantidade que deseja comprar ");
        SetCor(15,9);
        gotoxy(84,4);
        printf("             ");
        gotoxy(84,4);
        scanf("%f", &qtd);
    } while (qtd<=0);

    SetCor(9,15);
    box(40,8,100,17,2);
    box(42,9,98,13,1);
    box(42,14,98,16,1);
    gotoxy(44,11);
    printf("Descricao");
    gotoxy(44,14);
    printf("TOTAL");

    SetCor(1,15);
    gotoxy(44,10);
    printf("Produto");
    gotoxy(44,11);
    printf("Quantidade");
    gotoxy(44,12);
    printf("Valor Unitario");

    gotoxy(44,15);
    printf("R$");

    SetCor(0,15);
    gotoxy(56,10);
    printf("%s",menu[indiceMenu]);
    gotoxy(59,11);
    printf("%.2f",qtd);
    gotoxy(59,12);
    printf("%.2f",preco[indiceMenu]);

    SetCor(4,15);
    gotoxy(47,15);
    printf("%.2f",preco[indiceMenu]*qtd);

    SetCor(7,0);
    gotoxy(0,26);
    return 0;
}
