// Matteo Galiazzo mattegaliz@gmail.com
#include <iostream>
#include <vector>
using namespace std;

// x = numero in v[0]
// y = numero in v[1]
// vector = vettore vuoto
// n = numero di elementi da inserire in v
void fibonacci(int x, int y, vector<int>& vector, int n);

void print_int_vector(const vector<int>& vector);

int main() {

  vector<int> vector;
  fibonacci(1, 2, vector, 10);
  print_int_vector(vector);
  return 0;
} 

void fibonacci(int x, int y, vector<int>& vector, int n) {
  vector.push_back(x);
  vector.push_back(y);
  for(int i = 2; i < n; i++) {
    vector.push_back(vector[i-1] + vector[i-2]);
  }
}

void print_int_vector(const vector<int>& vector) {
  for(int element : vector) {
    cout << element << " ";
  }
}
