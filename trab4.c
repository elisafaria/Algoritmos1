#include <stdio.h>
#include <stdlib.h>


// Aluna: Elisa Faria Almeida
// Matrícula: 2021006780


//FUNÇÃO PARA INICIALIZAR O ARRAY USANDO ALOCAÇÃO DINÂMICA
int* inicializa_vetor(int n){

 int *v = (int*) malloc (n * sizeof(int*));

 return v;
}

//FUNÇÃO QUE VERIFICA OS ELEMENTOS QUE SERÃO COLOCADOS NA BALANÇA
int coloca_balanca(int *m,  int *result, int M, int num_elementos, int indice_atual, int peso_atual){

 //casos base
 //a função retorna verdadeiro quando o peso atual igualar a M
 if (peso_atual == M)
    return 1;

 //a função retorna falso se o índice exceder o número de elementos
 if (indice_atual >= num_elementos)
    return 0;

 //a função retorna falso se o peso atual exceder M
 if (peso_atual > M)
    return 0;

 //chama a função para verificar as possibilidades, considerando o peso do índice atual
 int foi_adicionado = coloca_balanca (m, result, M, num_elementos, indice_atual + 1, peso_atual + m[indice_atual]);

 //se a função retornar verdadeiro, é atribuido o valor de 1 ao índice atual
 if (foi_adicionado == 1){
    result[indice_atual] = 1;
    return 1;
 }

 //chama a função para verificar as possibilidades, desconsiderando o elemento que excedeu o peso
 int sem_adicionar = coloca_balanca (m, result, M, num_elementos, indice_atual + 1, peso_atual);

 //se a função retornar falso, é atribuido o valor de 0 ao índice atual
 if (sem_adicionar == 1){
    result[indice_atual] = 0;
    return 1;
 }

  return 0;
}

//FUNÇÃO PARA IMPRIMIR VETOR
void imprime_vetor(int *v, int num_elementos){

  for (int i = 0; i < num_elementos; i++){
    printf ("%d ", v[i]);
  }

  printf ("\n");

}

//FUNÇÃO PARA LIBERAR A MEMÓRIA OCUPADA PELO VETOR
void libera_vetor(int *v){

 free(v);

}

int main(){

  int M;
  int num_elementos;
  int *m;
  int *result;

  //lê o peso total
  scanf("%d", &M);

  //lê a quantidade de elementos
  scanf("%d", &num_elementos);

  //inicializa os vetores
  m = inicializa_vetor (num_elementos);
  result = inicializa_vetor (num_elementos);

  //preenchendo o vetor com os valores digitados pelo usuário
  for (int i = 0; i < num_elementos; i++){
    scanf ("%d", &m[i]);
  }

  coloca_balanca (m, result, M, num_elementos, 0, 0);

  imprime_vetor(result, num_elementos);

  libera_vetor(m);
  libera_vetor(result);

  return 0;
}