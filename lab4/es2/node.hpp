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
  if (this->prev) this->prev->next = this->next;
  if (this->next) this->next->prev = this->prev;
  return this;
}

// il find e' implementato prima all'indietro e poi in avanti per risparmiare operazioni
// di ricerca. mentre su print_all devo per forza fare una stampa ordinata per la ricerca
// posso confrontare i nodi nell'ordine che voglio
node* node::find(const string& to_find) { 
  // cerco il nodo iniziale
  node* current_node = this;
  // ricerca all'indietro
  while (current_node->prev)
    if (current_node->value == to_find) return current_node;
  // ricerca in avanti
  current_node = this;
  while (current_node->next)
    if (current_node->value == to_find) return current_node;
  // non trovato
  return nullptr;  
}

node* node::advance(int n) {
  node* to_advance = this;
    if (n > 0) {
      while (n--) {
        if(!to_advance->next) return nullptr;
        to_advance = to_advance->next;
      }
    } else if (n < 0) {
      while (n++) {
        if (!to_advance->prev) return nullptr;
        to_advance = to_advance->prev;
      }
    }
  return to_advance;
}

node* node::push_back(string to_push) {
  node* current_node = this;
  while (current_node->next)
    current_node = current_node->next;
  node* to_add = new node(to_push);
  current_node->add(to_add);
  return to_add;
}

node* node::push_front(string to_push) {
  node* current_node = this;
  while (current_node->prev)
    current_node = current_node->prev;
  node* to_add = new node(to_push);
  current_node->insert(to_add);
  return to_add;
}

string node::pop_back() {
  node* current_node = this;
  while (current_node->next)
    current_node = current_node->next;
  current_node->prev->next = nullptr;
  return current_node->value;
}

string node::pop_front() {
  node* current_node = this;
  while (current_node->prev)
    current_node = current_node->prev;
  current_node->next->prev = nullptr;
  return current_node->value;
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
