#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Desenvolva um algoritmo para contar a quantidade de vogais existentes em uma string.
    Implemente uma função para para realizar a contagem.
*/

// Função que conta vogais
int countVogais(char str[])
{
    int count = 0;

    for (int i = 0; i < strlen(str); i++)
    {

        // Verifica as vogais minúsculas
        switch (str[i])
        {
        case 'a':
            count++;
            break;

        case 'e':
            count++;
            break;

        case 'i':
            count++;
            break;

        case 'o':
            count++;
            break;

        case 'u':
            count++;
            break;

        default:
            break;
        }

        // Verifica as vogais maiúsculas
        switch (str[i])
        {
        case 'A':
            count++;
            break;

        case 'E':
            count++;
            break;

        case 'I':
            count++;
            break;

        case 'O':
            count++;
            break;

        case 'U':
            count++;
            break;

        default:
            break;
        }
    }

    return count;
}

int main()
{
    char str[] = " ";

    // Entrada
    FILE *exc03_in = fopen("inputExc03", "r"); // Abri o arquivo para a leitor
    fscanf(exc03_in, "%s", str);               // Armazena o conteudo na string
    fclose(exc03_in);                          // Fecha o arquivo

    // Processamento
    int vogaisTotais = countVogais(str); // Chama a função para a execução

    // Saida
    FILE *exc03_out = fopen("outputExc03", "w");       // Abri o arquivo para escrever a string recebida
    fprintf(exc03_out, "Resultado: %i", vogaisTotais); // Mostra o que vai ser colocado no arquivo
    fclose(exc03_out);                                 // Fecha o arquivo

    return 0;
}