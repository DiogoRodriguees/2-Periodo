#include <stdio.h>
#include <stdlib.h>

FILE *exc01_out;
FILE *exc01_in;

// Printa o vetor no arquivo(outputEx01)
void printVetor(int a, int *vetor[])
{
    exc01_out = fopen("outputExc01", "w");
    for (int i = 0; i < a; i++)
    {
        fprintf(exc01_out, "(%i) ", vetor[i]);
    }
    fclose(exc01_out);
}

// Busca o numero informado no vetor
int searchElement(int num, int a, int *vetor[])
{
    for (int i = 0; i < a; i++)
    {
        // Elemento encontrado
        if (num == vetor[i])
        {
            exc01_out = fopen("outputExc01", "a");
            fprintf(exc01_out, "\n\nO elemento foi encontrado!!\n");
            fclose(exc01_out);
            return i;
        }
        // Elemento não encontrado
        else
        {
            if (i == (a - 1))
            {
                exc01_out = fopen("outputExc01", "a");
                fprintf(exc01_out, "\no numero nao foi encontrado");
                fclose(exc01_out);
            }
        }
    }
}

int main()
{
    int vetor[10];
    int elemento;

    // Entrada
    exc01_in = fopen("inputExc01", "r");
    for (int i = 0; i < 10; i++)
    {
        fscanf(exc01_in, "%i", &vetor[i]);
    }
    fclose(exc01_in);

    // Processamento
    printVetor(10, vetor);
    elemento = searchElement(70, 10, vetor);

    exc01_out = fopen("outputExc01", "a");
    fprintf(exc01_out, "\nPosição do Elemento: %i", elemento);
    fclose(exc01_out);

    return 0;
}