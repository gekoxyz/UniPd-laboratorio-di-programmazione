// Matteo Galiazzo mattegaliz@gmail.com
#include <iostream>
using namespace std;

int main() {
    int x = 1;
    int y = 2;

  // metodo ignorante
  while(true) {
    int z = x + y;
    x = y;
    y = z;
    cout << z << " ";
  }
  return 0;
}
