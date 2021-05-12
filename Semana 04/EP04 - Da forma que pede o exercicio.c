#include <stdio.h>


int main(void){
    int codigo = 0;
    float qtd = 0;
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

    char menu[10][25] = {"Johnnie Walker",
                          "Smirnoff",
                          "Jack Daniels",
                          "Captain Morgan",
                          "Absolut",
                          "Ballantines",
                          "Jose Cuervo",
                          "Concha y Toro",
                          "Moet & Chandon",
                          "Havana Club"};

    printf(" 1 - %s\n",menu[0]);
    printf(" 2 - %s\n",menu[1]);
    printf(" 3 - %s\n",menu[2]);
    printf(" 4 - %s\n",menu[3]);
    printf(" 5 - %s\n",menu[4]);
    printf(" 6 - %s\n",menu[5]);
    printf(" 7 - %s\n",menu[6]);
    printf(" 8 - %s\n",menu[7]);
    printf(" 9 - %s\n",menu[8]);
    printf("10 - %s\n",menu[9]);
    printf("\nInforme o codigo da bebida que voce desejas comprar: ");
    scanf("%d",&codigo);
    int flag =0;
    switch (codigo){
        case 1:
            flag=1;
            break;
        case 2:
            flag=1;
            break;
        case 3:
            flag=1;
            break;
        case 4:
            flag=1;
            break;
        case 5:
            flag=1;
            break;
        case 6:
            flag=1;
            break;
        case 7:
            flag=1;
            break;
        case 8:
            flag=1;
            break;
        case 9:
            flag=1;
            break;
        case 10:
            flag=1;
            break;
        default:
            printf("\n\nCodigo do produto nao cadastrado!!!\n\n");
//poderia colocar um return 0 aqui e nao precisaria de flag e nem switch
    }
    if (flag){
        codigo--;
        printf("Informe a quantidade de %s voce deseja comprar: ", menu[codigo]);
        scanf("%f",&qtd);
        if (qtd<=0){
            printf("\nA quantidade a ser comprada deve ser maior que Zero!!!\n\n");

        }
        else{
            printf("\nProduto comprado: %s\n", menu[codigo]);
            printf("valor unitario: %.2f\n", preco[codigo]);
            printf("Valor total da compra: %.2f\n\n\n",qtd*preco[codigo]);
        }
    }
}
