#include <stdio.h>

int main(){
    int v[3] = {1, 2, 3};
    int *p1 = v;
    int v2[3] = {4, 5, 6};
    int *p2 = v2;
    int *m[2] = {v, v2};
    int **pm = m;

    printf("1:%i\n", *p1);
    printf("2:%i\n", *(p1+1));
    printf("3:%i\n", *(p1+2));
    printf("4:%i\n", *p2);
    printf("5:%i\n", *(p2+1));
    printf("6:%i\n", *(p2+2));



    return 0;
}