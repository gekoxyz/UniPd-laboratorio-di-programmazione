#include "node.h"

// inserimento prima di this
node* node::insert(node* new_node) {
  // node non valido
  if (new_node == nullptr) return this;
  // il prossimo elemento del nuovo nodo e' this dato che aggiungiamo in testa
  new_node->next = this;
  // se esiste l'elemento precedente faccio puntare il suo successivo al nuovo elemento
  if(this->prev) this->prev->next = new_node;
  // faccio puntare il precedente del nuovo nodo al precedente del vecchio nodo
  new_node->prev = this->prev;
  // imposto il precedente di this al nuovo nodo
  this->prev = new_node;
  return new_node;
}

// inserimento dopo di this
node* node::add(node* new_node) {
  // node non valido
  if (new_node == nullptr) return this;
  new_node->prev = this;
  if(this->next) this->next->prev = new_node;
  new_node->next = this->next;
  this->next = new_node;
  return new_node;
}

node* node::erase() {

  return this;
}

void node::print_all() {
  // cerco il nodo iniziale
  node* start_node = this;
  while (start_node->prev)
    start_node = start_node->prev;
  
  cout << "{";
  while(start_node) {
    cout << start_node->value;
    if (!start_node->next) {
      cout << "}" << endl;
      return;
    }
    cout << " ";
    start_node = start_node->next;
  }
  cout << "}" << endl;
}
