#include <stdio.h>

int main(){

    typedef struct produto
    {
        int codigo;
        char descricao[12];
        float preco;
    } Produto;

    Produto prod = {1, "Teclado", 98.50};
    Produto* p = &prod;

    Produto* pi = &prod;
    Produto* pc = &prod.descricao;
    Produto* pf = &prod.preco;

    //Imprime para comparaçao dos endereços
    printf("Codigo *   : %u\n", &prod.codigo);
    printf("descricao *: %u\n", &prod.descricao);
    printf("preco *    : %u\n", &prod.preco);
    printf("p *        : %i\n", p);
    printf("pi *       : %i\n", pi);
    printf("pc *       : %i\n", pc);
    printf("pf *       : %i\n", pf);

    return 0;
}