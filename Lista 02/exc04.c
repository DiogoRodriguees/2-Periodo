#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Desenvolva um algoritmo para extrair um trecho de uma string a partir de um intervalo (posição inicial e final).
    Implemente uma função para realizar a extração.

    Exemplo:
    String: “foto_aniversario.jpg”. Extrair os três últimos caracteres (caractere 17 até o 19): “jpg”.
    String: “UTFPR Campo Mourão”. Extrair os caracteres do intervalo 6 ao 10: “Campo”.
*/

int s = 18; // tamanho das strings

void extraiString(int a, int b, char str[])
{
    int n = 0; // Variavel usada no for
    int size = b - a;
    char str2[size];

    // Passa a string nas posições indicadas
    for (int i = 0; i < s; i++)
    {
        if (i <= b && i >= a)
        {
            str2[n] = str[i];
            n++;
        }
    }

    // Saida
    FILE *exc04_out = fopen("outputexc04", "w");
    fprintf(exc04_out, "Resultado: %s", str2);
    fclose(exc04_out);
}

int main()
{
    char str[s];

    // Entrada
    FILE *exc04_in = fopen("inputExc04", "r");
    for (int i = 0; i < s; i++)
    {
        fscanf(exc04_in, "%c", &str[i]);
    }
    fclose(exc04_in);
    printf("\n%s", str);

    // Processamento
    extraiString(6, 10, str);

    return 0;
}