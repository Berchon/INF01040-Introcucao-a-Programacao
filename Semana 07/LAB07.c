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


#define MaxIndex 20

int main(){

    float valores[MaxIndex];
    for (int i=0; i<MaxIndex; i++){
        printf("Informe o %d%c valor: ", (i+1), 167);
        scanf("%f", &valores[i]);
    }

    printf("\n\n");

    for(int i=(MaxIndex-1); i>=0; i--){
        printf("%d%c valor digitado foi: %.2f\n", i+1, 167, valores[i]);
    }

}
