#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define TAM 30
int main(void) {
  int  novoy,novoy2, cont,i,escolha;
  float x1[TAM], x2[TAM],y[TAM], w1, w2, x3, w3;
  float ww1,ww2,ww3,xt1[TAM],xt2[TAM],yt[TAM];
  float ProdutoInterno,ProdutoInterno2,acerto,porcentagem, alfa, erro;
  char linha[100],linha2[100];

/* aqui a gente randomizou o w1,w2,w3.*/

  srand(time(NULL));
  w1 = rand() % 2 - 1;
  w2 = rand() % 2 - 1;
  w3 = rand() % 2 - 1;
  x3 = 1.0;
  alfa = 0.01;
  acerto = 0;
  i = 0;

/*fizemos um switch, pro usuario poder escolher qual a base do arquivo vai querer compilar, o A ou o B, funciona como uma espécie de botao de seleção.*/
  
    printf("Escolha :\n");
    printf("          1 para Dataset A. \n");
    printf("          2 para Dataset B. \n");
    scanf("%d",&escolha);

/*aqui o programa identifica os ponteiros abaixo como sendo arquivos de dados*/

    FILE *arquivo;
    FILE *arquivoteste;

/*aqui abri o switch no primeiro caso, no qual ele vai usar os arquivos A, executar o programa com base nos dados deles.*/

  switch (escolha){
    case 1 :
      arquivo = fopen("A_l.txt","r");
        if (arquivo == NULL) {
		      printf("Nao foi possivel abrir o arquivo.\n");
	return 0;
	}

/*esse while eh pra abrir o arquivo e colocar cada dado dentro dos vetores correspondentes a ele*/

  while(fgets(linha, 100, arquivo) != NULL){
        fscanf(arquivo,"%f %f %f", &x1[i], &x2[i], &y[i]);
        i++;
  }
  fclose(arquivo);

/*depois dos vetores serem preenchidos, jogamos eles em um for que faz o calculo do produto interno com todos os valores e modifica o w1,w2,w3 para que a tava de acerto seja 100%*/

  do{
    cont = 0;
    for (i = 0;i < 30;i++){
      ProdutoInterno = x1[i] * w1 + x2[i] * w2 + x3 * w3;
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

/*aqui são impressos os valores do W1,w2,w3 exelente digamos assim, que seram usados no arquivo teste.*/

  porcentagem = (cont / 30) * 100;
  printf("Quantidade de acertos da aprendizagem: %d\n", cont);
  printf("Porcetagem de acertos da aprendizagem: %.3f%%\n\n ", porcentagem);

  printf("\n w1 da aprendizagem = %f\n",w1);
  printf(" w2 da aprendizagem = %f\n",w2); 
  printf(" w3 da aprendizagem = %f\n\n\n\n\n", w3);

  ww1 = w1;
  ww2 = w2;
  ww3 = w3;

/*arquivo teste A*/
/*a partir de agora o programa vai por em pratica o que ele aprendeu*/

  printf("-------------------------------------\n\n");

/*a partir de agora vai repetir o processo anterior após a leitura do arquivo, mas agora sem alterar os valores de w1,w2,w3, agora querendo achar a porcentagem exata que o programa consegue nos fornecer com base no aprendizado*/  

  arquivoteste = fopen("A_t.txt","r");
  if (arquivoteste == NULL) {
		     printf("Nao foi possivel abrir o arquivo.\n");
		       return 0;
	}
  cont=0;
  while(fgets(linha2, 100, arquivoteste) != NULL){
        fscanf(arquivoteste,"%f %f %f", &xt1[cont], &xt2[cont], &yt[cont]);
        cont++;
  }
  fclose(arquivoteste);

  for (cont = 0;cont < 30 ;cont++){
   

    ProdutoInterno2 = xt1[cont] * w1 + xt2[cont] * w2 + x3 * w3;

    if (ProdutoInterno2 >= 0){
      novoy2 = 1;
    } else {
      novoy2 = 0;
    }

    if (yt[cont] == novoy2){
      acerto++;
    }
   
  }

/*aqui imprimimos a porcentagem de acertos que o programa calculou, ai saberemos o quao otimo ele pode ser com base na porcentagem que o usario pretende atingir*/

    porcentagem = (acerto / 30) * 100;
    printf("Quantidade de acertos do teste : %.0f\n", acerto);
    printf("Porcetagem de acertos do teste: %.3f%%\n\n ", porcentagem);
    printf("\nw1 final do teste = %f\n",ww1);
    printf("w2 final do teste = %f\n",ww2);
    printf("w3 final do teste = %f\n\n\n\n",ww3);
  break;
  
/*aqui inicia-se o caso 2 do switch, a partir de agora é tudo exatamente igual ao anterior, com diferença apenas nos arquivos que ele vai ler, vai usar agora a base B, vai aprender e realizar os mesmos procedimentos*/

  case 2 :
  arquivo = fopen("B_l.txt","r");
      	if (arquivo == NULL) {
		     printf("Nao foi possivel abrir o arquivo.\n");
		       return 0;
	      }
  
  while(fgets(linha, 100, arquivo) != NULL){
        fscanf(arquivo,"%f %f %f", &x1[i], &x2[i], &y[i]);
        i++;
  }
  fclose(arquivo);

  do{
    cont = 0;
    for (i = 0;i < 30;i++){

      ProdutoInterno = x1[i] * w1 + x2[i] * w2 + x3 * w3;
      
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
  printf("Quantidade de acertos da aprendizagem: %d\n", cont);
  printf("Porcetagem de acertos da aprendizagem: %.3f%%\n\n ", porcentagem);

  printf("\n w1 da aprendizagem = %f\n",w1);
  printf(" w2 da aprendizagem = %f\n",w2); 
  printf(" w3 da aprendizagem = %f\n\n\n\n\n", w3);

  ww1 = w1;
  ww2 = w2;
  ww3 = w3;

/*arquivo de teste B*/

  printf("----------------------------------\n\n");

  
  arquivoteste = fopen("B_t.txt","r");
  if (arquivoteste == NULL) {
		     printf("Nao foi possivel abrir o arquivo.\n");
		       return 0;
	}
  cont=0;
  while(fgets(linha2, 100, arquivoteste) != NULL){
        fscanf(arquivoteste,"%f %f %f", &xt1[cont], &xt2[cont], &yt[cont]);
        cont++;
  }
  fclose(arquivoteste);

  for (cont = 0;cont < 30 ;cont++){
   

    ProdutoInterno2 = xt1[cont] * w1 + xt2[cont] * w2 + x3 * w3;

    if (ProdutoInterno2 >= 0){
      novoy2 = 1;
    } else {
      novoy2 = 0;
    }

    if (yt[cont] == novoy2){
      acerto++;
    }
   
  }
    porcentagem = (acerto / 30) * 100;
    printf("Quantidade de acertos do teste : %.0f\n", acerto);
    printf("Porcetagem de acertos do teste: %.3f%%\n\n ", porcentagem);
    printf("\nw1 final do teste = %f\n",ww1);
    printf("w2 final do teste = %f\n",ww2);
    printf("w3 final do teste = %f\n\n\n\n",ww3);
  break;
  }
  
return 0;
}
