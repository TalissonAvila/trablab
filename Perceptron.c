#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  double alfa, erro;
  int y, novoy, cont;
  double x1, x2, x3, w1, w2, w3;
  double ProdutoInterno,acerto,porcentagem;
  char linha[100];

  x3 = 1.0;
  w1 = 0.5;
  w2 = 0.5;
  w3 = 0.5;
  alfa = 0.01;
  arquivo = fopen("./A_I.txt","r");
  FILE *arquivo;
  while(fgets(linha, sizeof(linha), arquivo) != NULL){
        fscanf(arquivo,"%lf %lf %d", &x1[i], &x2[i], &y[i]);
        i++;

    ProdutoInterno = x1 * w1 + x2 * w2 + x3 * w3;
    

    if (ProdutoInterno >= 0){
      novoy = 1;
    } else novoy = 0;

    erro = y - novoy;
    w1 = w1 + alfa * erro * x1;
    w2 = w2 + alfa * erro * x2;
    w3 = w3 + alfa * erro * x3;

    if (novoy == y){
      acerto = acerto + 1;
    }
  }
    porcentagem = (acerto / 30) * 100;
    printf("Quantidade de acertos : %.0lf\n", acerto);
    printf("Porcetagem de acertos : %.3lf%%\n\n ", porcentagem);

    printf("novo w1 = %lf\n",w1);
    printf("novo w2 = %lf\n",w2);
    printf("novo w3 = %lf\n",w3); 
return 0;
}
