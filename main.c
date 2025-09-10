#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// **************************************************************************
int *numbers_create(int size); // aloca os espaços para um tamanho fixo
void numbers_read(int *numbers,
                  int size); // ler todos os valores para os espaços
float numbers_average(int *numbers,
                      int size);           // calcula a média e retorna o valor
void numbers_show(int *numbers, int size); // exibe os valores alocados
void numbers_destroy(int *numbers);        // desaloca a variável alocada
int maior_numero(int * numbers, int size); // encontra o maior número do conjunto de dados 
int menor_numero(int * numbers, int size); // encontra o menor número do conjunto de dados
// **************************************************************************

// **************************** Implementação ******************************

int *numbers_create(int size) {
  int *num = NULL;
  num = (int *)malloc(size * sizeof(int));
  if (num == NULL)
    return NULL;
  return num;
}

void numbers_read(int *numbers, int size) {
  if (numbers != NULL) {
    for (int i = 0; i < size; i++)
      numbers[i] = rand() % 50;
  }
}

float numbers_average(int *numbers, int size) {
  float sum = 0.0;
  if (numbers != NULL)
    for (int i = 0; i < size; i++)
      sum += numbers[i];
  if (sum != 0)
    return sum / (float)size;
  return 0;
}

void numbers_show(int *numbers, int size) {
  printf("[");
  if (numbers != NULL) {
    for (int i = 0; i < size; i++)
      if (i == (size - 1))
        printf("%d", numbers[i]);
      else
        printf("%d, ", numbers[i]);
  }
  printf("]\n");
}

void numbers_destroy(int *numbers) { free(numbers); }

int maior_numero(int * numbers, int size) { // Função Adicional
  int maior = numbers[0];
  if (numbers != NULL) {
    for (int i = 0; i < size; i++){ //Primeiro, lê-se todos os números
      if (numbers[i] > maior){ //Caso o número lido seja o maior, será armazenado na variável "maior"
        maior = numbers[i];
      } 
    }
  }
  return maior;
}

int menor_numero(int * numbers, int size) { // Função Adicional
  int menor = numbers[0];
  if (numbers != NULL) {
    for (int i = 0; i < size; i++){ //Primeiro, lê-se todos os números
      if (numbers[i] < menor){ //Caso o número lido seja o menor, será armazenado na variável "menor"
        menor = numbers[i];
      } 
    }
  }
  return menor;
}

// *************************************************************************

int main() {
  srand(time(NULL)); // Inicializa o geraor aleatório
  int *numbers; // Ponteiro
  int size=rand() % 100; // Ordem aleatória
  
  numbers = numbers_create(size); // Aloca os espaços

  numbers_read(numbers, size);  // Lê os números
  numbers_show (numbers, size); // Mostra os números
  float avg = numbers_average(numbers, size); // Calcula a média dos números
  printf("Media = %.2f\n", avg); // Mostrando a média
  
  int maior = maior_numero(numbers, size); // Analisa o maior número
  printf("Maior número: %d\n", maior); //Mostrando o maior número
  int menor = menor_numero(numbers, size); // Analisa o menor número
  printf("Menor número: %d\n", menor); //Mostrando o menor número

  numbers_destroy(numbers);
  
  return 0;
}