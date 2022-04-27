#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Desenvolva um algoritmo para somar todos os números de um determinado conjunto.
    O conjunto de números deve ser armazenado em um vetor.
    O algoritmo deve ser estruturado com o modelo Entrada-Processamento-Saída discutido nas aulas anteriores.
    Escolha uma forma de entrada diferente do scanf. Sugestão: utilize a entrada via arquivo.
    Desenvolva uma função para realizar a soma
*/

int somaNum(int a, int vetor[a])
{
    int soma = 0;

    for (int i = 0; i < a; i++)
    {
        soma = soma + vetor[i];
    }

    return soma;
}

int main()
{
    int a, b;
    int vetor[5];

    // Entrada
    FILE *exc02_in = fopen("inputExc02", "r");
    for (int i = 0; i < 5; i++)
    {
        fscanf(exc02_in, "%i", &vetor[i]);
    }
    fclose(exc02_in);

    // Processamento
    int soma = somaNum(5, vetor);

    // Saida
    FILE *exc02_out = fopen("outputExc02", "w");
    fprintf(exc02_out, "Resultado: %i", soma);
    fclose(exc02_out);

    return 0;
}