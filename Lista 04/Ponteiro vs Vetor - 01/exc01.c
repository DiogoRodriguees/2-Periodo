#include <stdio.h>

/*
Nome: Diogo Rodrigues dos Santos.
Exercicio 1 da lista 01 - Ponteiros vs Vetor.
*/
int main(){
    int v[4] = {1, 2, 3, 4};
    int *p = v;
    int *w = &v[2];
    int i=30;
    int *x = &i;

    printf("*p: %u\n", p);
    printf(" v: %u\n", v);
    printf("*w: %u\n", w);
    int v2[4] = {1, 2, 3, 4};
    
    printf("v[3]: %u\n", v2[3]);
    printf("v+3: %u\n", *(v2+3));

    
    return 0;
}