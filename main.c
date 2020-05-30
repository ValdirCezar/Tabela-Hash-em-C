#include <stdio.h>
#include <stdlib.h>

struct set
{
  int key;
  int data;
};
struct set *array;
int capacity = 10;
int size = 0;

int hashFunction(int key)
{
  return (key % capacity);
}
int checkPrime(int n)
{
  int i;
  if (n == 1 || n == 0)
  {
    return 0;
  }
  for (i = 2; i < n / 2; i++)
  {
    if (n % i == 0)
    {
      return 0;
    }
  }
  return 1;
}
int getPrime(int n)
{
  if (n % 2 == 0)
  {
    n++;
  }
  while (!checkPrime(n))
  {
    n += 2;
  }
  return n;
}
void init_array()
{
  capacity = getPrime(capacity);
  array = (struct set *)malloc(capacity * sizeof(struct set));
  for (int i = 0; i < capacity; i++)
  {
    array[i].key = 0;
    array[i].data = 0;
  }
}

void insert(int key, int data)
{
  int index = hashFunction(key);
  if (array[index].data == 0)
  {
    array[index].key = key;
    array[index].data = data;
    size++;
    printf("\n Chave (%d) inserida com sucesso! \n", key);
  }
  else if (array[index].key == key)
  {
    array[index].data = data;
  }
  else
  {
    printf("\n Erro por colisao  \n");
  }
}

void remove_element(int key)
{
  int index = hashFunction(key);
  if (array[index].data == 0)
  {
    printf("\n Chave não encontrada \n");
  }
  else
  {
    array[index].key = 0;
    array[index].data = 0;
    size--;
    printf("\n Chave (%d) Removida! \n", key);
  }
}
void display()
{
  int i;
  for (i = 0; i < capacity; i++)
  {
    if (array[i].data == 0)
    {
      printf("\n Array[%d]: / ", i);
    }
    else
    {
      printf("\n Chave: %d Array[%d]: %d \t", array[i].key, i, array[i].data);
    }
  }
}

int size_of_hashtable()
{
  return size;
}

int main()
{
  int choice, key, data, n;
  int c = 0;
  init_array();

  do
  {
    printf("1.Inserir Intem na Hash Table"
         "\n2.Remover item da Hash Table"
         "\n3.Chekar tamanho da Hash Table"
         "\n4.Mostrar uma Hash Table"
         "\n\n Escolha uma opção: ");

    scanf("%d", &choice);
    switch (choice)
    {
    case 1:

      printf("Informe a chave -:\t");
      scanf("%d", &key);
      printf("Informe os dados -:\t");
      scanf("%d", &data);
      insert(key, data);

      break;

    case 2:

      printf("Informe a chave a ser deletada -:");
      scanf("%d", &key);
      remove_element(key);

      break;

    case 3:

      n = size_of_hashtable();
      printf("O tamanho da tabela é -:%d\n", n);

      break;

    case 4:

      display();

      break;

    default:

      printf("Valor invalido\n");
    }

    printf("\nDeseja continuar? [1] SIM [2] NAO: ");
    scanf("%d", &c);

  } while (c == 1);
}