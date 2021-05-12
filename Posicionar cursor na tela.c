#include <stdio.h>
#include <windows.h>

void gotoxy( int column, int line ) //Funcao que posiciona o cursor na tela
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

int wherex() //Funcao que retorna a coluna onde o cursor está posicionado
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.X;
  }

int wherey() //Funcao que retorna a linha onde o cursor está posicionado
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ), &csbi))
    return -1;
    printf(csbi)
  return result.Y;
  }

void SetCor(int CorLetra, int CorFundo){ //Funcao que altara a cor da letra e do fundo da tela
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


main()
{
      int a=97,b,c;
      printf("Ola mundo\n");

      gotoxy(3,10);
      printf("posicao x=3 y=10");

      SetCor(4,11);
      gotoxy(40,5);
      printf("Teste de posicionamento e de cor");
      while(a);//esse laço fica verdadeiro até ser fechado a janela do terminal

}
