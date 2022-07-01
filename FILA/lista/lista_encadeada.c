#include "lista.h"

typedef struct no
{
    TipoElemento dado;
    struct no *ant;
    struct no *prox;
} No;

typedef struct
{
    No *inicio;
    No *fim;
    int qtde;
} Lista;

Lista *lista_criar()
{
    Lista *nova = (Lista *)malloc(sizeof(Lista));
    nova->inicio = NULL;
    nova->fim = NULL;
    nova->qtde = 0;

    return nova;
}

void lista_destruir(Lista **endereco);

bool lista_anexar(Lista *l, TipoElemento elemento)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->dado = elemento;
    novoNo->prox = NULL;

    if (lista_vazia(l))
    {
        l->fim = novoNo;
        l->inicio = novoNo;
        novoNo->ant = NULL;
    }
    else
    {
        novoNo->ant = l->fim;
        l->fim = novoNo;
    }

    l->qtde++;

    return true;
}

bool lista_inserir(Lista *l, TipoElemento elemento, int posicao);

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco);
int lista_removerElemento(Lista *l, TipoElemento elemento);

bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento){
    No *aux = l->inicio;

    for (int i = 0; i < l->qtde; i++)
    {
        if(i == posicao)
        {
            aux->dado = novoElemento;
        }
        aux = aux->prox;
    }
    return true;
}

int lista_posicao(Lista *l, TipoElemento elemento){
    int count = 0;

    No *aux = l->inicio;

    for (int i = 0; i < l->qtde; i++)
    {
        if(aux->dado == elemento){
            return count;
        }
        count++;
        aux = aux->prox;
    }
}

bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco)
{
    No *aux = l->inicio;

    for (int i = 0; i < l->qtde; i++)
    {
        if (i == posicao)
        {
            *endereco = aux->dado;
            break;
        }
        aux = aux->prox;
    }

    return true;
}

int lista_tamanho(Lista *l)
{
    return l->qtde;
}

bool lista_vazia(Lista *l)
{
    if (l->inicio == NULL && l->fim == NULL)
    {
        return true;
    }
    return false;
}

bool lista_toString(Lista *l, char *str)
{
    No *aux = l->inicio;

    strcat(str, "[");
    for (int i = 0; i < l->qtde; i++)
    {
        char cmp[10];
        sprintf(cmp, "%i", aux->dado);
        strcat(str, cmp);

        if (i < (l->qtde - 1))
        {
            strcat(str, ",");
        }
    }
    strcat(str, "]");

    return true;
}