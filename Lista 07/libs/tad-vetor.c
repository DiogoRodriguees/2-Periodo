// tad_vetor.c
#include "tad-vetor.h"
#define TAM 3
#include <stdio.h>

/********************************************
 * Especificação dos dados
 *******************************************/
struct vetor
{
    int *vet;
    int tam;
    int qtd;
};

/********************************************
 * Implementação das funções
*******************************************/
Vetor *vet_criar()
{

    Vetor *v = (Vetor *)malloc(sizeof(Vetor));
    v->vet = (int *)calloc(TAM, sizeof(int));
    v->tam = TAM;
    v->qtd = 0;

    return v;
}

bool vet_anexar(Vetor *v, int elemento)
{

    if (v->qtd >= v->tam)
    {
        int tamS2 = v->tam;
        v->tam = v->tam * 2;
        int *v1 = (int *)calloc(v->tam, sizeof(int));

        for (int i = 0; i < tamS2; i++)
        {
            v1[i] = v->vet[i];
        }

        v->vet = v1;
    }

    v->vet[v->qtd] = elemento;
    v->qtd++;

    return true;
}

bool vet_inserir(Vetor *v, int elemento, int posicao)
{
    if (v->qtd >= v->tam)
    {
        int tamS2 = v->tam;
        v->tam = v->tam * 2;
        int *v1 = (int *)calloc(v->tam, sizeof(int));

        for (int i = 0; i < tamS2; i++)
        {
            v1[i] = v->vet[i];
        }

        v->vet = v1;
    }
    int *v1 = (int *)calloc(v->tam, sizeof(int));

    int aux;

    for (int i = 0; i < v->tam; i++)
    {
        if (i < posicao)
        {
            v1[i] = v->vet[i];
        }
        if (i == posicao)
        {
            aux = v->vet[i];
            v1[i] = elemento;
        }
        if (i > posicao)
        {
            v1[i] = aux;
            aux = v->vet[i];
        }
    }

    v->vet = v1;
    v->vet[posicao] = elemento;
    v->qtd++;

    return true;
}

bool vet_substituir(Vetor *v, int posicao, int novoElemento)
{
    v->vet[posicao] = novoElemento;

    return true;
}

bool vet_removerPosicao(Vetor *v, int posicao, int *endereco)
{
    *endereco = v->vet[posicao];
    v->vet[posicao] = NULL;
    free(v->vet[posicao]);

    return true;
}

int vet_removerElemento(Vetor *v, int elemento)
{
    for (int i = 0; i < (v->tam); i++)
    {
        if (v->vet[i] == elemento)
        {
            v->qtd--;
            v->vet[i] = NULL;
            return &v->vet[i];
        }
    }

    return -1;
}

int vet_tamanho(Vetor *v)
{
    return v->qtd;
}

bool vet_elemento(Vetor *v, int posicao, int *saida)
{

    for (int i = 0; i < v->tam; i++)
    {
        if (v->vet[i] == v->vet[posicao])
        {
            *saida = &v->vet[posicao];
        }
    }
}

int vet_posicao(Vetor *v, int elemento);

void vet_imprimir(Vetor *v)
{

    printf("[");
    for (int i = 0; i < v->tam; i++)
    {
        printf("%i", v->vet[i]);
        if (i < (v->tam - 1))
        {
            printf(", ");
        }
    }
    printf("]");
    printf("\n");
}

void vet_desalocar(Vetor **endVetor);

bool vet_toString(Vetor* vetor, char* string) {

    if(vetor == NULL) {
        return false;
    } 
    printf("Eu ");

    strcat(string, "[");
    for (int i = 0; i < vetor->tam; i++)
    {
        char casting[50];

        sprintf(casting, "%d", vetor->vet[i]);
        printf("%s", casting);
        strcat(string, casting);

        if (i < ((vetor->tam) - 1))
        {
            strcat(string, ",");
        }
    }
    strcat(string, "]");

    return true;
}
