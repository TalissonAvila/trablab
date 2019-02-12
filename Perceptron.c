#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int  novoy, cont, i;
  float x1[30], x2[30],y[30], w1, w2, x3, w3;
  float ProdutoInterno,acerto,porcentagem, alfa, erro;
  char linha[100];
  
  w1 = 0.5;
  w2 = 0.5;
  w3 = 0.5;
  x3 = 1.0;
  alfa = 0.01;
  FILE *arquivo;
  arquivo = fopen("A_I.txt","r");
      	if (arquivo == NULL) {
		     printf("Nao foi possivel abrir o arquivo.\n");
		       exit(0);
	      }
  
  while(fgets(linha, 100, arquivo) != NULL){
        fscanf(arquivo,"%f %f %f", &x1[i], &x2[i], &y[i]);
        i++;}
    while(cont <= 30){

    ProdutoInterno = x1[i] * w1 + x2[i] * w2 + x3 *w3;
    

    if (ProdutoInterno >= 0){
      novoy = 1;
    } else novoy = 0;

    erro = y[i] - novoy;
    if (erro == 0){
      cont++;
    } else cont = 0;
    w1 = w1 + (alfa * erro * x1[i]);
    w2 = w2 + (alfa * erro * x2[i]);
    w3 = w3 + (alfa * erro * x3);

    if (novoy == y[i]){
      acerto = acerto + 1;
      
    }
    
    }
fclose(arquivo);
    porcentagem = (acerto / 30) * 100;
    printf("Quantidade de acertos : %.0f\n", acerto);
    printf("Porcetagem de acertos : %.3f%%\n\n ", porcentagem);

    printf("\n novo w1 = %f\n",w1);
    printf(" novo w2 = %f\n",w2); 
    printf(" novo w3 = %f\n", w3);
return 0;
}
