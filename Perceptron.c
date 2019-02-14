#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define TAM 30
int main(void) {
  int  novoy, cont,i,escolha;
  float x1[TAM], x2[TAM],y[TAM], w1, w2, x3, w3;
  float ProdutoInterno,acerto,porcentagem, alfa, erro;
  char linha[100];


  srand(time(NULL));
  w1 = rand() % 2 - 1;
  w2 = rand() % 2 - 1;
  w3 = rand() % 2 - 1;
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
    for (i = 0;i < TAM;i++){

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
  while(cont < TAM);

  porcentagem = (cont / TAM) * 100;
  printf("\n\nAcertos da aprendizagem : %d\n", cont);
  printf("Porcetagem de acertos da aprendizagem : %.3f%%\n\n ", porcentagem);

  printf("\n W1 da aprendizagem = %f\n",w1);
  printf(" W2 da aprendizagem = %f\n",w2); 
  printf(" W3 da aprendizagem = %f\n", w3);
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
    for (i = 0;i < TAM;i++){

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
  while(cont < TAM);

  porcentagem = (cont / TAM) * 100;
  printf("\n\nAcertos da aprendizagem : %d\n", cont);
  printf("Porcetagem de acertos da aprendizagem : %.3f%%\n\n ", porcentagem);

  printf("\n W1 da aprendizagem = %f\n",w1);
  printf(" W2 da aprendizagem = %f\n",w2); 
  printf(" W3 da aprendizagem = %f\n", w3);
  break;
  }
  
return 0;
}
