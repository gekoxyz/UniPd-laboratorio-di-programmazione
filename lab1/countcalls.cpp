// Matteo Galiazzo mattegaliz@gmail.com
#include <iostream>
using namespace std;

void call_counter(void);

int calls = 0;

int main() {
  cout << calls;
  call_counter();

  cout << calls;

  return 0;
}

void call_counter(void) {
  calls++;
}
