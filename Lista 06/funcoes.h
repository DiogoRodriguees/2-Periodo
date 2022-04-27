#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto
{
   unsigned int codigo;
   char nome[50];
   float preco;
} Produto;
 
void criarValores(int **prod1, float preco1, int codigo1, char string1[])
{
   Produto *primeiroProd = (Produto *)calloc(1, sizeof(Produto));
   primeiroProd->codigo = codigo1;
   primeiroProd->preco = preco1;
   strcpy(primeiroProd->nome, string1);
 
   *prod1 = primeiroProd;
}
 
void imprimeProduto(Produto* vetorProd2)
{
   printf("\nCaracteristicas do Produto\n");
 
   printf("Nome..: %s\n", vetorProd2->nome);
   printf("Preco.: %.2f\n", vetorProd2->preco);
   printf("Codigo: %i\n", vetorProd2->codigo);
}