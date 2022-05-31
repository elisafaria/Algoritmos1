#include <stdio.h>
#include <stdlib.h>

//SUGESTAO DE ESTRUTURA PARA GUARDAR UM MACACO
typedef struct Macaco{
  int altura;
  struct bloco* lista_blocos;
} Macaco;

typedef struct Macaco * p_Macaco;

//SUGESTAO DE ESTRUTURA PARA GUARDAR UM BLOCO
typedef struct bloco{
  int id;
  int altura;
  struct bloco* prox;

} bloco;

typedef struct bloco * p_Bloco;

//FUNÇÃO PARA INICIALIZAR UM MACACO
p_Macaco inicializa_macacos (int num_macacos) {

 //Criando um vetor do tipo struct Macaco
 Macaco *M = (p_Macaco) malloc (num_macacos * sizeof (Macaco));

 //Inicializando os valores de cada macaco
 for (int i = 0; i < num_macacos; i++){
   M[i].lista_blocos = NULL;
   M[i].altura = 0;
 }

  return M;
}

//FUNÇÃO PARA ADICIONAR UM NOVO BLOCO NA LISTA
p_Bloco adicionar_bloco(int altura_bloco, int id_bloco, p_Bloco lista){

  p_Bloco novoBloco = (p_Bloco) malloc(sizeof(bloco));
  novoBloco->altura = altura_bloco;
  novoBloco->id = id_bloco;
  novoBloco->prox = lista;

  return novoBloco;
}

//FUNÇÃO PARA DIRECIONAR O BLOCO AO MACACO DE MENOR ALTURA
p_Macaco bota_no_menor (p_Macaco M, int num_macacos, int id_bloco, int altura_bloco) {
 int i;
 int menor = M[0].altura;
 int posicaoMenor = 0;

 //Encontrando a menor altura entre os macacos
 for (i = 0; i < num_macacos; i++){
   if (M[i].altura < menor){
     menor = M[i].altura;
     posicaoMenor = i;
   }
 }

 //Somando a altura do bloco coma altura total do macaco
 M[posicaoMenor].altura = M[posicaoMenor].altura + altura_bloco;

 //Adicionando um bloco no macaco de menor altura
 M[posicaoMenor].lista_blocos = adicionar_bloco(altura_bloco, id_bloco, M[posicaoMenor].lista_blocos);

 return M;
}

//SUGESTAO DE FUNCOES PARA IMPRESSAO
void imprime_blocos(p_Bloco lista){
  if(lista == NULL) return;
  imprime_blocos(lista->prox);
  printf(" %d %d", lista->id, lista->altura);
}

void imprime_macacos(p_Macaco M, int num_macacos){
  for(int i = 0; i < num_macacos; i++){
    printf("M[%d] altura = %d:", i, M[i].altura);
    imprime_blocos(M[i].lista_blocos);
    printf("\n");
  }
}

//FUNÇÃO PARA LIBERAR O ESPAÇO DA MEMÓRIA OCUPADO PELAS LISTAS
void libera_macacos (p_Macaco M, int num_macacos){

//Criação de um ponteiro que armazena o primeiro bloco da lista
p_Bloco aux;

 for (int i = 0; i < num_macacos; i++){
   while (M[i].lista_blocos != NULL){
     aux = M[i].lista_blocos;
     M[i].lista_blocos = M[i].lista_blocos->prox;
     free (aux);
   }
  }
}

//******************************
//VOCE NAO PODE MODIFICAR A MAIN
//******************************
int main(int argc, char * argv[]){

  p_Macaco M;
  int num_macacos;
  int id_bloco;
  int altura_bloco;

  //le o numero de macacos
  scanf("%d", &num_macacos);

  M = inicializa_macacos(num_macacos);

  //le o primeiro bloco
  scanf("%d %d", &id_bloco, &altura_bloco);
  while(id_bloco != -1){
    bota_no_menor(M, num_macacos, id_bloco, altura_bloco);
    //le o proximo bloco
    scanf("%d %d", &id_bloco, &altura_bloco);
  }

  imprime_macacos(M, num_macacos);

  //Lembre que cada macaco tem uma lista que precisa ser liberada
  libera_macacos(M, num_macacos);
  return 0;
}