#include <stdio.h>

int main(){

    typedef struct produto
    {
        int codigo;
        char descricao[12];
        float preco;

    } Produto;

    // Criando as variaveis do tipo Struct Produto
    Produto prodA = {1, "Teclado", 98.50};
    Produto prodB = {2, "Mouse", 65.00};
    Produto prodC = {3, "Webcam", 130.00};
    Produto prodD = {0, "qualquer coisa", 12.00};

    //Cria um vetor e passar o conteudo para ele
    Produto vet [4];
    vet[0] = prodA;
    vet[1] = prodB;
    vet[2].codigo = prodC.codigo;
    strcpy(vet [2].descricao, prodC.descricao);
    vet[2].preco = prodC.preco;

    // Cria um vetor de ponteiro e passa os endereços para ele
    Produto* vet2 [4];
    vet2[0] = &prodA;
    vet2[1] = &prodB;
    vet2[2] = &prodC;
    vet2[3] = &prodD;

    vet2[2]->codigo = 100;
    vet2[3]->codigo = 123;
    vet2[3]->preco = 16.50;
    
    strcpy(vet2[1]->descricao, "Mouse sem fio");             //Modifica descricao do prodB
    strcpy(vet2[3]->descricao, "Prenchendo campo descriçao");//Modifica o conteudo de prodD

    return 0;
}