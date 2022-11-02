#include <iostream>
using namespace std;

void f(){
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int* element_pointer = &arr[1]; 
  
  for(int el: arr)
    cout << el << " ";
  cout << '\n';
  
  // cambio gli elementi dell'array usando il puntatore
  element_pointer[-1] = 99;
  // uso sizeof(arr) / sizeof(int) per ottenere la dimensione dell'array, dato che
  // sizeof mi resituisce la dimensione di un tipo in bytes
  // sizeof(arr) = 4 bytes * 10 elementi = 40 bytes
  // dividendo per sizeof(int) ottengo la dimensione effettiva dell'array (40/4 = 10)
  for(int i = 0; i < (sizeof(arr)/sizeof(int)) - 1 ; i++)
    element_pointer[i] = 100 + i;

  for(int el: arr)
    cout << el << " ";
  cout << '\n';
  
}

void f_illegal() {
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int* element_pointer = &arr[9]; 
  
  // creo un segmentation fault scrivendo fuori dai limiti dell'array
  element_pointer[10] = 1;
}

int main() {
  f();
  f_illegal();
  return 0;
}
