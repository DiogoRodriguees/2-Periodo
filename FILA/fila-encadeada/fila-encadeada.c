#include "fila.h"

/**************************************
 * DADOS
 **************************************/
typedef struct no
{
    int dado;
    struct no *prox;
} No;

struct fila
{
    No *inicio;
    No *fim;
    int qtde;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
Fila *fila_criar()
{
    Fila *novaFila = (Fila *)malloc(sizeof(Fila));
    novaFila->inicio = NULL;
    novaFila->fim = NULL;
    novaFila->qtde = 0;
    return novaFila;
}

void fila_destruir(Fila **enderecoFila){
    Fila* f = *enderecoFila;
	Fila* aux;

	while (f->inicio != NULL)
	{
		aux = f->inicio;
		f->inicio = f->inicio->prox;
		free(aux);
	}
    free(f);
}

bool fila_inserir(Fila *f, TipoElemento elemento)
{
    No *aux = (No *)malloc(sizeof(No));
    aux->dado = elemento;
    aux->prox = NULL;

    if (f->inicio == NULL)
    {
        f->inicio = aux;
        return true;
    }
    else
    {
        f->fim = aux;
    }

    No *aux2 = f->inicio;

    while (aux2 != NULL)
    {
        if (aux2->prox == NULL)
        {
            aux2->prox = aux;
            break;
        }
        aux2 = aux2->prox;
    }
    f->qtde++;
    return true;
}

bool fila_remover(Fila *f, TipoElemento *saida) // estratégia do scanf
{
    if (!fila_vazia(f))
    {
        *saida = f->inicio->dado;
        f->inicio = f->inicio->prox;
        f->qtde--;
        return true;
    }
    else
    {
        return false;
    }
}
bool fila_primeiro(Fila *f, TipoElemento *saida) // estratégia do scanf
{
    *saida = f->inicio->dado;
}

bool fila_vazia(Fila *f)
{
    if (f->inicio == NULL)
    {
        return true;
    }
    return false;
}

int fila_tamanho(Fila *f)
{
    return f->qtde;
}

void fila_imprimir(Fila *f)
{
    No *aux = f->inicio;

    if (!fila_vazia(f))
    {

        printf("Fila: ");
        printf("[");
        while (aux != NULL)
        {
            printf("%i", aux->dado);
            if (aux->prox != NULL)
            {
                printf(",");
            }
            aux = aux->prox;
        }
        printf("]");
        printf("\n");
    }

    else{
        printf("Pilha vazia, sem elementos para imprimir\n");
    }
}

Fila *fila_clone(Fila *f)
{
    Fila *clone = (Fila *)malloc(sizeof(Fila));
    clone->inicio = NULL;
    clone->fim = NULL;
    clone->qtde = 0;
    No *aux = f->inicio;

    while (aux != NULL)
    {
        fila_inserir(clone, aux->dado);
        aux = aux->prox;
    }
    return clone;
}

bool fila_toString(Fila *f, char *str)
{
    No *aux = f->inicio;
    str[0] = '\0';
    strcat(str, "[");
    while (aux != NULL)
    {
        char novo[50];
        sprintf(novo, "%i", aux->dado);
        strcat(str, novo);
        if (aux->prox != NULL)
        {
            strcat(str, ",");
        }
        aux = aux->prox;
    }
    strcat(str, "]");
}

bool fila_inserirTodos(Fila *f, TipoElemento *vetor, int tamVetor)
{
    No *aux = f->inicio;
    for (int i = 0; i < tamVetor; i++)
    {
        fila_inserir(f, vetor[i]);
    }
    return true;
}
