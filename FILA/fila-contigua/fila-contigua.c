#include "fila.h"

#define TAM_INICIAL 20
/**************************************
 * DADOS
 **************************************/
struct fila
{
	TipoElemento *vetor;
	int tamVetor;
	int inicio;
	int fim;
	int qtdeElementos;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
Fila *fila_criar()
{
	Fila *novaFila = (Fila *)malloc(sizeof(Fila));
	novaFila->fim = 0;
	novaFila->inicio = 0;
	novaFila->qtdeElementos = 0;
	novaFila->tamVetor = TAM_INICIAL;
	novaFila->vetor = (TipoElemento *)calloc(TAM_INICIAL, sizeof(TipoElemento));

	return novaFila;
}

void fila_destruir(Fila **enderecoFila)
{
	Fila *f = *enderecoFila;

	for (int i = 0; i < (f->qtdeElementos); i++)
	{
		f->vetor[i] = NULL;
		free(f->vetor[i]);
	}

	f = NULL;
	free(f);
}

bool fila_inserir(Fila *f, TipoElemento elemento)
{
	if (f->qtdeElementos == f->tamVetor)
	{
		return false;
	}

	f->vetor[f->fim] = elemento;
	f->qtdeElementos++;

	if (f->fim == (f->tamVetor - 1))
	{
		f->fim = 0;
	}
	else
	{
		f->fim += 1;
	}

	return true;
}

bool fila_remover(Fila *f, TipoElemento *saida) // estratégia do scanf
{
	if (!fila_vazia(f))
	{
		f->vetor[f->inicio] = NULL;
		if (f->inicio == (f->tamVetor - 1))
		{
			f->inicio = 0;
		}
		else
		{
			f->inicio++;
		}
		f->qtdeElementos--;

		return true;
	}
	else
	{
		printf("Impossivel Remover. Pilha vazia!!\n");
	}

	return false;
}

bool fila_primeiro(Fila *f, TipoElemento *saida) // estratégia do scanf
{
	*saida = f->vetor[f->inicio];
	return true;
}

bool fila_vazia(Fila *f)
{
	if (f->qtdeElementos == 0)
	{
		return true;
	}

	return false;
}

int fila_tamanho(Fila *f)
{
	return f->tamVetor;
}

void fila_imprimir(Fila *f)
{
	if (!fila_vazia(f))
	{
		printf("Fila: ");
		printf("[");
		int i = f->inicio;
		int qtd = f->qtdeElementos;
		for (int i = f->inicio; i < f->fim; i++)
		{
			printf(" %i", f->vetor[i]);
			if (i < (f->fim - 1))
			{
				printf(",");
			}
		}
		printf("]");
		printf("\n");
	}
	else
	{
		printf("Pilha vazia!! - Nenhum elemento para imprimir. \n");
	}
}

Fila *fila_clone(Fila *f)
{
	Fila *clone = fila_criar();

	int inicio = f->inicio;
	int fim = f->fim;
	for (int i = inicio; i < fim; i++)
	{
		fila_inserir(clone, f->vetor[i]);
	}

	return clone;
}

bool fila_toString(Fila *f, char *str)
{
	str[0] = '\0';
	strcat(str, "[");
	for (int i = f->inicio; i < f->fim; i++)
	{
		char aux[50];
		sprintf(aux, " %i", f->vetor[i]);
		strcat(str, aux);
		if (i < (f->fim - 1))
		{
			strcat(str, ",");
		}
	}
	strcat(str, "]");

	return true;
}

bool fila_inserirTodos(Fila *f, TipoElemento *vetor, int tamVetor)
{
	if (tamVetor >= (f->tamVetor - f->qtdeElementos))
	{
		return false;
	}

	for (int i = 0; i < tamVetor; i++)
	{
		fila_inserir(f, vetor[i]);
	}
	return true;
}
