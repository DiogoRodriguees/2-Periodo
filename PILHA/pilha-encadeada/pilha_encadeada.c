#include "pilha.h"

/**************************************
 * DADOS
 **************************************/
typedef struct no
{
	TipoElemento dado;
	struct no *prox;
} No;

struct pilha
{
	No *topo;
	int qtdeElementos;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/

// Desenvolva as funções
Pilha *pilha_criar()
{
	Pilha *novaPilha = (Pilha *)malloc(sizeof(Pilha));
	novaPilha->qtdeElementos = 0;
	novaPilha->topo = NULL;

	return novaPilha;
}

void pilha_destruir(Pilha **endereco)
{
	Pilha *p = *endereco;
	No *aux = p->topo;
	No *aux2 = aux->prox;

	while (aux2 != NULL)
	{
		free(aux);
		aux = aux2;
		aux2 = aux2->prox;
	}

	aux2 = NULL;
	free(aux2);
	aux = NULL;
	free(aux);
	p = NULL;
	free(p);
}

bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{
	No *aux = (No *)malloc(sizeof(No));
	aux->dado = elemento;
	aux->prox = p->topo;
	p->topo = aux;
	p->qtdeElementos++;
	return true;
}

bool pilha_desempilhar(Pilha *p, TipoElemento *saida)
{
	*saida = p->topo->dado;
	p->topo = p->topo->prox;

	return true;
}

bool pilha_topo(Pilha *p, TipoElemento *saida)
{
	*saida = p->topo->dado;

	return true;
}

bool pilha_vazia(Pilha *p)
{
	if (p->topo == NULL)
	{
		return false;
	}

	return true;
}

void pilha_imprimir(Pilha *p)
{

	No *aux = p->topo;

	printf("Pilha: ");
	printf("[");
	while (aux != NULL)
	{
		printf("%i", aux->dado);
		aux = aux->prox;
		if (aux != NULL)
		{
			printf(",");
		}
	}
	printf("]\n");
}

int pilha_tamanho(Pilha *p)
{
	int count = 0;
	No *aux = p->topo;

	while (aux != NULL)
	{
		count++;
		aux = aux->prox;
	}

	return count;
}

Pilha *pilha_clone(Pilha *p)
{
	int i = 0;
	No *aux = p->topo;
	Pilha *clone = pilha_criar();
	TipoElemento *v = (TipoElemento *)calloc(p->qtdeElementos, sizeof(TipoElemento));

	while (aux != NULL)
	{
		v[i] = aux->dado;
		aux = aux->prox;
		i++;
	}

	aux = p->topo;

	while (aux != NULL)
	{
		i--;
		pilha_empilhar(clone, v[i]);
		aux = aux->prox;
	}

	return clone;
}

void pilha_inverter(Pilha *p)
{
	Pilha *pInvertida = pilha_criar();
	No *aux = p->topo;

	while (aux != NULL)
	{
		pilha_empilhar(pInvertida, aux->dado);
		aux = aux->prox;
	}
	*p = *pInvertida;
}

bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor)
{

	for (int i = 0; i < tamVetor; i++)
	{
		pilha_empilhar(p, vetor[i]);
	}

	return true;
}

bool pilha_toString(Pilha *f, char *str)
{
	No *aux = f->topo;

	strcat(str, "[");
	while (aux != NULL)
	{
		char origem[50];

		sprintf(origem, "%d", aux->dado);
		strcat(str, origem);

		if (aux->prox != NULL)
		{
			strcat(str, ",");
		}
		aux = aux->prox;
	}
	strcat(str, "]");
	return true;
}