#include <iostream>
using namespace std;

void print_reference(const int& a, const double& b) {
  cout << a << " " << b << '\n';
}

void print_pointer(int* a, double* b) {
  cout << *a << " " << *b << '\n';
}

int main() {
  int a = 0;
  double b = 1;
  print_reference(a, b);
  print_pointer(&a, &b);
  return 0;
}
