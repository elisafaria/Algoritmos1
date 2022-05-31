#include <stdio.h>

//Você deverá modificar apenas a função abaixo, você
//não pode modificar a assinatura dela
int concatena(char* s1, char* s2, char* sres, int* espacos){
  int tam = 1, esp = 0;
  int i, j;

  //Laços FOR para contar os caracteres e os espaços de cada string
  for (int i = 1; s1 [i] != '\0'; i++){

       if (s1[i] == ' '){
            esp++;
        }
        tam++;
  }

   for (i = 1; s2 [i] != '\0'; i++){

        if (s2[i] == ' '){
            esp++;
        }
        tam++;
    }

 //Adicionado 1 levando em conta o espaço entre as duas strings
  *espacos = esp + 1;

 //Concatenando as strings
 //Imprimindo a string 1 na string resultado
   for (i = 0; s1[i] != '\n'; i++){
    sres[i] = s1[i];
  }

//Adicionando espaço entre as strings
	sres[i] = ' ';

 //Imprimindo a string 2 na string resultado
  for (j = 0; s2[j] != '\n'; j++, i++){
    sres[i+1] = s2[j];
  }

//Indicando o fim da string resultado
	sres[i+1]='\0';

//A função retornará o tamanho da string resultante
   return tam;
}

//Funcao para imprimir uma string, NÃO MODIFIQUE
void print_string(char* str){
  int k = 0;
  while(str[k] != '\0'){
    printf("%c", str[k]);
    k++;
  }
  printf("\n");
}

//NÂO MODIFIQUE a main
int main(int argc, char * argv[]){
  char frase1[40];
  char frase2[40];
  char fraseResultado[80];
  int tamResultado;
  int espacos;

  //lendo a entrada
  fgets(frase1, 40, stdin);
  fgets(frase2, 40, stdin);

  tamResultado = concatena(frase1, frase2, fraseResultado, &espacos);

  print_string(fraseResultado);
  printf("String com %d caracteres e %d espacos.\n", tamResultado, espacos);

  return 0;
}