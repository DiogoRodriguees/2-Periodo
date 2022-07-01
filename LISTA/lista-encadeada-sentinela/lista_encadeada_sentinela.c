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

Lista *lista_criar()
{
    Lista *nova = (Lista *)malloc(sizeof(Lista));
    No *n = (No *)malloc(sizeof(No));
    nova->sentinela->prox = nova->sentinela;
    nova->sentinela->ant = nova->sentinela;
    nova->qtde = 0;

    return nova;
}

void lista_destruir(Lista **endereco)
{
    Lista *l = *endereco;
    No *aux = l->sentinela->ant;
    No *aux2;
    while (aux != l->sentinela->prox)
    {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }

    free(*endereco);
}

bool lista_anexar(Lista *l, TipoElemento elemento)
{
    No *aux = l->sentinela;
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->dado = elemento;

    if (lista_vazia(l))
    {
        aux->prox = novoNo;
        aux->ant = novoNo;
        novoNo->prox = aux;
        novoNo->ant = aux;
    }
    else
    {
        novoNo->prox = aux;      // novono "prox" aponta para o sentinela
        novoNo->ant = aux->ant;  // novoNo "ant" aponta para o ultimo
        aux->ant->prox = novoNo; // o "prox" do ultimo elemento aponta para o novoNo
        aux->ant = novoNo;       // o "ant" do sentunela aponta para o ultimo
    }
    l->qtde+=1;
    return true;
}

bool lista_inserir(Lista *l, TipoElemento elemento, int posicao)
{
    int count = 0;
    No *aux = l->sentinela->prox;
    No *fim = l->sentinela->ant;
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->dado = elemento;

    if (posicao > l->qtde)
    {
        printf("Imposivel inserir");
        return false;
    }

    if (posicao == l->qtde) lista_anexar(l, elemento);
    
    if (lista_vazia(l))
    {
        aux->ant = novoNo;     // Atulaiza o Fim da lista
        aux->prox = novoNo;    // Atualiza o Começo da lista
        novoNo->ant = novoNo;  // Nova "ant" aponta para o final
        novoNo->prox = novoNo; // Novo "prox" aponta para o começo
    }

    while (aux != fim->prox)
    {
        if (count == posicao)
        {
            novoNo->prox = aux;
            novoNo->ant = aux->ant;
            aux->ant->prox = novoNo;
            aux->ant = novoNo;
        }
        count++;
        aux = aux->prox;
    }

    l->qtde += 1;
    return true;
}

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco)
{
    No *aux = l->sentinela->prox;

    if (lista_vazia(l))
    {
        printf("Impossivel remove!! Lista vazia.\n");
        return false;
    }

    // Leva o aux até a posição indicada
    while (posicao >= 0) {
        posicao--;
        aux = aux->prox;
    }

    // Guarda o dado contido na posição indicada
    *endereco = aux->dado;

    // Faz o desencadeamento
    aux->prox->ant = aux->ant;
    aux->ant->prox = aux->prox;

    //Desaloca o No e atualiza a quantidade de elementos
    free(aux);
    l->qtde-=1;
        
    return true;
}

int lista_removerElemento(Lista *l, TipoElemento elemento)
{
    No *aux = l->sentinela->prox;
    No *fim = l->sentinela;
    int i = 0;
    int itemRem;

    if (lista_vazia(l))
    {
        printf("Impossivel remover!! Lista vazia.\n");
        return -1;
    }

    while(aux != fim){
        if(aux->dado == elemento){
            aux->prox->ant = aux->ant;
            aux->ant->prox = aux->prox;
            free(aux);
            itemRem = i;
        }
        i++;
        aux = aux->prox;
    }

    l->qtde-= 1;
    return itemRem;
}

bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento)
{
    No *aux = l->sentinela->prox;

    //Procura o No da posição indicada
    while (posicao >= 0) {
        posicao--;
        aux = aux->prox;
    }
    
    // Substitui o elemento da posição encontrada
    aux->dado = novoElemento;
        
    return true;
}

int lista_posicao(Lista *l, TipoElemento elemento)
{
    int i = 0;
    No *aux = l->sentinela->prox;
    while (aux != l->sentinela->ant)
    {
        if (aux->dado == elemento)
        {
            return i;
        }
        i++;
        aux = aux->prox;
    }
    return -1;
}

bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco)
{
    int i = 0;
    No *aux = l->sentinela->prox;

    while (posicao >= 0) {
        posicao--;
        aux = aux->prox;
    }
    
    
    *endereco = aux->dado;
        
    return false;
}

int lista_tamanho(Lista *l)
{
    return l->qtde;
}

bool lista_vazia(Lista *l)
{
    if (l->sentinela->ant == l->sentinela && l->sentinela->prox == l->sentinela) return true;
    return false;
}

bool lista_toString(Lista *l, char *str)
{
    No *aux = l->sentinela->prox;
    No *fim = l->sentinela;
    str[0] = '\0';
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
    No *fim = l->sentinela->ant;

    printf("Lista: [");
    while (aux != fim->prox)
    {
        printf("%i", aux->dado);
        if(aux->prox != fim->prox){
            printf(",");
        }
        aux = aux->prox;
    }
    printf("]\n");
}