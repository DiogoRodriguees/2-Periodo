#include "lista.h"
#define TAM 5

struct lista
{
	TipoElemento *vetor;
	int tam;
	int qtde;
};

Lista *lista_criar()
{
	Lista *novaLista = (Lista *)malloc(sizeof(Lista));
	TipoElemento *nv = (TipoElemento *)calloc(TAM, sizeof(TipoElemento));
	novaLista->tam = TAM;
	novaLista->qtde = 0;
	novaLista->vetor = nv;

	return novaLista;
}

void lista_destruir(Lista **endereco){

	Lista* l = *endereco;
	l->vetor = NULL;
	free(l->vetor);
	l = NULL;
	free(l);
}

bool lista_anexar(Lista *l, TipoElemento elemento)
{
	if (l->qtde == l->tam)
	{
		TipoElemento *nv = (TipoElemento *)calloc((l->tam * 2), sizeof(TipoElemento));
		for (int i = 0; i < l->tam; i++)
		{
			nv[i] = l->vetor[i];
		}
		l->vetor = nv;
		l->tam = l->tam * 2;
	}

	l->vetor[l->qtde] = elemento;


	l->qtde+= 1;
	return true;
}

bool lista_inserir(Lista *l, TipoElemento elemento, int posicao){
	TipoElemento ant = elemento;
	TipoElemento atual;

	for (int i = posicao; i < l->tam; i++)
	{
		atual = l->vetor[i];
		l->vetor[i] = ant;
		ant = atual;
	}
	
	return true;
}

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco){
	

	for (int i = 0; i < l->tam; i++)
	{
		if(i == posicao){
			*endereco = l->vetor[i];
		}
		if(i >= posicao){
			l->vetor[i] = l->vetor[i+1];
		}

	}
	l->qtde-=1;
	return true;
}

int lista_removerElemento(Lista *l, TipoElemento elemento){
	int aux = 0;
	int posicao;

	for (int i = 0; i < l->tam; i++)
	{
		if(l->vetor[i] == elemento){
			aux = 1;
			posicao = i;
		}
		if(aux != 0){
			l->vetor[i] = l->vetor[i+1];
		}

	}
	l->qtde-=1;
	return posicao;
}

bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento){
	for (int i = 0; i < l->tam; i++)
	{
		if(i == posicao){
			l->vetor[i] = novoElemento;
		}
	}
	return true;
}

int lista_posicao(Lista *l, TipoElemento elemento){
	int aux;

	for (int i = 0; i < l->tam; i++)
	{
		if(l->vetor[i] == elemento){
			aux = i;
		}
	}

	return aux;
}

bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco){
	for (int i = 0; i < l->tam; i++)
	{
		if(i == posicao){
			*endereco = l->vetor[i];
		}
	}
	return true;
}

int lista_tamanho(Lista *l){
	return l->qtde;
}

bool lista_vazia(Lista *l){
	if(l->qtde == 0){
		return true;
	}
	return false;
}

bool lista_toString(Lista *l, char *str){
	str[0] = '\0';
	strcat(str, "[");
	for (int i = 0; i < l->qtde; i++)
	{
		char c[50];
		sprintf(c, "%i", l->vetor[i]);
		strcat(str, c);
		if(i < (l->qtde -1)){
			strcat(str, ",");
		}
	}
	strcat(str, "]");
	return true;
}

void lista_imprimir(Lista *l){
	
	printf("Lista: [");
	for (int i = 0; i < l->qtde; i++)
	{
		printf("%i", l->vetor[i]);
		if(i < (l->qtde -1)){
			printf(",");
		}
	}
	printf("]\n");
}