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
    lista_imprimir(l);
    if (lista_removerPosicao(l, 0, &elemento)) printf("Nessa posicao estava o elemento: %i\n", elemento);

    elemento = lista_removerElemento(l, 30);
    printf("O Elemento removido estva na posicao: %i\n", elemento);

    if (lista_substituir(l, 1, 20)) printf("O elemento foi substituido!!\n");
    
    int n = lista_posicao(l, 20);
    printf("Esse elemento esta na posicao %i!\n", n);

    if (lista_buscar(l, 2, &elemento)) printf("Essa posicao possui o elemento %i!!\n", elemento);    

    int tam = lista_tamanho(l);
    printf("Tamanho: %i\n", tam);

    if (lista_vazia(l)) printf("lista vazia\n");

    lista_toString(l, str);
    printf("String: %s\n", str);

    lista_imprimir(l);
    lista_destruir(&l);

    return 0;
}
