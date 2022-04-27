#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *dobrar(int **vetor, int tam)
{
    int *vetorDobrado = (int *)malloc(tam * sizeof(int));

    // Laço que preencher o vetor dobrado
    for (int i = 0; i < tam; i++)
    {
        vetorDobrado[i] = i < (tam / 2) ? vetor[i] : 0;
    }

    return vetorDobrado;
}

void preencheVetor(int **vetor, int tam)
{
    int *vetor2 = (int *)malloc(tam * sizeof(int));

    // Laço que coloca números aleatorios no vetor
    for (int i = 0; i < tam; i++)
    {
        vetor2[i] = rand() % 100;
    }

    *vetor = vetor2;
}

void imprimeVetor(int tam, int **vetor)
{
    for (int i = 0; i < tam; i++)
    {
        printf("vetor[%i]: %i\n", i, vetor[i]);
    }

    printf("\n");
}

bool verificaVetores(int *vetor1, int *vetor2, int tam)
{
    bool verificador;

    for (int i = 0; i < tam; i++)
    {
        if (i < (tam / 2))
        {
            verificador = (vetor1[i] == vetor2[i]) ? true : false;
            if (!verificador) return false;
        }
        else
        {
            verificador = (vetor2[i] == 0) ? true : false;
            if (!verificador) return false;
        }
    }

    return verificador;
}

int main()
{
    int tam;
    int gTam;
    int *vetor;
    int *vetorDobrado;
    bool verificador;

    printf("Informe o tamanho do vetor: ");
    scanf("%i", &tam);

    preencheVetor(&vetor, tam);

    gTam = tam;
    tam = tam * 2;
    vetorDobrado = dobrar(vetor, tam);
    verificador = verificaVetores(vetor, vetorDobrado, tam);

    if (verificador)
    {
        printf("\nA operacao foi realizada com sucesso!\n");
    }
    else
    {
        printf("\nNao foi possível completar a operação!\n");
    }

    printf("\nVetor Original!\n");
    imprimeVetor(gTam, vetor);

    printf("\nVetor Dobrado!\n");
    imprimeVetor(tam, vetorDobrado);

    free(vetor); // Desaloca o vetor
    vetor = NULL;
    vetor = (int*) calloc(10, sizeof(int));


    return 0;
}