#include "pilha.h"

#define TAM_INICIAL 5

/**************************************
 * DADOS
 **************************************/
struct pilha
{
    TipoElemento *vetor;
    int tamVetor;
    int qtdeElementos;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
// Desenvolva as funções
Pilha *pilha_criar()
{
    Pilha *origem = (Pilha *)malloc(sizeof(Pilha));
    origem->qtdeElementos = 0;
    origem->vetor = (TipoElemento *)calloc(TAM_INICIAL, sizeof(TipoElemento));
    origem->tamVetor = TAM_INICIAL;

    return origem;
}

void pilha_destruir(Pilha **endereco)
{
    *endereco = NULL;
    free(*endereco);
}

bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{
    Pilha *aux = p;
    int qtd = aux->qtdeElementos;

    if (qtd == aux->tamVetor)
        return false;

    aux->vetor[qtd] = elemento;
    aux->qtdeElementos += 1;

    return true;
}

bool pilha_desempilhar(Pilha *p, TipoElemento *saida)
{
    int qtd = (p->qtdeElementos) - 1;

    *saida = p->vetor[qtd - 1];
    p->vetor[qtd] = NULL;
    p->qtdeElementos -= 1;

    return true;
}

bool pilha_topo(Pilha *p, TipoElemento *saida)
{

    int qtd = p->qtdeElementos;

    *saida = p->vetor[qtd - 1];
    return true;
}

bool pilha_vazia(Pilha *p)
{
    if ( p->vetor[0]== NULL)
    {
        return true;
    }

    return false;
}

void pilha_imprimir(Pilha *p)
{

    printf("Pilha: ");
    printf("[");
    for (int i = 0; i < p->qtdeElementos; i++)
    {
        printf("%i", p->vetor[i]);
        if (i < (p->qtdeElementos - 1))
        {
            printf(",");
        }
    }
    printf("]\n");
}

int pilha_tamanho(Pilha *p)
{
    return p->tamVetor;
}

Pilha *pilha_clone(Pilha *p)
{
    Pilha *clone = (Pilha *)malloc(sizeof(Pilha));
    clone->qtdeElementos = p->qtdeElementos;
    clone->tamVetor = p->tamVetor;
    clone->vetor = (TipoElemento *)calloc(clone->tamVetor, sizeof(TipoElemento));

    for (int i = 0; i < p->qtdeElementos; i++)
    {
        clone->vetor[i] = p->vetor[i];
    }

    return clone;
}
void pilha_inverter(Pilha *p)
{
    TipoElemento *pInvertido = (TipoElemento *)malloc(sizeof(TipoElemento));

    int aux = p->qtdeElementos - 1;
    for (int i = 0; i < p->qtdeElementos; i++)
    {
        pInvertido[i] = p->vetor[aux];
        aux--;
    }

    p->vetor = pInvertido;
}

bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor)
{

    for (int i = 0; i < tamVetor; i++)
    {
        p->vetor[p->qtdeElementos] = vetor[i];
        p->qtdeElementos++;
    }

    return true;
}

bool pilha_toString(Pilha *f, char *str)
{

    strcat(str, "[");
    for (int i = 0; i < f->tamVetor; i++)
    {
        char copy[50];

        sprintf(copy, "%i", f->vetor[i]);
        strcat(str, copy);
        if (i < (f->tamVetor - 1))
        {
            strcat(str, ",");
        }
    }
    strcat(str, "]");

    return true;
}