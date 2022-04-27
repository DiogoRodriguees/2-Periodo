#include <stdio.h>

/*
Nome: Diogo Rodrigues dos Santos.
Exercicio 2 da lista 01 - Ponteiros vs Vetor.
*/
int main(){
    int v[4] = {1, 2, 3, 4};
    int *p = v;
    int *w = p + 2;
    int i=30;
    int *x = &i;




    printf("*p: %u\n", p);
    printf("   *p : %u\n", *p);
    printf("*(p+1): %u\n", *(p+1));
    printf("*(p+2): %u\n", *(p+2));
    printf("*(p+3): %u\n", *(p+3));
    printf(" v: %u\n", v);
    printf("*w: %u\n", w);
    
    return 0;
}