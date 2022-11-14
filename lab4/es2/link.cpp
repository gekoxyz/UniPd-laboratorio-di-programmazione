#include <string>
using namespace std;

class link {
private:
  string value;
  link* prev{nullptr};
  link* succ{nullptr};

public:
  link(const string& v, link* p = nullptr, link* s = nullptr) {
    string value{v};
    link* prev{p};
    link* succ{s};
  }

};