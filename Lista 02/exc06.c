#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *exc06_in;
FILE *exc06_out;

struct aluno
{
    int ra;
    float notas[3];
};

struct media
{
    int raMedia;
    float media;
};

void maiorMedia(int n, struct media bestAluno[])
{
    float mediaMaior = 0;
    int guardaRa = 0;

    for (int i = 0; i < n; i++)
    {
        if (mediaMaior < bestAluno[i].media)
        {
            mediaMaior = bestAluno[i].media;
            guardaRa = bestAluno[i].raMedia;
        }
    }

    exc06_out = fopen("outputExc06.txt", "a");
    fprintf(exc06_out, "Maior media:  %.1f\n", mediaMaior);
    fprintf(exc06_out, "RA do Aluno com maior media: %i\n\n", guardaRa);
    fclose(exc06_out);
}

void menorMedia(int n, struct media piorAluno[])
{
    float mediaMenor = 99999999;
    int raPiorAluno;

    for (int i = 0; i < n; i++)
    {
        if (mediaMenor > piorAluno[i].media)
        {
            mediaMenor = piorAluno[i].media;
            raPiorAluno = piorAluno[i].raMedia;
        }
    }
    exc06_out = fopen("outputExc06.txt", "a");
    fprintf(exc06_out, "Menor media:  %.1f\n", mediaMenor);
    fprintf(exc06_out, "RA do Aluno com menor media: %i\n\n", raPiorAluno);
    fclose(exc06_out);
}

void mNotaPrimeiraProva(int n, struct aluno melhorPrimeiraProva[])
{
    float maiorNota = -9999999;
    int raMaiorNota;

    for (int i = 0; i < n; i++)
    {
        if (maiorNota < melhorPrimeiraProva[i].notas[0])
        {
            maiorNota = melhorPrimeiraProva[i].notas[0];
            raMaiorNota = melhorPrimeiraProva[i].ra;
        }
    }

    exc06_out = fopen("outputExc06.txt", "a");
    fprintf(exc06_out, "Maior nota na Primeira Prova:  %.1f\n", maiorNota);
    fprintf(exc06_out, "RA do Aluno com maior nota na primeira prova: %i\n\n", raMaiorNota);
    fclose(exc06_out);
}

void verificaAprovado(int n, struct media aprovado[])
{
    int countAprov = 1;
    int alunAprov[countAprov];
    int countReprov = 1;
    int alunReprov[countReprov];

    for (int i = 0; i < n; i++)
    {
        if (aprovado[i].media > 6.0)
        {
            countAprov++;
            alunAprov[i] = aprovado[i].raMedia;
        }
        else
        {
            countReprov++;
            alunReprov[i] = aprovado[i].raMedia;
        }
    }

    exc06_out = fopen("outputExc06.txt", "r");
    for (int i = 0; i < n; i++)
    {
        fprintf(exc06_out, "Aluno Aprovado:  %.1fi\n", alunAprov[i]);
        fprintf(exc06_out, "Aluno Reprovado: %i\n", alunReprov[i]);
    }
    fprintf(exc06_out, "\n");
    fclose(exc06_out);
}

void media(int n, struct aluno a[n])
{
    struct media mAlunos[n];

    for (int i = 0; i < n; i++)
    {
        mAlunos[i].media = (a[i].notas[0] + a[i].notas[1] + a[i].notas[2]) / 3;
        mAlunos[i].raMedia = a[i].ra;
    }
    verificaAprovado(n, mAlunos);
    maiorMedia(n, mAlunos);
    menorMedia(n, mAlunos);
}

int main()
{
    int n;

    printf("Informe o numero de alunos: ");
    scanf("%i", &n);

    struct aluno a[n];

    // Entrada - Recebe as informações
    exc06_in = fopen("inputExc06", "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(exc06_in, "%i %f %f %f", &a[i].ra, &a[i].notas[0], &a[i].notas[1], &a[i].notas[2]);
    }
    fclose(exc06_in);

    // Cria um vetor com as medias
    media(n, a);
    mNotaPrimeiraProva(n, a);

    // Saida - Coloca os arquivos no "outputExc06"
    exc06_out = fopen("outputExc06.txt", "a");
    for (int i = 0; i < n; i++)
    {
        fprintf(exc06_out, "Aluno %i: ", a[i].ra);
        fprintf(exc06_out, " %.1f", a[i].notas[0]);
        fprintf(exc06_out, " %.1f", a[i].notas[1]);
        fprintf(exc06_out, " %.1f\n", a[i].notas[2]);
    }
    fclose(exc06_out);

    return 0;
}