#include <stdio.h>

int main(){
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;

    int *v[4] = {&a, &b, &c, &d};
    int **p = v;


    printf("v: %u\n", v);
    printf("p: %u\n", p);
    printf("v[0]: %i\n", *(*(p)));
    printf("v[1]: %i\n", *(*(p+1)));
    printf("v[2]: %i\n", *(*(p+2)));
    printf("v[3]: %i\n", *(*(p+3)));


    return 0;
}