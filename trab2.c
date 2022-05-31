#include <stdio.h>
#include <stdlib.h>

//função para iniciar um vetor com alocação dinâmica, considerando n valores.
int *iniciaVetor (int n){

	int *vetor = (int*) malloc (n * sizeof(int));
	return vetor;
}

//função para liberar a memória separada pelo malloc
void liberaConjunto (int *v) {

 free (v);

}

//função que calcula a intersecção entre os conjuntos
int* interseccao (int* v1, int t1, int* v2, int t2, int *t){

 //inicializando vetor com alocação dinâmica para o conjunto intersecção.
 int* vint = iniciaVetor (t1 + t2);

 int i, j, k = 0, rep = 0;
 *t=0;

  //laços aninhados para comparar os elemento dos conjuntos. Se forem iguais, o valor passará para o vetor intersecção.
	for (i = 0; i < t1; i++){
		for (j = 0; j < t2; j++){
			if (v1[i] == v2[j]){
              vint[k] = v2[j];
              k++;
              rep++;
           }
         }
	   }

  //atribuindo o valor de rep ao ponteiro t, indicando o tamanho do vetor resultante da intersecção entre os conjuntos.
  *t = rep;

  //inicializando um segundo vetor intersecção para alocar o tamanho correto
  int* vintF = iniciaVetor (rep);

  //imprimindo o vetor vint no vetor vintF
  for (i = 0; i < *t; i++){
    vintF[i] = vint[i];
    }

  //liberando o espaço separado para o vetor vint
  liberaConjunto(vint);

	return vintF;
}

//função que calcula a união dos dois conjuntos.
int* uniao (int* v1, int t1, int* v2, int t2, int* tf){

  //inicializando vetor com alocação dinâmica para o conjunto união.
	int* un = iniciaVetor (t1 + t2);
	int i, j, cont = 0;

	//imprimindo os dois conjuntos no vetor união.
	for (i = 0; i < t1; i++){
		un[i] = v1[i];
	 }
  for (i = 0; i < t2; i++){
       un[i + t1] = v2[i];
   }

  //Laços aninhados para comparar os elementos do vetor. Se forem iguais, o elemento será subtituido por -1.
	for (i = 0; i < t1 + t2; i++){
    for (j = i + 1; j < t1 + t2; j++){
       if(un[j] == un[i]){
          un[j] = -1;
        }
		  }
	 }

	//deixando apenas os valores diferentes de -1 no vetor união
    for(i = 0; i < t1 + t2; i++){
		if (un[i]!= -1){
			un[cont] = un[i];
			cont++;
		}
	}

  //atribuindo o valor de cont ao ponteiro tf, indicando o tamanho do vetor resultante da união entre os conjuntos.
	*tf = cont;

	return un;
}

//função para imprimir o conjunto de forma ordenada
void imprimeConjunto (int *vet, int tvet) {

int i, j, aux;

//lacos aninhados para ordenar os elementos do conjunto
for (i = 0; i < tvet; i++){
    for (j = i + 1; j < tvet; j++){
        if(vet[i] > vet[j]){
          aux = vet[i];
           vet[i] = vet[j];
           vet[j] = aux;
        }
      }
    }

//imprimindo o conjunto
for (i = 0; i < tvet; i++) {

    printf ("%d ", vet[i]);

 }

 printf ("\n");

}

//NAO ALTERE A MAIN
int main(int argc, char * argv[]){
  int* A; // conjunto A
  int* B; // conjunto B
  int* C; // união
  int* D; // intercecção
  int nA, nB, nC, nD, aux; // número de elementos de cada conjunto

  //inicializando e lendo o conjunto A
  scanf("%d", &nA);
  A = iniciaVetor(nA);
  for(int i = 0; i < nA; i++){
    scanf("%d", &aux);
    A[i] = aux;
  }

  //inicializando e lendo o conjunto B
  scanf("%d", &nB);
  B = iniciaVetor(nB);
  for(int i = 0; i < nB; i++){
    scanf("%d", &aux);
    B[i] = aux;
  }

  //calcula e imprime a uniao e a interseccao
  C = uniao(A, nA, B, nB, &nC);
  imprimeConjunto(C, nC);

  D = interseccao(A, nA, B, nB, &nD);
  imprimeConjunto(D, nD);

  //libera a memoria dos 4 vetores
  liberaConjunto(A);
  liberaConjunto(B);
  liberaConjunto(C);
  liberaConjunto(D);

  return 0;
}