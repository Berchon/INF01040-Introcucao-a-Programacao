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

void imprimeTecla(char tecla,int x, int y, int sombra){
    //SetCor(15,9);
    gotoxy(x, y-1);
    printf("    . ...  ");
    gotoxy(x, y);
    printf("  %c . ...  ", tecla);
    gotoxy(x, y+1);
    printf("   .. ...  ");
    /*
    if (sombra){
        SetCor(8,15);
        printf("%c",220);
        gotoxy(x+1, y+1);
        for (int i=0; i<(5);i++){
            printf("%c",223);
        }
    }
    */
}

void imprimeTecla2(int x, int y){
    //SetCor(15,9);
    gotoxy(x, y-1);
    printf("              ... ....  ");
    gotoxy(x, y);
    printf("  CONFIRMA       . ..   ");
    gotoxy(x, y+1);
    printf("                . .     ");
}

void F(int x, int y){
    gotoxy(x,y);
    printf("%c%c%c", 220,220,220);
    gotoxy(x,y+1);
    printf("%c%c",219,254);
    gotoxy(x,y+2);
    printf("%c",223);
}

void E(int x, int y){
    gotoxy(x,y);
    printf("%c%c%c", 220,220,220);
    gotoxy(x,y+1);
    printf("%c%c%c",219,254,254);
    gotoxy(x,y+2);
    printf("%c%c%c",223,223,223);
}

void L(int x, int y){
    gotoxy(x,y);
    printf("%c",220);
    gotoxy(x,y+1);
    printf("%c",219);
    gotoxy(x,y+2);
    printf("%c%c%c",223,223,223);
}

void I(int x, int y){
    gotoxy(x,y);
    printf("%c%c%c",220,220,220);
    gotoxy(x+1,y+1);
    printf("%c",219);
    gotoxy(x,y+2);
    printf("%c%c%c",223,223,223);
}

void T(int x, int y){
    gotoxy(x,y);
    printf("%c%c%c",220,220,220);
    gotoxy(x+1,y+1);
    printf("%c",219);
    gotoxy(x+1,y+2);
    printf("%c",223);
}

void O(int x, int y){
    gotoxy(x,y);
    printf("%c%c%c", 220,220,220);
    gotoxy(x,y+1);
    printf("%c %c",219,219);
    gotoxy(x,y+2);
    printf("%c%c%c",223,223,223);
}

void R(int x, int y){
    gotoxy(x,y);
    printf("%c%c", 220,220);
    gotoxy(x,y+1);
    printf("%c%c%c",219,220,223);
    gotoxy(x,y+2);
    printf("%c %c",223,223);
}

void A(int x, int y){
    gotoxy(x+1,y);
    printf("%c", 220);
    gotoxy(x,y+1);
    printf("%c%c%c",219,220,219);
    gotoxy(x,y+2);
    printf("%c %c",223,223);
}

void J(int x, int y){
    gotoxy(x,y);
    printf("%c%c%c", 220,220,220);
    gotoxy(x,y+1);
    printf("%c %c",220,219);
    gotoxy(x,y+2);
    printf("%c%c%c",223,223,223);
}

void U(int x, int y){
    gotoxy(x,y);
    printf("%c %c", 220,220);
    gotoxy(x,y+1);
    printf("%c %c",219,219);
    gotoxy(x,y+2);
    printf("%c%c%c",223,223,223);
}

void S(int x, int y){
    gotoxy(x,y);
    printf("%c%c%c", 220,220,220);
    gotoxy(x,y+1);
    printf("%c%c%c",223,254,220);
    gotoxy(x,y+2);
    printf("%c%c%c",223,223,223);
}

void C_Cedil(int x, int y){
    gotoxy(x,y);
    printf("%c%c%c", 220,220,220);
    gotoxy(x,y+1);
    printf("%c",219);
    gotoxy(x,y+2);
    printf("%c%c%c",223,219,223);
}

void M(int x, int y){
    gotoxy(x,y);
    printf("%c   %c", 220,220);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c",219,223,254,223,219);
    gotoxy(x,y+2);
    printf("%c   %c",223,223);
}

void X(int x, int y){
    gotoxy(x,y);
    printf("%c   %c", 220,220);
    gotoxy(x,y+1);
    printf(" %c%c%c",223,220,223);
    gotoxy(x,y+2);
    printf("%c%c %c%c",220,223,223,220);
}

void status(int i, int j){
    int a,b;
    if (i>j){
        a=j;
        b=i;
    }
    else{
        a=i;
        b=j;
    }
    SetCor(0,15);
    gotoxy(4, 26);
    printf("Informe o N%c do candidado (Chapa %d ou Chapa %d) e pressione <ENTER>.", 167,a,b);
}

void ImprimeTela(){
    SetCor(0,15);
    box(0,0,119,29,1);
    gotoxy(0,0);
    SetCor(15,8);
    box(77,11,117,27,0);
    SetCor(0,15);
    box(2,26,75,28,1);
    box(2,2,75,28,2);
    gotoxy(2,25);
    printf("%c",199);
    gotoxy(3,25);
    for (int i=3; i<75; i++){
        printf("%c",196);
    }
    printf("%c",182);
    gotoxy(4, 26);
    printf("Informe o N%c do candidado (de 1 ate 10) e pressione <ENTER>.", 167);
    gotoxy(4, 27);
    printf("Para encerrar a votacao entre com o valor 0 (ZERO).");
    box(77,2,117,9,1);
    SetCor(15,0);
    imprimeTecla(49, 79,13, 0);
    imprimeTecla(50, 92,13, 0);
    imprimeTecla(51, 105,13, 0);

    imprimeTecla(52, 79, 17, 0);
    imprimeTecla(53, 92, 17, 0);
    imprimeTecla(54, 105, 17, 0);

    imprimeTecla(55, 79, 21, 0);
    imprimeTecla(56, 92, 21, 0);
    imprimeTecla(57, 105, 21, 0);

    imprimeTecla(48, 79, 25, 0);
    SetCor(0,2);
    imprimeTecla2(92, 25);

    SetCor(0,15);
    E(80,6);
    L(84,6);
    E(88,6);
    I(92,6);
    T(96,6);
    O(100,6);
    R(104,6);
    A(108,6);
    L(112,6);

    J(84,3);
    U(88,3);
    S(92,3);
    T(96,3);
    I(100,3);
    C_Cedil(104,3);
    A(108,3);

    gotoxy(4,3);
    printf("Seu voto para");
    gotoxy(6,4);
    printf("PRESIDENTE");
    gotoxy(4,5);
    printf("=============");

    gotoxy(4,7);
    printf("Numero ");
    SetCor(15,9);
    printf("       ");

}

#define NUMCHAPAS 10
int main(){
    // Converte a página de codigos atual para o padrao americano
    system("chcp 437");
    ImprimeTela();
    //ChapaObiLuke(58,12);
    int votos[NUMCHAPAS]; // o indice ZERO sera usado para armazenar o nro total de votos
    int voto;
    for (int i=0; i<=NUMCHAPAS; i++){
        votos[i]=0;
    }
    do{
        SetCor(15,9);
        gotoxy(11,7);
        scanf("%d", &voto);
        if (voto<0 || voto>NUMCHAPAS){
            SetCor(6,4);
            box(4,10,61,13,1);
            gotoxy(6,11);
            printf("Voce deve informar um valor de 1 ate 10.");
            gotoxy(6,12);
            printf("Voce pode informar 0 (Zero) para encerrar a eleicao.");
            int tecla;
            tecla=getch();
            ImprimeTela();
        }
        else if (voto>0 && voto<=NUMCHAPAS){
            votos[voto]++;
            votos[0]++;
            SetCor(0,15);
            switch (voto){
                case 1:
                    ChapaR2D2(53,14);
                    nomeR2D2(4,18);
                    break;
                case 2:
                    ChapaC3PO(53,14);
                    nomeC3PO(4,18);
                    break;
                case 3:
                    ChapaJarJar(53,14);
                    nomeJarJar(4,18);
                    break;
                case 4:
                    ChapaEstreladaMorte(53,14);
                    nomeEstreladaMorte(4,18);
                    break;
                case 5:
                    ChapaStormTrooper(53,14);
                    nomeStormTrooper(4,18);
                    break;
                case 6:
                    ChapaBanda(53,14);
                    nomeBanda(4,18);
                    break;
                case 7:
                    ChapaVader(53,14);
                    nomeVader(4,18);
                    break;
                case 8:
                    ChapaYoda(53,15);
                    nomeYoda(4,18);
                    break;
                case 9:
                    ChapaBobaFett(53,15);
                    nomeBobaFett(4,18);
                    break;
                case 10:
                    ChapaObiLuke(53,14);
                    nomeObiLuke(4,18);
                    break;
            }

            SetCor(9,15);
            F(6,10);
            I(10,10);
            M(14,10);


            int tecla;
            tecla=getch();
            ImprimeTela();
        }
    } while (voto!=0);
    SetCor(0,15);
    box(0,0,119,29,1);
    gotoxy(0,0);
    if (votos[0]==0){
        gotoxy(36,10);
        SetCor(4,15);
        printf("Eleicao Invalida! Ninguem compareceu a votacao.");
    }
    else{
        gotoxy(3,5);
        SetCor(10,15);
        printf(" 1 = R2-D2");
        gotoxy(40,5);
        printf("%.2f %",(float)votos[1]*100/votos[0]);

        gotoxy(3,6);
        SetCor(6,15);
        printf(" 2 = C-3PO");
        gotoxy(40,6);
        printf("%.2f %",(float) votos[2]*100/votos[0]);

        gotoxy(3,7);
        SetCor(13,15);
        printf(" 3 = Jar Jar Binks");
        gotoxy(40,7);
        printf("%.2f %",(float) votos[3]*100/votos[0]);

        gotoxy(3,8);
        SetCor(4,15);
        printf(" 4 = Estrela da Morte");
        gotoxy(40,8);
        printf("%.2f %",(float) votos[4]*100/votos[0]);

        gotoxy(3,9);
        SetCor(8,15);
        printf(" 5 = Stormtroopers Fives e Rex");
        gotoxy(40,9);
        printf("%.2f %",(float) votos[5]*100/votos[0]);

        gotoxy(3,10);
        SetCor(5,15);
        printf(" 6 = Banda da Cantina");
        gotoxy(40,10);
        printf("%.2f %",(float) votos[6]*100/votos[0]);

        gotoxy(3,11);
        SetCor(0,15);
        printf(" 7 = Darth Vader");
        gotoxy(40,11);
        printf("%.2f %",(float) votos[7]*100/votos[0]);

        gotoxy(3,12);
        SetCor(2,15);
        printf(" 8 = Mestre Yoda");
        gotoxy(40,12);
        printf("%.2f %",(float) votos[8]*100/votos[0]);

        gotoxy(3,13);
        SetCor(11,15);
        printf(" 9 = Boba Fett");
        gotoxy(40,13);
        printf("%.2f %",(float) votos[9]*100/votos[0]);

        gotoxy(3,14);
        SetCor(1,15);
        printf("10 = Obi-Wan Kenobi e Luke Skywalker");
        gotoxy(40,14);
        printf("%.2f %",(float) votos[10]*100/votos[0]);

        gotoxy(3,15);
        printf("==========================================");
        gotoxy(3,16);
        SetCor(12,15);
        printf("Total de votos validos ");
        gotoxy(40,16);
        printf("%d",votos[0]);

        int tecla;
        tecla=getch();
        SetCor(0,15);
        box(0,0,119,29,1);
        gotoxy(0,0);

        int ChapaPrimeiro[2]; //no indice Zero eh guardado o nro da CHAPA.
        int ChapaSegundo[2];  //No indice 1 eh guardado a quantidade de votos
        ChapaPrimeiro[0] = 0;
        ChapaPrimeiro[1] = 0;
        ChapaSegundo[0] = 0;
        ChapaSegundo[1] = 0;
        for (int i=1; i<=NUMCHAPAS;i++){
            if (votos[i]>ChapaPrimeiro[1]){
                //atualiza o primeiro colocado
                ChapaPrimeiro[0] = i;
                ChapaPrimeiro[1] = votos[i];
            }
        }
        for (int i=1; i<=NUMCHAPAS;i++){
            if (votos[i]>ChapaSegundo[1] && i!=ChapaPrimeiro[0]){
                //Encontra o segundo colocado
                ChapaSegundo[0] = i;
                ChapaSegundo[1] = votos[i];
            }
        }
        float porcentPrimeiro = votos[ChapaPrimeiro[0]]*100/votos[0];
        float porcentSegundo  = votos[ChapaSegundo[0]]*100/votos[0];
        if (porcentPrimeiro>50){ //Vitoria no Primeiro turno
            gotoxy(49,3);
            printf("Novo presidente eleito");
            switch (ChapaPrimeiro[0]){
                case 1:
                    ChapaR2D2(60,17);
                    nomeR2D2(4,21);
                    break;
                case 2:
                    ChapaC3PO(60,17);
                    nomeC3PO(4,21);
                    break;
                case 3:
                    ChapaJarJar(60,17);
                    nomeJarJar(4,21);
                    break;
                case 4:
                    ChapaEstreladaMorte(60,17);
                    nomeEstreladaMorte(4,21);
                    break;
                case 5:
                    ChapaStormTrooper(60,17);
                    nomeStormTrooper(4,21);
                    break;
                case 6:
                    ChapaBanda(60,17);
                    nomeBanda(4,21);
                    break;
                case 7:
                    ChapaVader(60,17);
                    nomeVader(4,21);
                    break;
                case 8:
                    ChapaYoda(60,17);
                    nomeYoda(4,21);
                    break;
                case 9:
                    ChapaBobaFett(60,17);
                    nomeBobaFett(4,21);
                    break;
                case 10:
                    ChapaObiLuke(60,17);
                    nomeObiLuke(4,21);
                    break;
            }
        }
        else{ //Segundo turno
            gotoxy(38,3);
            SetCor(12,15);
            printf("Candidatos que passaram para o segundo turno");
            X(58,14);
            SetCor(0,15);
            int segundoturno[1]; //Armazena o numero das chapas que passaram para o segundo turno
            segundoturno[0]=ChapaPrimeiro[0];
            segundoturno[1]=ChapaSegundo[0];
            for (int i=0; i<2;i++){
                //gotoxy(0,0+i);
                //printf("%d",segundoturno[i]);
                switch (segundoturno[i]){
                    case 1:
                        ChapaR2D2(30+60*i,17);
                        break;
                    case 2:
                        ChapaC3PO(30+60*i,17);
                        break;
                    case 3:
                        ChapaJarJar(30+60*i,17);
                        break;
                    case 4:
                        ChapaEstreladaMorte(30+60*i,17);
                        break;
                    case 5:
                        ChapaStormTrooper(30+60*i,17);
                        break;
                    case 6:
                        ChapaBanda(30+60*i,17);
                        break;
                    case 7:
                        ChapaVader(30+60*i,17);
                        break;
                    case 8:
                        ChapaYoda(30+60*i,17);
                        break;
                    case 9:
                        ChapaBobaFett(30+60*i,17);
                        SetCor(0,15);
                        break;
                    case 10:
                        ChapaObiLuke(30+60*i,17);
                        break;
                }

            }
            int tecla;
            tecla=getch();
            ImprimeTela();
            status(segundoturno[0],segundoturno[1]);
            for(int i=0; i<=NUMCHAPAS;i++){
                votos[i]=0;
            }
            do{
                SetCor(15,9);
                gotoxy(11,7);
                scanf("%d", &voto);
                if (voto!=segundoturno[0] && voto!=segundoturno[1] && voto!=0){
                    SetCor(6,4);
                    box(4,10,61,13,1);
                    gotoxy(6,11);
                    printf("Voce deve votar na Chapa %d ou na Chapa %d.", segundoturno[0], segundoturno[1]);
                    gotoxy(6,12);
                    printf("Voce pode informar 0 (Zero) para encerrar a eleicao.");
                    int tecla;
                    tecla=getch();
                    ImprimeTela();
                    status(segundoturno[0],segundoturno[1]);
                    continue;
                }
                else if (voto>0 && voto<=NUMCHAPAS){
                    votos[voto]++;
                    votos[0]++;
                    SetCor(0,15);
                    switch (voto){
                        case 1:
                            ChapaR2D2(53,14);
                            nomeR2D2(4,18);
                            break;
                        case 2:
                            ChapaC3PO(53,14);
                            nomeC3PO(4,18);
                            break;
                        case 3:
                            ChapaJarJar(53,14);
                            nomeJarJar(4,18);
                            break;
                        case 4:
                            ChapaEstreladaMorte(53,14);
                            nomeEstreladaMorte(4,18);
                            break;
                        case 5:
                            ChapaStormTrooper(53,14);
                            nomeStormTrooper(4,18);
                            break;
                        case 6:
                            ChapaBanda(53,14);
                            nomeBanda(4,18);
                            break;
                        case 7:
                            ChapaVader(53,14);
                            nomeVader(4,18);
                            break;
                        case 8:
                            ChapaYoda(53,15);
                            nomeYoda(4,18);
                            break;
                        case 9:
                            ChapaBobaFett(53,15);
                            nomeBobaFett(4,18);
                            break;
                        case 10:
                            ChapaObiLuke(53,14);
                            nomeObiLuke(4,18);
                            break;
                    }

                    SetCor(9,15);
                    F(6,10);
                    I(10,10);
                    M(14,10);


                    //int tecla;
                    tecla=getch();
                    ImprimeTela();
                    status(segundoturno[0],segundoturno[1]);
                }
            } while (voto!=0);

            SetCor(0,15);
            box(0,0,119,29,1);
            gotoxy(0,0);
            if (votos[0]==0){
                gotoxy(36,10);
                SetCor(4,15);
                printf("Eleicao Invalida! Ninguem compareceu a votacao.");
            }
            else{
                int somaLinha = 0;

                if (segundoturno[0]==1 || segundoturno[1]==1){
                    gotoxy(3,11+somaLinha);
                    SetCor(10,15);
                    printf(" 1 = R2-D2");
                    gotoxy(40,11+somaLinha);
                    printf("%.2f %",(float)votos[1]*100/votos[0]);
                    somaLinha++;
                }

                if (segundoturno[0]==2 || segundoturno[1]==2){
                    gotoxy(3,11+somaLinha);
                    SetCor(6,15);
                    printf(" 2 = C-3PO");
                    gotoxy(40,11+somaLinha);
                    printf("%.2f %",(float) votos[2]*100/votos[0]);
                    somaLinha++;
                }

                if (segundoturno[0]==3 || segundoturno[1]==3){
                    gotoxy(3,11+somaLinha);
                    SetCor(13,15);
                    printf(" 3 = Jar Jar Binks");
                    gotoxy(40,11+somaLinha);
                    printf("%.2f %",(float) votos[3]*100/votos[0]);
                    somaLinha++;
                }

                if (segundoturno[0]==4 || segundoturno[1]==4){
                    gotoxy(3,11+somaLinha);
                    SetCor(4,15);
                    printf(" 4 = Estrela da Morte");
                    gotoxy(40,11+somaLinha);
                    printf("%.2f %",(float) votos[4]*100/votos[0]);
                    somaLinha++;
                }

                if (segundoturno[0]==5 || segundoturno[1]==5){
                    gotoxy(3,11+somaLinha);
                    SetCor(8,15);
                    printf(" 5 = Stormtroopers Fives e Rex");
                    gotoxy(40,11+somaLinha);
                    printf("%.2f %",(float) votos[5]*100/votos[0]);
                    somaLinha++;
                }

                if (segundoturno[0]==6 || segundoturno[1]==6){
                    gotoxy(3,11+somaLinha);
                    SetCor(5,15);
                    printf(" 6 = Banda da Cantina");
                    gotoxy(40,11+somaLinha);
                    printf("%.2f %",(float) votos[6]*100/votos[0]);
                    somaLinha++;
                }

                if (segundoturno[0]==7 || segundoturno[1]==7){
                    gotoxy(3,11+somaLinha);
                    SetCor(0,15);
                    printf(" 7 = Darth Vader");
                    gotoxy(40,11+somaLinha);
                    printf("%.2f %",(float) votos[7]*100/votos[0]);
                    somaLinha++;
                }

                if (segundoturno[0]==8 || segundoturno[1]==8){
                    gotoxy(3,11+somaLinha);
                    SetCor(2,15);
                    printf(" 8 = Mestre Yoda");
                    gotoxy(40,11+somaLinha);
                    printf("%.2f %",(float) votos[8]*100/votos[0]);
                    somaLinha++;
                }

                if (segundoturno[0]==9 || segundoturno[1]==9){
                    gotoxy(3,11+somaLinha);
                    SetCor(11,15);
                    printf(" 9 = Boba Fett");
                    gotoxy(40,11+somaLinha);
                    printf("%.2f %",(float) votos[9]*100/votos[0]);
                    somaLinha++;
                }

                if (segundoturno[0]==10 || segundoturno[1]==10){
                    gotoxy(3,11+somaLinha);
                    SetCor(1,15);
                    printf("10 = Obi-Wan Kenobi e Luke Skywalker");
                    gotoxy(40,11+somaLinha);
                    printf("%.2f %",(float) votos[10]*100/votos[0]);
                    somaLinha++;
                }

                gotoxy(3,14);
                printf("==========================================");
                gotoxy(3,15);
                SetCor(12,15);
                printf("Total de votos validos ");
                gotoxy(40,15);
                printf("%d",votos[0]);

                int tecla;
                tecla=getch();

                int vencedor;
                if(votos[segundoturno[0]]>votos[segundoturno[1]]){
                    vencedor = segundoturno[0];
                }
                else{
                    vencedor=segundoturno[1];
                }

                SetCor(0,15);
                box(0,0,119,29,1);
                gotoxy(0,0);
                gotoxy(49,3);
                printf("Novo presidente eleito");
                switch (vencedor){
                    case 1:
                        ChapaR2D2(60,17);
                        nomeR2D2(4,21);
                        break;
                    case 2:
                        ChapaC3PO(60,17);
                        nomeC3PO(4,21);
                        break;
                    case 3:
                        ChapaJarJar(60,17);
                        nomeJarJar(4,21);
                        break;
                    case 4:
                        ChapaEstreladaMorte(60,17);
                        nomeEstreladaMorte(4,21);
                        break;
                    case 5:
                        ChapaStormTrooper(60,17);
                        nomeStormTrooper(4,21);
                        break;
                    case 6:
                        ChapaBanda(60,17);
                        nomeBanda(4,21);
                        break;
                    case 7:
                        ChapaVader(60,17);
                        nomeVader(4,21);
                        break;
                    case 8:
                        ChapaYoda(60,17);
                        nomeYoda(4,21);
                        break;
                    case 9:
                        ChapaBobaFett(60,17);
                        nomeBobaFett(4,21);
                        break;
                    case 10:
                        ChapaObiLuke(60,17);
                        nomeObiLuke(4,21);
                        break;
                }
            }
        }
    }

    int tecla;
    tecla=getch();
    SetCor(7,0);
    system("cls");
}

void nomeBanda(int x, int y){
    SetCor(4,15);
    gotoxy(x,y);
    printf("Nome ");
    SetCor(0,15);
    printf("Banda da Cantina");
    SetCor(4,15);
    gotoxy(x,y+3);
    printf("Coligacao");
    gotoxy(x,y+4);
    printf("=========");
    SetCor(0,15);
    gotoxy(x,y+5);
    printf("Nos garantimos o circo.");
    gotoxy(x,y+6);
    printf("Ja o pao, eh com voce");
}

void ChapaBanda(int x, int y){
    int MaxCol = 44;
    gotoxy(x-MaxCol/2, y-6);
    printf("  /   \\                              /   \\  ");
    gotoxy(x-MaxCol/2, y-5);
    printf(" (     )             ___            (     ) ");
    gotoxy(x-MaxCol/2, y-4);
    printf("  (O O)             /   \\            (O O)  ");
    gotoxy(x-MaxCol/2, y-3);
    printf("  (/=\\)            (     )           (/=\\)  ");
    gotoxy(x-MaxCol/2, y-2);
    printf(" // I  \\            (O O)           // I \\\\ ");
    gotoxy(x-MaxCol/2, y-1);
    printf("||  I/~\\|           (/^\\)          ||  I  ||");
    gotoxy(x-MaxCol/2, y);
    printf(" \\\\ > # )          //---\\\\          \\\\ I // ");
    gotoxy(x-MaxCol/2, y+1);
    printf(" |\\(> O |         |()___()|          \\(I)/| ");
    gotoxy(x-MaxCol/2, y+2);
    printf(" ===>__/          (:::::::)          ==I=== ");
    gotoxy(x-MaxCol/2, y+3);
    printf(" | || |           .=======.          | I| | ");
    gotoxy(x-MaxCol/2, y+4);
    printf(" | || |           |_|| ||_|          | || | ");
    gotoxy(x-MaxCol/2, y+5);
    printf(" |_||_|           [ ]| |[ ]          |_||_| ");
    gotoxy(x-MaxCol/2, y+6);
    printf(" [_][__\\          ---------         /__][__\\");
}

void nomeR2D2(int x, int y){
    SetCor(4,15);
    gotoxy(x,y);
    printf("Nome ");
    SetCor(0,15);
    printf("R2-D2");
    SetCor(4,15);
    gotoxy(x,y+3);
    printf("Coligacao");
    gotoxy(x,y+4);
    printf("=========");
    SetCor(0,15);
    gotoxy(x,y+5);
    printf("Bip-bip-bop-bip-bop-bip");
}

void ChapaR2D2(int x, int y){
    int MaxCol = 11;
    gotoxy(x-MaxCol/2, y-5);
    printf("    ___    ");
    gotoxy(x-MaxCol/2, y-4);
    printf("   / ()\\   ");
    gotoxy(x-MaxCol/2, y-3);
    printf(" _|_____|_ ");
    gotoxy(x-MaxCol/2, y-2);
    printf("| | === | |");
    gotoxy(x-MaxCol/2, y-1);
    printf("|_|  O  |_|");
    gotoxy(x-MaxCol/2, y);
    printf(" ||  O  || ");
    gotoxy(x-MaxCol/2, y+1);
    printf(" ||__*__|| ");
    gotoxy(x-MaxCol/2, y+2);
    printf("|~ \\___/ ~|");
    gotoxy(x-MaxCol/2, y+3);
    printf("/=\\ /=\\ /=\\");
    gotoxy(x-MaxCol/2, y+4);
    printf("[_]_[_]_[_]");
}

void nomeJarJar(int x, int y){
    SetCor(4,15);
    gotoxy(x,y);
    printf("Nome ");
    SetCor(0,15);
    printf("Jar Jar Binks");
    SetCor(4,15);
    gotoxy(x,y+3);
    printf("Coligacao");
    gotoxy(x,y+4);
    printf("=========");
    SetCor(0,15);
    gotoxy(x,y+5);
    printf("A habilidade de falar nao");
    gotoxy(x,y+6);
    printf("o torna inteligente");
}

void ChapaJarJar(int x, int y){
    int MaxCol = 17;
    gotoxy(x-MaxCol/2, y-10);
    printf("        O_O      ");
    gotoxy(x-MaxCol/2, y-9);
    printf("       / ^ \\     ");
    gotoxy(x-MaxCol/2, y-8);
    printf("      /(<o>)\\    ");
    gotoxy(x-MaxCol/2, y-7);
    printf("     // \\:/ \\\\   ");
    gotoxy(x-MaxCol/2, y-6);
    printf("    //  ):(  \\\\  ");
    gotoxy(x-MaxCol/2, y-5);
    printf("    ' _/ : \\_ '  ");
    gotoxy(x-MaxCol/2, y-4);
    printf("     /  \\'/  \\   ");
    gotoxy(x-MaxCol/2, y-3);
    printf("    //|  /  |\\\\  ");
    gotoxy(x-MaxCol/2, y-2);
    printf("   // | (   | \\\\ ");
    gotoxy(x-MaxCol/2, y-1);
    printf("  //  |__\\__|  ||");
    gotoxy(x-MaxCol/2, y);
    printf(" //   (_____)  ||");
    gotoxy(x-MaxCol/2, y+1);
    printf("##\\   |\\    | /##");
    gotoxy(x-MaxCol/2, y+2);
    printf("||    | |\\  |  //");
    gotoxy(x-MaxCol/2, y+3);
    printf("      | | |\\|    ");
    gotoxy(x-MaxCol/2, y+4);
    printf("      | | | |    ");
    gotoxy(x-MaxCol/2, y+5);
    printf("      | | | |    ");
    gotoxy(x-MaxCol/2, y+6);
    printf("      | | | |    ");
    gotoxy(x-MaxCol/2, y+7);
    printf("      | | | |    ");
    gotoxy(x-MaxCol/2, y+8);
    printf("      | | | |    ");
    gotoxy(x-MaxCol/2, y+9);
    printf("      (_) (_)    ");
    gotoxy(x-MaxCol/2, y+10);
    printf("      ooo ooo    ");
}

void nomeC3PO(int x, int y){
    SetCor(4,15);
    gotoxy(x,y);
    printf("Nome ");
    SetCor(0,15);
    printf("C-3PO");
    SetCor(4,15);
    gotoxy(x,y+3);
    printf("Coligacao");
    gotoxy(x,y+4);
    printf("=========");
    SetCor(0,15);
    gotoxy(x,y+5);
    printf("Protocolo e Fluencia.");
    gotoxy(x,y+6);
    printf("A chave para falar com todos");
}

void ChapaC3PO(int x, int y){
    int MaxCol = 11;
    gotoxy(x-MaxCol/2, y-6);
    printf("   /~\\    ");
    gotoxy(x-MaxCol/2, y-5);
    printf("  |oo )   ");
    gotoxy(x-MaxCol/2, y-4);
    printf("  _\\=/_   ");
    gotoxy(x-MaxCol/2, y-3);
    printf(" /  _  \\  ");
    gotoxy(x-MaxCol/2, y-2);
    printf("//|/.\\|\\\\ ");
    gotoxy(x-MaxCol/2, y-1);
    printf("\\\\ \\_/  ||");
    gotoxy(x-MaxCol/2, y);
    printf(" \\|\\ /| ||");
    gotoxy(x-MaxCol/2, y+1);
    printf(" # _ _/  #");
    gotoxy(x-MaxCol/2, y+2);
    printf("  | | |   ");
    gotoxy(x-MaxCol/2, y+3);
    printf("  | | |   ");
    gotoxy(x-MaxCol/2, y+4);
    printf("  []|[]   ");
    gotoxy(x-MaxCol/2, y+5);
    printf("  | | |   ");
    gotoxy(x-MaxCol/2, y+6);
    printf(" /_]_[_\\  ");
}

void nomeYoda(int x, int y){
    SetCor(4,15);
    gotoxy(x,y);
    printf("Nome ");
    SetCor(0,15);
    printf("Mestre Yoda");
    SetCor(4,15);
    gotoxy(x,y+3);
    printf("Coligacao");
    gotoxy(x,y+4);
    printf("=========");
    SetCor(0,15);
    gotoxy(x,y+5);
    printf("Paciencia voce deve ter meu");
    gotoxy(x,y+6);
    printf("jovem Padawan. Sinta a Forca!");
}

void ChapaYoda(int x, int y){
    int MaxCol = 11;

    SetCor(10,15);
    gotoxy(x-MaxCol/2, y-6);
    printf("   _____   ");
    gotoxy(x-MaxCol/2, y-5);
    printf("(\\( O.O )/)");
    gotoxy(x-MaxCol/2, y-4);
    printf(" '(  %c  )' ",196);
    gotoxy(x-MaxCol/2, y-3);
    printf("   )   (   ");
    gotoxy(x-MaxCol/2, y-2);
    SetCor(6,15);
    printf("  %c%c%c%c%c%c%c   ",254,254,254,254,254,254,254);
    gotoxy(x-MaxCol/2, y-1);
    printf(" %c%c%c%c%c%c%c%c%c ",219,221,219,219,219,219,219,222,219);
    gotoxy(x-MaxCol/2, y);
    printf(" %c%c%c%c%c%c%c%c%c ",219,221,219,219,219,219,219,222,219);
    gotoxy(x-MaxCol/2, y+1);
    printf(" %c%c%c%c%c%c%c%c%c ",219,221,219,219,219,219,219,222,219);
    gotoxy(x-MaxCol/2, y+2);
    SetCor(10,15);
    printf(" (");
    SetCor(6,15);
    printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
    SetCor(10,15);
    printf(") ");
    SetCor(6,15);
    gotoxy(x-MaxCol/2, y+3);
    printf("  %c%c%c%c%c%c%c",219,219,219,219,219,219,219);
    gotoxy(x-MaxCol/2, y+4);
    printf("  %c%c%c%c%c%c%c",219,219,219,219,219,219,219);
    gotoxy(x-MaxCol/2, y+5);
    SetCor(10,15);
    printf("  (__(__)  ");
}

void nomeVader(int x, int y){
    SetCor(4,15);
    gotoxy(x,y);
    printf("Nome ");
    SetCor(0,15);
    printf("Darth Vader");
    SetCor(4,15);
    gotoxy(x,y+3);
    printf("Coligacao");
    gotoxy(x,y+4);
    printf("=========");
    SetCor(0,15);
    gotoxy(x,y+5);
    printf("Nao. EU, sou seu pai");
}

void ChapaVader(int x, int y){
    int MaxCol = 32;
    gotoxy(x-MaxCol/2, y-7);
    printf("             _.~~~~~~._         ");
    gotoxy(x-MaxCol/2, y-6);
    printf("           _/    ||    \\_       ");
    gotoxy(x-MaxCol/2, y-5);
    printf("          /      ||      \\      ");
    gotoxy(x-MaxCol/2, y-4);
    printf("         |       ||       |     ");
    gotoxy(x-MaxCol/2, y-3);
    printf("         |_______||_______|     ");
    gotoxy(x-MaxCol/2, y-2);
    printf("         |/ ---- \\/ ---- \\|     ");
    gotoxy(x-MaxCol/2, y-1);
    printf("         / (    )  (    ) \\     ");
    gotoxy(x-MaxCol/2, y);
    printf("        /\\  ---- () ----  /\\    ");
    gotoxy(x-MaxCol/2, y+1);
    printf("       /  \\     /||\\     /  \\   ");
    gotoxy(x-MaxCol/2, y+2);
    printf("      /    \\   /||||\\   /    \\  ");
    gotoxy(x-MaxCol/2, y+3);
    printf("     /      \\ /||||||\\ /      \\ ");
    gotoxy(x-MaxCol/2, y+4);
    printf("    /_       \\o======o/       _\\");
    gotoxy(x-MaxCol/2, y+5);
    printf("      `--...__|`--.--'|__...--' ");
    gotoxy(x-MaxCol/2, y+6);
    printf("             /        \\         ");
}

void nomeEstreladaMorte(int x, int y){
    SetCor(4,15);
    gotoxy(x,y);
    printf("Nome ");
    SetCor(0,15);
    printf("Estrela da Morte");
    SetCor(4,15);
    gotoxy(x,y+3);
    printf("Coligacao");
    gotoxy(x,y+4);
    printf("=========");
    SetCor(0,15);
    gotoxy(x,y+5);
    printf("Tenho tudo aquilo que o");
    gotoxy(x,y+6);
    printf("BRASIL precisa");
}

void ChapaEstreladaMorte(int x, int y){
    int MaxCol = 44;
    gotoxy(x-MaxCol/2, y-6);
    printf("    .          __---__                      ");
    gotoxy(x-MaxCol/2, y-5);
    printf("  .     .   .-'...:...'-.               .   ");
    gotoxy(x-MaxCol/2, y-4);
    printf("           / .  . : .__ .\\                  ");
    gotoxy(x-MaxCol/2, y-3);
    printf("    .     /........./  \\ .\\  .   .          ");
    gotoxy(x-MaxCol/2, y-2);
    printf("         / :  :   :| () | :\\                ");
    gotoxy(x-MaxCol/2, y-1);
    printf("        :...........\\__/....:         .     ");
    gotoxy(x-MaxCol/2, y);
    printf(" .      |___________________|             . ");
    gotoxy(x-MaxCol/2, y+1);
    printf("        |...................|              .");
    gotoxy(x-MaxCol/2, y+2);
    printf("  .     :  :  :   :   :   : :               ");
    gotoxy(x-MaxCol/2, y+3);
    printf("      .  \\................./      .         ");
    gotoxy(x-MaxCol/2, y+4);
    printf("          \\  .  . : .  .  /   .             ");
    gotoxy(x-MaxCol/2, y+5);
    printf(".      .   \\._........._./  .        .      ");
    gotoxy(x-MaxCol/2, y+6);
    printf("              -..___..-                .    ");
}

void nomeStormTrooper(int x, int y){
    SetCor(4,15);
    gotoxy(x,y);
    printf("Nome ");
    SetCor(0,15);
    printf("Stormtroopers");
    gotoxy(x+5,y+1);
    printf("Fives e Rex");
    SetCor(4,15);
    gotoxy(x,y+3);
    printf("Coligacao");
    gotoxy(x,y+4);
    printf("=========");
    SetCor(0,15);
    gotoxy(x,y+5);
    printf("Por um mundo mais igual");
}

void ChapaStormTrooper(int x, int y){
    int MaxCol = 27;

    gotoxy(x-MaxCol/2, y-7);
    printf("      /__\\           /__\\  ");
    gotoxy(x-MaxCol/2, y-6);
    printf("     |<><>|         |<><>| ");
    gotoxy(x-MaxCol/2, y-5);
    printf("     (_/\\_)         (_/\\_) ");
    gotoxy(x-MaxCol/2, y-4);
    printf("    /      \\       /      \\");
    gotoxy(x-MaxCol/2, y-3);
    printf("   //| __ |\\\\      ||/(===o");
    gotoxy(x-MaxCol/2, y-2);
    printf("  // |/  \\| \\\\     | /  \\ |");
    gotoxy(x-MaxCol/2, y-1);
    printf(" //  [][][]  ||    \\/][][\\/");
    gotoxy(x-MaxCol/2, y);
    printf("|'   |\\  /|  ['     |\\  /| ");
    gotoxy(x-MaxCol/2, y+1);
    printf("     |_||_|  I]     |_||_| ");
    gotoxy(x-MaxCol/2, y+2);
    printf("     [ ][ ]  I      [ ][ ] ");
    gotoxy(x-MaxCol/2, y+3);
    printf("     | || |         | || | ");
    gotoxy(x-MaxCol/2, y+4);
    printf("     |_||_|         |_||_| ");
    gotoxy(x-MaxCol/2, y+5);
    printf("    /__][_]_________[_][__\\");
}

void nomeObiLuke(int x, int y){
    SetCor(4,15);
    gotoxy(x,y);
    printf("Nome ");
    SetCor(0,15);
    printf("Obi-Wan Kenobi e");
    gotoxy(x+5,y+1);
    printf("Luke Skywalker");
    SetCor(4,15);
    gotoxy(x,y+3);
    printf("Coligacao");
    gotoxy(x,y+4);
    printf("=========");
    SetCor(0,15);
    gotoxy(x,y+5);
    printf("Que a forca esteja com voce!");
}

void ChapaObiLuke(int x, int y){
    int MaxCol = 43;
    gotoxy(x-MaxCol/2, y-7);
    printf("    ====           .*       _      ====    ");
    gotoxy((x-MaxCol/2) , (y-6));
    printf("   ~~o o          .*'      /o\\    (o o\")   ");
    gotoxy(x-MaxCol/2, y-5);
    printf("   _\\ -/_        .*' ..... \\_/    _\\- /_   ");
    gotoxy(x-MaxCol/2, y-4);
    printf("  /  \\ / \\      .*'              / \\  / \\  ");
    gotoxy(x-MaxCol/2, y-3);
    printf(" //|  | |\\\\    .*'              /   \\/   \\ ");
    gotoxy(x-MaxCol/2, y-2);
    printf("|| |  | | \\\\  /*'              / /| |  |\\ |");
    gotoxy(x-MaxCol/2, y-1);
    printf("|| |  | |  \\\\//                || | |  | ||");
    gotoxy(x-MaxCol/2, y);
    printf("(' |====|   <)                 (` | |  | `)");
    gotoxy(x-MaxCol/2, y+1);
    printf("   | || |                         | |  |   ");
    gotoxy(x-MaxCol/2, y+2);
    printf("   (_)(_)                         | |\\ |   ");
    gotoxy(x-MaxCol/2, y+3);
    printf("   |_||_|                        /  || \\   ");
    gotoxy(x-MaxCol/2, y+4);
    printf("   |_||_|                       /   ||_|\\  ");
    gotoxy(x-MaxCol/2, y+5);
    printf("  /__][__\\                     /____|[_]_\\ ");
}

void nomeBobaFett(int x, int y){
    SetCor(4,15);
    gotoxy(x,y);
    printf("Nome ");
    SetCor(0,15);
    printf("Boba Fett");
    SetCor(4,15);
    gotoxy(x,y+3);
    printf("Coligacao");
    gotoxy(x,y+4);
    printf("=========");
    SetCor(0,15);
    gotoxy(x,y+5);
    printf("Existe um preco por sua");
    gotoxy(x,y+6);
    printf("cabeca e eu vou coleta-lo.");
}

void ChapaBobaFett(int x, int y){
    y=y-1;

    int MaxCol = 43;
    //lINHA 1
    gotoxy(x-MaxCol/2, y-11);
    SetCor(8,15);
    printf("%c%c%c%c",220,220,220,220);
    //lINHA 2
    gotoxy(x-MaxCol/2, y-10);
    SetCor(0,8);
    printf("%c",177);
    SetCor(8,15);
    printf("%c%c%c%c%c",219,219,219,219,219);
    SetCor(7,15);
    printf("%c",220);
    //Linha 3
    gotoxy(x-MaxCol/2, y-9);
    printf(" ");
    SetCor(7,8);
    printf("%c",220);
    SetCor(8,15);
    printf("%c%c",178,223);
    //Linha 4
    SetCor(7,15);
    gotoxy(x-MaxCol/2, y-8);
    printf(" %c%c                                ",219,176);
    //Linha 5
    gotoxy(x-MaxCol/2, y-7);
    printf(" %c        ",219);
    SetCor(2,15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c      ",220,220,220,220,219,219,219,219,219,219,219,219,219,219,219,219,220,220,220);
    //Linha 6
    gotoxy(x-MaxCol/2, y-6);
    SetCor(7,15);
    printf(" %c     ",219);
    SetCor(2,15);
    printf("%c%c%c%c%c",220,219,219,219,219);
    SetCor(2,0);
    printf("%c%c%c%c%c%c%c%c",177,176,176,176,176,176,176,176);
    SetCor(2,15);
    printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
    SetCor(8,7);
    printf("%c",176);
    SetCor(2,15);
    printf("%c%c%c%c   ",219,219,219,220);
    //Linha 7
    gotoxy(x-MaxCol/2, y-5);
    SetCor(7,15);
    printf(" %c    ",219);
    SetCor(2,15);
    printf("%c%c%c",219,219,219);
    SetCor(2,0);
    printf("%c%c%c%c",177,177,176,176);
    SetCor(2,15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219);
    SetCor(8,7);
    printf("%c %c%c",176,177,176);
    SetCor(2,15);
    printf("%c%c%c  ",219,219,219);
    //Linha 8
    gotoxy(x-MaxCol/2, y-4);
    SetCor(7,15);
    printf(" %c   ",219);
    SetCor(2,15);
    printf("%c%c%c",219,219,219);
    SetCor(2,0); //sombra escura
    printf("%c%c%c",177,176,176);
    SetCor(2,15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    SetCor(8,7); //sombra clara
    printf("%c",176);
    SetCor(2,15);
    printf("%c%c%c%c%c ",219,219,219,219,219);
    //Linha 9
    gotoxy(x-MaxCol/2, y-3);
    SetCor(7,15);
    printf(" %c  ",219);
    SetCor(2,15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    SetCor(0,6);
    printf("%c",176);
    SetCor(2,15);
    printf("%c",219);
    SetCor(0,6);
    printf("%c",177);
    SetCor(2,15);
    printf("%c",219);
    SetCor(0,14);
    printf("%c",176);
    SetCor(2,15);
    printf("%c",219);
    SetCor(0,6);
    printf("%c",176);
    //Linha 10
    gotoxy(x-MaxCol/2, y-2);
    SetCor(7,15);
    printf(" %c  ", 219),
    SetCor(2,0);
    printf("          %c%c%c%c%c%c%c%c%c%c%c          ",223,223,223,223,223,223,223,223,223,223,223);
    //Linha 11
    gotoxy(x-MaxCol/2, y-1);
    SetCor(7,15);
    printf(" %c ",219);
    SetCor(4,0);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",177,219,219,219,219,219,219,219,219,219,220,220,220,220,220,220,220,220,220,220,220,220,219,219);
    SetCor(0,7);
    printf("%c",177);
    SetCor(4,0);
    printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
    //Linha 12
    gotoxy(x-MaxCol/2, y);
    SetCor(14,15);
    printf("%c%c ",219,219);
    SetCor(4,0);
    printf("%c%c      %c%c%c%c%c%c%c%c%c%c%c%c%c%c        %c%c",177,176,223,223,223,223,223,223,223,223,223,223,223,223,223,223,176,178);
    //Linha 13
    gotoxy(x-MaxCol/2, y+1);
    SetCor(7,15);
    printf("%c",219);
    SetCor(0,14);
    printf("%c%c", 176,176);
    SetCor(2,0);
    printf("%c", 178);
    SetCor(4,0);
    printf("%c%c%c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,220,220,220,220,220,220,220,220,220,220,220,220,219,219,219,219,223);
    //Linha 14
    gotoxy(x-MaxCol/2, y+2);
    SetCor(2,15);
    printf("  ");
    SetCor(6,0);
    printf("%c",178);
    SetCor(2,0);
    printf("%c  ",219);
    SetCor(4,0);
    printf("%c%c%c%c%c%c%c%c%c%c      ",223,223,219,219,219,219,219,219,219,178);
    SetCor(7,0);
    printf("%c%c",176,178);
    SetCor(4,0);
    printf("%c%c",219,219);
    SetCor(7,0);
    printf("%c", 177);
    SetCor(4,0);
    printf("%c%c%c%c%c%c ",219,219,177,223,223,176);
    SetCor(2,0);
    printf("%c",177);
    //Linha 15
    gotoxy(x-MaxCol/2, y+3);
    SetCor(6,15);
    printf("  ");
    SetCor(6,0);
    printf("%c",178);
    SetCor(2,0);
    printf("%c  %c  ",219,177);
    SetCor(4,0);
    printf("%c%c%c%c%c%c%c      ",223,219,219,219,219,219,219);
    SetCor(7,0);
    printf("%c",177);
    SetCor(4,0);
    printf("%c%c%c%c       ",219,219,219,223);
    SetCor(2,0);
    printf("%c",219);
    //Linha 16
    gotoxy(x-MaxCol/2, y+4);
    SetCor(2,15);
    printf("  ");
    SetCor(8,0);
    printf("%c",176);
    SetCor(2,0);
    printf("%c   ", 219);

    printf("%c%c  ",176,178);
    SetCor(4,0);
    printf("%c%c",219,219);
    SetCor(8,0);
    printf("%c",177);
    SetCor(4,0);
    printf("%c%c      ",219,219);
    SetCor(8,0);
    printf("%c",178);
    SetCor(4,0);
    printf("%c%c%c",219,219,219);
    SetCor(2,0);
    printf("  %c%c  %c %c",177,176,176,219);
    //Linha 17
    gotoxy(x-MaxCol/2, y+5);
    SetCor(2,15);
    printf("   ");
    SetCor(2,0);
    printf("%c %c %c%c%c  ",219,176,219,219,219);
    SetCor(4,0);
    printf("%c%c%c%c      %c%c%c  ",219,219,219,176,219,219,219);
    SetCor(2,0);
    printf("%c%c%c%c   %c",219,219,219,177,219);
    //Linha 18
    gotoxy(x-MaxCol/2, y+6);
    SetCor(2,15);
    printf("  ");
    SetCor(7,0);
    printf("%c",176);
    SetCor(2,0);
    printf("%c  %c%c%c%c%c  ",219,177,219,219,219,219);
    SetCor(4,0);
    printf("%c%c%c      %c%c%c ",178,219,219,219,219,177);
    SetCor(2,0);
    printf("%c%c%c%c%c   %c",219,219,219,219,219,219);
    //Linha 19
    gotoxy(x-MaxCol/2, y+7);
    SetCor(2,15);
    printf("   ");
    SetCor(2,15);
    printf("%c",223);
    SetCor(2,0);
    printf("%c %c%c%c",177,178,219,219);
    SetCor(7,0);
    printf("%c",176);
    SetCor(2,0);
    printf("%c%c  ",219,219);
    SetCor(4,0);
    printf("%c",219);
    SetCor(8,0);
    printf("%c      %c",177,177);
    SetCor(4,0);
    printf("%c",219);
    SetCor(2,0);
    printf(" %c%c",177,219);
    SetCor(7,0);
    printf("%c",178);
    SetCor(2,0);
    printf("%c%c%c%c %c",219,219,219,176,219,177);
    //Linha 20
    gotoxy(x-MaxCol/2, y+8);
    SetCor(2,15);
    printf("     ");
    SetCor(2,0);
    printf("%c%c%c%c%c%c%c  ",176,219,219,219,219,219,219);
    SetCor(4,0);
    printf("%c",219);
    SetCor(8,0);
    printf("%c      ",177);
    SetCor(4,0);
    printf("%c%c ",219,219);
    SetCor(2,0);
    printf("%c%c%c%c%c%c%c ",178,219,219,219,219,219,219);
    SetCor(2,15);
    printf("%c",223);
    //Linha 21
    gotoxy(x-MaxCol/2, y+9);
    SetCor(2,15);
    printf("        ");
    SetCor(2,15);
    printf("%c%c%c",223,223,223);
    SetCor(2,0);
    printf("%c  ",178);
    SetCor(4,0);
    printf("%c%c      %c%c ",219,219,219,219);
    SetCor(2,0);
    printf("%c",176);
    SetCor(2,15);
    printf("%c%c%c",223,223,223);
    //Linha 22
    gotoxy(x-MaxCol/2, y+10);
    SetCor(4,15);
    printf("              %c        ",223);
    SetCor(4,0);
    printf("%c",177);
}
