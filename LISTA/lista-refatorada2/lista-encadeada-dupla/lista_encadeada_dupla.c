#include "lista.h"

typedef struct no
{
    TipoElemento dado;
    struct no *ant;
    struct no *prox;
} No;

struct lista
{
    No *inicio;
    No *fim;
    int qtde;
};

Lista *lista_criar()
{
    Lista *nova = (Lista *)malloc(sizeof(Lista));
    nova->inicio = NULL;
    nova->fim = NULL;
    nova->qtde = 0;

    return nova;
}

void lista_destruir(Lista **endereco){
    Lista* l = *endereco;
    No* aux = l->inicio;
    No* aux2;

    while (aux!=NULL)
    {
        aux2 = aux;
        aux = aux->prox;
        free(aux);
    }
    l = NULL;
    free(l);
}

bool lista_anexar(Lista *l, TipoElemento elemento)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->dado = elemento;
    novoNo->prox = NULL;
    novoNo->ant = NULL;

    if (lista_vazia(l))
    {
        l->fim = novoNo;
        l->inicio = novoNo;
    }
    else
    {
        novoNo->ant = l->fim;
        l->fim->prox = novoNo;
        l->fim = novoNo;
    }

    l->qtde += 1;

    return true;
}

bool lista_inserir(Lista *l, TipoElemento elemento, int posicao)
{
    int i = 0;
    No *aux = l->inicio;

    // Cria um No e inseri os novos dados
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->dado = elemento;
    novoNo->ant = NULL;
    novoNo->prox = NULL;

    if(posicao > l->qtde){
        printf("Impossivel inserir!");
        return false;
    }
    if (lista_vazia(l))
    {
        l->inicio = novoNo;
        l->fim = novoNo;
    }
    if(posicao == l->qtde){
        lista_anexar(l, elemento);
        return true;
    }
    while (aux != NULL)
    {
        // Verifica se a posicao é a primeira e faz o encadeamento
        if (i == posicao && posicao == 0)
        {
            // Faz oo encadeamento
            aux->ant = novoNo;
            novoNo->prox = aux;
            l->inicio = novoNo;
        }

        // Faz o encadeamento das demais posições
        if (i == posicao && posicao != 0 && posicao < l->qtde)
        {
            // Atualizção os ponteiros do novoNo
            novoNo->prox = aux;
            novoNo->ant = aux->ant;

            // Faz o encadeamento do novoNo, colocando ele na posição desejada
            aux->ant->prox = novoNo;
            aux->ant = novoNo;            
        }
        
        i++;
        aux = aux->prox;
    }

    l->qtde += 1; // Aumenta a quantidade de elementos
    return true;
}

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco)
{
    No *aux = l->inicio;
    No* ant;
    No* prox;
    int i = 0;

    while (aux!= NULL)
    {
        if(i == posicao && posicao!= 0 && posicao!=(l->qtde-1)){
            ant = aux->ant;
            prox = aux->prox;
            ant->prox = prox;
            prox->ant = ant;
            *endereco = aux->dado;
        }
        if(i == posicao &&  posicao==(l->qtde -1)){
            ant = aux->ant;
            prox = aux->prox;
            ant->prox = prox;
            *endereco = aux->dado;
            l->fim = aux->ant;
        }
        if(i == posicao && posicao== 0){
            l->inicio = aux->prox;
            aux->prox->ant = aux->ant;
            *endereco = aux->dado;
        }
        i++;
        aux = aux->prox;
    }
    free(aux);
    l->qtde--;

    return true;
}

int lista_removerElemento(Lista *l, TipoElemento elemento)
{
    No *aux = l->inicio;
    int rem = 0;

    // aux vai ate o no que sera removido
    while (aux->dado != elemento)
    {
        aux = aux->prox;
        rem++;
    }
    
    // Desencadeando o no
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;


    // Desalocando o no da memoria
    free(aux);
    l->qtde--;
    return rem;
}

bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento)
{
    No *aux = l->inicio;

    for (int i = 0; i < l->qtde; i++)
    {
        if (i == posicao) aux->dado = novoElemento;
        aux = aux->prox;
    }

    return true;
}

int lista_posicao(Lista *l, TipoElemento elemento)
{
    int posicao = 0;
    No *aux = l->inicio;

    while (aux != NULL)
    {
        if (aux->dado == elemento) return posicao; // Retorna a posição do elemeto, caso encontrado.
        posicao++;
        aux = aux->prox;
    }

    return -1;
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
    str[0] = '\0';

    strcat(str, "[");
    for (int i = 0; i < l->qtde; i++)
    {
        char cmp[10];
        sprintf(cmp, "%i", aux->dado); // Transferi o valor inteira pra o "cmp" em forma de char
        strcat(str, cmp); // Concatena o valor recebido na string: str.

        if (i < (l->qtde - 1)) strcat(str, ",");
        aux = aux->prox;
    }
    strcat(str, "]");

    return true;
}

void lista_imprimir(Lista *l)
{
    No *aux = l->inicio;

    printf("Lista: [");
    while (aux != NULL)
    {
        printf("%i", aux->dado);
        if (aux->prox != NULL) printf(",");
        aux = aux->prox;
    }
    printf("]\n");
}