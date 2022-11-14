#include <iostream>
#include <string>
#include "node.hpp"

using namespace std;

int main() {
  node pippo = node("pippo");
  pippo.print_all();
  node paperino = node("paperino");
  pippo.insert(&paperino);
  paperino.print_all();
  node pluto = node("pluto");
  paperino.add(&pluto);
  pippo.print_all();
  return 0;
}