#include <stdio.h>
#include <stdlib.h>

// Clona com metodo scanf
void clonarVetor1(int *vetor, int tam, int *copyVetor)
{
    int *vCopy;
    vCopy = (int *)calloc(tam, sizeof(int));

    // Preenche o vetor
    for (int i = 0; i < tam; i++)
    {
        vetor[i] = rand() % 100;
    }

    // Copia o vetor
    for (int i = 0; i < tam; i++)
    {
        vCopy[i] = vetor[i];
    }

    *copyVetor = vCopy;
}

int *clonarVetor2(int tam, int *vetor2, int *vCopy2)
{
    int *vResult = (int *)calloc(tam, sizeof(int));

    // Preenche o vetor
    for (int i = 0; i < tam; i++)
    {
        vetor2[i] = rand() % 100;
    }

    // Copia o vetor
    for (int i = 0; i < tam; i++)
    {
        vResult[i] = vetor2[i];
    }

    return vResult;
}


void imprimeVetor(int tam, int *vetor)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Vetor[%i]: %i\n", i, vetor[i]);
    }
    printf("\n");
}

int main()
{
    // Primeira Função (usando metodo scanf)
    int tam;
    int *v;
    int *copyV;

    printf("Qual o Tamanho do Primeiro Vetor: ");
    scanf("%i", &tam);

    v = (int *)calloc(tam, sizeof(int));
    copyV = (int *)calloc(tam, sizeof(int));

    clonarVetor1(v, tam, &copyV);

    // Segunda Função (usando return)
    int tam2;
    int *v2;
    int *copyV2;

    printf("\nQual o Tamanho do Segundo Vetor: ");
    scanf("%i", &tam2);

    v2 = (int *)calloc(tam2, sizeof(int));
    copyV2 = clonarVetor2(tam2, v2, copyV2);

    // Imprimindo os vetores
    printf("\nPrimeiro Vetor!!\n");
    imprimeVetor(tam, v);

    printf("\nCopia do Primeiro Vetor!!\n");
    imprimeVetor(tam, copyV);

    printf("\nSegundo Vetor!!\n");
    imprimeVetor(tam2, v2);

    printf("\nCopia do Segundo Vetor!!\n");
    imprimeVetor(tam2, copyV2);

    return 0;
}