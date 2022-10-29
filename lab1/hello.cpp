// Matteo Galiazzo mattegaliz@gmail.com
#include <iostream>
#include <vector>
using namespace std;

int globale1 = 2;
int globale2;

void print(string out, vector<int> v);

int main() {
  int auto1 = 0;
  static int auto2 = 1;
  static int auto3;

  cout << "Ciao\n";

  vector<int> vect = {1, 2, 3, 4};
  string out = "BOH";

  print(out, vect);
  return 0;
}

void print(string out, vector<int> vect) {
  cout << "sei dentro la funzione\n";
  for (int element : vect) {
    cout << element;
  }
}
