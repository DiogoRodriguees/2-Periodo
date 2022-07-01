#include "lista.h"

typedef struct no
{
    TipoElemento dado;
    struct no *ant;
    struct no *prox;
} No;

struct lista
{
    No *sentinela;
    int qtde;
};

No *procuraNo(int posicao, No *aux)
{
    while (posicao > 0)
    {
        posicao--;
        aux = aux->prox;
    }

    return aux;
}

void encadeamentoListaVazia(No *aux, No *novo)
{
    // Atualiza o Sentinela
    aux->prox = novo;
    aux->ant = novo;

    // Atualiza o novoNo
    novo->ant = aux;
    novo->prox = aux;
}

int devolvePosicao(No *aux, TipoElemento elemento)
{
    No *fim = aux->ant;
    int i = 0;
    while (aux != fim)
    {
        if (aux->dado == elemento)
            return i;
        aux = aux->prox;
        i++;
    }
    return -1;
}

Lista *lista_criar()
{
    Lista *nova = (Lista *)malloc(sizeof(Lista));
    nova->sentinela = (No *)malloc(sizeof(No));
    nova->sentinela->prox = nova->sentinela;
    nova->sentinela->ant = nova->sentinela;
    nova->qtde = 0;

    return nova;
}

void lista_destruir(Lista **endereco)
{
    No *aux2;
    Lista *l = *endereco;
    No *aux = l->sentinela->prox;

    while (aux != l->sentinela)
    {
        aux2 = aux;      // Passa o No que será desalocado
        aux = aux->prox; // Atualiza o No
        free(aux2);      // Desaloca o No atual
    }

    free(*endereco);
}

bool lista_anexar(Lista *l, TipoElemento elemento)
{
    No *aux = l->sentinela;
    No *novoNo = (No *)malloc(sizeof(No));

    if (lista_vazia(l))
    {
        encadeamentoListaVazia(aux, novoNo);
    }
    else
    {
        // Atualiza o novoNo
        novoNo->prox = aux;
        novoNo->ant = aux->ant;
        novoNo->dado = elemento;

        // Atualiza o sentinela
        aux->ant->prox = novoNo;
        aux->ant = novoNo;
    }

    l->qtde++;

    return true;
}

bool lista_inserir(Lista *l, TipoElemento elemento, int posicao)
{
    No *aux = l->sentinela->prox;
    No *novoNo = (No *)malloc(sizeof(No));

    novoNo->dado = elemento;

    if (posicao > l->qtde) return false;

    if (lista_vazia(l))
    {
        encadeamentoListaVazia(aux, novoNo);
        l->qtde++;
        return true;
    }

    // Coloca o aux na posição desejada
    aux = procuraNo(posicao, aux);

    // Atualiza os dados do novoNo
    novoNo->prox = aux;
    novoNo->ant = aux->ant;
    novoNo->dado = elemento;

    // Faz o encadeamento do novoNo
    aux->ant->prox = novoNo;
    aux->ant = novoNo;

    l->qtde++;

    return true;
}

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco)
{
    No *aux = l->sentinela->prox;

    if (lista_vazia(l)) return false;

    // Coloca o aux até a posição indicada
    aux = procuraNo(posicao, aux);

    // Guarda o dado da posição indicada 
    *endereco = aux->dado;

    // Faz o desencadeamento
    aux->prox->ant = aux->ant;
    aux->ant->prox = aux->prox;

    // Desaloca o No
    free(aux);

    l->qtde -= 1;

    return true;
}

int lista_removerElemento(Lista *l, TipoElemento elemento)
{
    No *aux = l->sentinela->prox;

    if (lista_vazia(l)) return -1;

    int i = devolvePosicao(aux, elemento); // Encontra a posição do elemento
    aux = procuraNo(i, aux);               // Leva o aux ate a posição encontrada

    // Faz o desencadeamento o elemento
    aux->prox->ant = aux->ant;
    aux->ant->prox = aux->prox;

    // Desaloca o aux
    free(aux);

    l->qtde -= 1;

    return i;
}

bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento)
{
    No *aux = l->sentinela->prox;

    // Coloca o aux na posição desejada
    aux = procuraNo(posicao, aux);

    // Substitui o elemento da posição encontrada
    aux->dado = novoElemento;

    return true;
}

int lista_posicao(Lista *l, TipoElemento elemento)
{
    No *aux = l->sentinela->prox;
    int i = devolvePosicao(aux, elemento);

    return -1;
}

bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco)
{
    No *aux = l->sentinela->prox;

    // Coloca o aux na posição desejada
    aux = procuraNo(posicao, aux);

    // Devolve o conteúdo da posição indicada
    *endereco = aux->dado;

    return true;
}

int lista_tamanho(Lista *l)
{
    return l->qtde;
}

bool lista_vazia(Lista *l)
{
    if (l->qtde) return true;

    return false;
}

bool lista_toString(Lista *l, char *str)
{
    str[0] = '\0';
    No *aux = l->sentinela->prox;
    No *fim = l->sentinela;

    strcat(str, "[");
    while (aux != fim)
    {
        char c[50];
        sprintf(c, "%i", aux->dado);
        strcat(str, c);

        if (aux->prox != fim) strcat(str, ",");
        aux = aux->prox;
    }
    strcat(str, "]");
    return true;
}

void lista_imprimir(Lista *l)
{
    No *aux = l->sentinela->prox;

    printf("Lista: [");

    while (aux != l->sentinela)
    {
        printf("%i", aux->dado);
        if (aux->prox != l->sentinela) printf(",");
        
        aux = aux->prox;
    }

    printf("]\n");
}