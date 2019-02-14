#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void) {
  int  novoy, cont,i,escolha;
  float x1[30], x2[30],y[30], w1, w2, x3, w3;
  float ProdutoInterno,acerto,porcentagem, alfa, erro;
  char linha[100];

  srand(time(NULL));
  w1 = rand() % 20 - 10;
  w2 = rand() % 20 - 10;
  w3 = rand() % 20 - 10;
  x3 = 1.0;
  alfa = 0.01;
  acerto = 0;
  i = 0;
    printf("Escolha :\n");
    printf("          1 para Dataset A. \n");
    printf("          2 para Dataset B. \n");
    scanf("%d",&escolha);
     FILE *arquivo;
  switch (escolha){
    case 1 :
   
  arquivo = fopen("A_l.txt","r");
      	if (arquivo == NULL) {
		     printf("Nao foi possivel abrir o arquivo.\n");
		       exit(0);
	      }
  
  while(fgets(linha, 100, arquivo) != NULL){
        fscanf(arquivo,"%f %f %f", &x1[i], &x2[i], &y[i]);
        i++;
  }
  fclose(arquivo);

  do{
    cont = 0;
    for (i = 0;i < 30;i++){

      ProdutoInterno = x1[i] * w1 + x2[i] * w2 + x3 *w3;
      
      if (ProdutoInterno >= 0){
        novoy = 1;
      } else {
        novoy = 0;
      }
      erro = y[i] - novoy;
      if (erro == 0){
        cont++;
      } 
      w1 = w1 + (alfa * erro * x1[i]);
      w2 = w2 + (alfa * erro * x2[i]);
      w3 = w3 + (alfa * erro * x3);
      
    }
  }
  while(cont < 30);

  porcentagem = (cont / 30) * 100;
  printf("\n\nQuantidade de acertos : %d\n", cont);
  printf("Porcetagem de acertos : %.3f%%\n\n ", porcentagem);

  printf("\n novo w1 = %f\n",w1);
  printf(" novo w2 = %f\n",w2); 
  printf(" novo w3 = %f\n", w3);
  break;
  case 2 :
  arquivo = fopen("B_l.txt","r");
      	if (arquivo == NULL) {
		     printf("Nao foi possivel abrir o arquivo.\n");
		       exit(0);
	      }
  
  while(fgets(linha, 100, arquivo) != NULL){
        fscanf(arquivo,"%f %f %f", &x1[i], &x2[i], &y[i]);
        i++;
  }
  fclose(arquivo);

  do{
    cont = 0;
    for (i = 0;i < 30;i++){

      ProdutoInterno = x1[i] * w1 + x2[i] * w2 + x3 *w3;
      
      if (ProdutoInterno >= 0){
        novoy = 1;
      } else {
        novoy = 0;
      }
      erro = y[i] - novoy;
      if (erro == 0){
        cont++;
      } 
      w1 = w1 + (alfa * erro * x1[i]);
      w2 = w2 + (alfa * erro * x2[i]);
      w3 = w3 + (alfa * erro * x3);
      
    }
  }
  while(cont < 30);

  porcentagem = (cont / 30) * 100;
  printf("\n\nQuantidade de acertos : %d\n", cont);
  printf("Porcetagem de acertos : %.3f%%\n\n ", porcentagem);

  printf("\n novo w1 = %f\n",w1);
  printf(" novo w2 = %f\n",w2); 
  printf(" novo w3 = %f\n", w3);
  break;
  }
  
return 0;
}
