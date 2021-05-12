#include<stdio.h>
#include <windows.h>



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

    int iMax=10;
    float peso,maior,menor,media;
    media=0;
    peso=0;

    printf("Informe o peso de %d pessoas\n\n", iMax);
    for (int i=1; i<=iMax;i++){
        do{
            printf("Informe o peso da %d%c pessoa: ", i, 166);
            scanf("%f", &peso);
            if (peso<=0){
                gotoxy(0,1+i);
                printf("                                                                                                             ");
                gotoxy(0,1+i);
            }
        }while (peso<=0);
        if (i==1){
            maior = peso;
            menor = peso;
        }
        else{
            if (peso>maior){
                maior=peso;
            }
            if (peso<menor){
                menor=peso;
            }
        }
        media += peso;
    }

    printf("\n\nA media dos pesos informados foi de: %.2f", (media/iMax));
    printf("\nO maior peso informado foi de: %.2f", maior);
    printf("\nO menor peso informado foi de: %.2f\n\n", menor);
}
