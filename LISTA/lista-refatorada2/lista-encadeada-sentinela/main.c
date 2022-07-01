#include <stdio.h>
#include "lista.h"

int main()
{
    char str[50];
    int elemento;
    Lista *l = lista_criar();

    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_anexar(l, 40);

    lista_inserir(l, 25, 4);
    lista_imprimir(l); // Lista: [10,20,30,40,25]

    if (lista_removerPosicao(l, 0, &elemento)) printf("Nessa posicao estava o elemento: %i\n", elemento);
    // Lista: [20,30,40,25]
    
    elemento = lista_removerElemento(l, 30); // Lista: [20,40,25]
    printf("O Elemento removido estva na posicao: %i\n", elemento);

    if (lista_substituir(l, 1, 20)) printf("O elemento foi substituido!!\n"); 
    // Lista: [20,20,25]

    int n = lista_posicao(l, 20);
    printf("Esse elemento esta na posicao %i!\n", n);

    if (lista_buscar(l, 2, &elemento)) printf("Essa posicao possui o elemento %i!!\n", elemento);

    int tam = lista_tamanho(l);
    printf("Tamanho: %i\n", tam);

    if (lista_vazia(l)) printf("lista vazia\n"); // Lista: [20,20,25]

    lista_toString(l, str); 
    printf("String: %s\n", str); // String: [20,20,25]

    lista_imprimir(l); // Lista: [20,20,25]
    lista_destruir(&l);

    return 0;
}
