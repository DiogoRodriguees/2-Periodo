#include <stdio.h>
#include "pilha.h"

int main()
{
    int elem;
    int v[2] = {50, 60};
    Pilha *inicial = pilha_criar();

    if (!pilha_vazia(inicial))
    {
        printf("A pilha esta vazia no momento!\n");
    }

    pilha_empilhar(inicial, 10);
    pilha_empilhar(inicial, 20);
    pilha_empilhar(inicial, 30);
    pilha_empilhar(inicial, 40);
    pilha_imprimir(inicial); // Pilha: [40,30,20,10]

    if (pilha_desempilhar(inicial, &elem))
    {
        printf("O elemento %i foi removido\n", elem);
    }

    if (pilha_topo(inicial, &elem))
    {
        printf("Topo: %i\n", elem);
    }

    Pilha *nClone = pilha_clone(inicial);

    pilha_inverter(inicial);

    int tam = pilha_tamanho(inicial);
    pilha_empilharTodos(inicial, v, 2);

    char str[20] = "";
    if (pilha_toString(inicial, str))
    {
        printf("String: %s\n", str);
    }

    pilha_imprimir(inicial);
    pilha_destruir(&inicial);

    return 0;
}