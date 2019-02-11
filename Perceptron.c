#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  double w,erroalfa,erro;
  int y,novoy,cont;
  double x1,x2,w1,w2,x3,w3;
  char linha[100];
  x3 = 1.0
  w1 = 0.5;
  w2 = 0.5;
  w3 = 0.5
  double ProdutoInterno;
  erroalfa = 0.01;

  while(fgets(linha, sizeof(linha), arquivo) != NULL){
        fscanf(arquivo,"%lf %lf %d", &x1[i], &x2[i], &y[i]);
        i++;

    ProdutoInterno = x1 * w1 + x2 * w2 + x3 * w3;
    
    printf("Produto interno é %lf\n", ProdutoInterno);

    if (ProdutoInterno >= 0){
      novoy = 1;
    } else novoy = 0;
    printf(" Novo y igual a %d\n",novoy);

    erro = y - noyoy;
    w1 = w1 + erroalfa * erro * x1;
    w2 = w2 + erroalfa * erro * x2;
    w3 = w3 + erroalfa * erro * x3;
  }
 
return 0;
}