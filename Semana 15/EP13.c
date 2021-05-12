#include<stdio.h>

#define N 10

struct livro {
    char titulo[20];
    char autor[20];
    char estilo[10];
    int codigo;
    float preco;
};

struct livro ler_livro();
void imprime_livro(struct livro);

void main(){
    struct livro book[N];

    for (int i=0; i<N; i++){
        printf(" LIVRO %d\n", i+1);
        printf("=========\n");
        book[i] = ler_livro();
        //ler_livro(&book[i])
        //imprime_carro(car[i]);
    }

    printf("\n\n");

    for (int i=0; i<N; i++){
        printf(" LIVRO %d\n", i+1);
        printf("=========\n");
        //book[i] = ler_livro();
        imprime_livro(book[i]);
    }

    printf("\n\n");
}

struct livro ler_livro(){
    struct livro book;
    printf("Informe o nome do livro: ");
    fflush(stdin);
    gets(book.titulo);
    printf("Informe o nome do autor do livro: ");
    fflush(stdin);
    gets(book.autor);
    printf("Informe o estilo do livro: ");
    fflush(stdin);
    gets(book.estilo);
    printf("Informe o codigo do livro: ");
    fflush(stdin);
    scanf("%d", &book.codigo);
    printf("Informe o preco do livro (R$): ");
    fflush(stdin);
    scanf("%f", &book.preco);
    printf("\n\n");
    return book;
}

void imprime_livro(struct livro book){
    printf("O nome do livro eh %s", book.titulo);
    printf("\nO autor do livro eh %s", book.autor);
    printf("\nO estilo do livro eh %s", book.estilo);
    printf("\nO codigo do livro eh %d", book.codigo);
    printf("\nO preco do livro eh R$ %.2f\n\n", book.preco);
}
