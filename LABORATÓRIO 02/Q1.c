/*
1) Implemente uma função iterativa (usando laço) para calcular o máximo divisor comum de dois
números inteiros positivos, MDC(x, y), usando o algoritmo de Euclides. Este algoritmo é baseado no
fato de que se o resto da divisão de x por y, representado por r, for igual a zero, y é o MDC. Se o
resto r for diferente de zero, o MDC de x e y é igual ao MDC de y e r. O processo se repete até que
o valor do resto da divisão seja zero.
*/

#include <stdio.h>

int MDC(int x,int y);

int main(void) {
    int x, y, mdc;
    printf("Digite o valor do primeiro inteiro positivo: ");
    scanf("%d", &x);
    printf("Digite o valor do segungo inteiro positivo: ");
    scanf("%d", &y);

    mdc = MDC(x,y);
    printf("O MDC de %d e %d é: %d.", x,y,mdc);
  
    return 0;
}

int MDC(int x,int y){
    int r, mdc;
    do{
        r = x % y;
        x = y;
        y = r;
    } while(r != 0);

    return x;
  }
