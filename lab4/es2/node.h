#include <iostream>

using namespace std;

class node {
  private:
  node* prev;
  node* next;

  public:
  string value;

  node(const string& v, node* p = nullptr, node* n = nullptr)
    : value{v}, prev{p}, next{n} {}

  node* insert(node* n); // inserimento prima di this 
  node* add(node* n); // inserimento dopo this 
  node* erase(); // rimuove this
  node* find(const string& to_find);
  node* advance(int n);
  void print_all();

  node* push_back(string to_push);
  node* push_front(string to_push);

  string pop_back();
  string pop_front();
};