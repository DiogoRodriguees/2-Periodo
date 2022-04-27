#include <stdio.h>
#include <stdlib.h>

// Devolvendo com metodo scanf
void tamanhoString1(char *string1, int *count)
{
    int countElem = 0;

    for (int i = 0; string1[i] != '\0'; i++)
    {
        countElem++;
    }

    *count = countElem;
}

// Devolvendo com return
int tamanhoString2(char *string2)
{
    int countElem2 = 0;

    for (int i = 0; string2[i] != '\0'; i++)
    {
        countElem2++;
    }

    return countElem2;
}

int main()
{
    // Primeira Função
    int count = 0;
    char string1[] = "Diogo Rodrigues";

    tamanhoString1(&string1, &count);

    printf("Numero de elementos Primeira String: %i\n", count); // Imprime o resultado 1

    // Segunda Funcão
    int count2 = 0;
    char string2[] = "Diogo dos Santos";

    count2 = tamanhoString2(&string1);

    printf("Numero de elementos Segunda String: %i\n", count2); // Imprime o resultado 2

    return 0;
}