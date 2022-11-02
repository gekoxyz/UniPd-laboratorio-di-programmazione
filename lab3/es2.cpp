#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

void print_array_length(const double* arr) {
  cout << "La dimensione dell'array e' di: " << sizeof(arr) / sizeof(double) << '\n';
}

int main() {
  double arr[ARRAY_SIZE];
  cout << sizeof(arr)/sizeof(double);
  
  print_array_length(arr);
  return 0;
}

