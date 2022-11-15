#include <iostream>
#include <string>
#include "node.hpp"

using namespace std;

int main() {
  node* disney = nullptr;

  node pippo = node("pippo");
  disney = &pippo;
  disney->print_all();

  node paperino = node("paperino");
  pippo.insert(&paperino);
  disney = &pippo;
  disney->print_all();

  node pluto = node("pluto");
  paperino.add(&pluto);
  disney->print_all();

  pluto.erase();

  disney->print_all();

  node ziopaperone = node("ziopaperone");
  paperino.add(&ziopaperone);
  node rockerduck = node("rockerduck");
  ziopaperone.add(&rockerduck);
  disney->print_all();

  cout << ziopaperone.advance(1) << endl;
  cout << ziopaperone.advance(2) << endl;
  cout << ziopaperone.advance(3) << endl;

  node* paperoga = disney->push_back("paperoga");
  disney->print_all();
  // cancello paperoga con delete dato che e' stato allocato con una new
  paperoga->erase();
  delete paperoga;
  paperoga = nullptr;
  disney->print_all();

  node* paperinik = disney->push_front("paperinik");
  disney->print_all();
  // cancello paperinik con una delete dato che e' stato allocato con una new
  paperinik->erase();
  delete paperinik;
  paperinik = nullptr;
  disney->print_all();

  disney->pop_front();
  disney->print_all();
  disney->pop_back();
  disney->print_all();

  return 0;
}