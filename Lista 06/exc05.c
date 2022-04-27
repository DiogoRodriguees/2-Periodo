#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "funcoes.h"
 
int main()
{
   Produto *vetorProd;
 
   criarValores(&vetorProd, 2.5, 2380242, "Nome do Produto");
 
   imprimeProduto(vetorProd);
 
   return 0;
}