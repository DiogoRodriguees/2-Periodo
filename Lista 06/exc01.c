#include <stdio.h>
#include <stdlib.h>

// Usa return
int *criaVetorAleatorio1(int tam)
{

    int *vetor = (int *)calloc(tam, sizeof(int));

    for (int i = 0; i < tam; i++)
    {
        vetor[i] = rand() % 100;
    }

    return vetor;
}

// Usa metodo scanf
void criaVetorAleatorio2(int tam, int *vetorOriginal)
{
    int *vetor2 = (int *)calloc(tam, sizeof(int));

    for (int i = 0; i < tam; i++)
    {
        vetor2[i] = rand() % 100;
    }

    *vetorOriginal = vetor2;
}

int main()
{
    // Primeira Função
    int *vetor;
    int tam;

    printf("\nInforme o tamanho do vetor: ");
    scanf("%i", &tam);

    vetor = criaVetorAleatorio1(tam);

    // Imprime o vetor da função com return para verificação
    for (int i = 0; i < tam; i++)
    {
        printf("[%i] ", vetor[i]);
    }

    // Segunda Função
    int *vetor2;
    int tam2;

    printf("\nInforme o tamanho do vetor2: ");
    scanf("%i", &tam2);

    criaVetorAleatorio2(tam2, &vetor2);

    // Imprime o vetor da função com metodo scanf para verificação
    for (int i = 0; i < tam; i++)
    {
        printf("[%i] ", vetor2[i]);
    }

    return 0;
}