#include <iostream>
#include "myvector.h"
using namespace std;

void print_vector(const myvector& v) {
    for (int i = 0; i < v.get_size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl; 
}

int main() {
    // initialization
    myvector v(10);

    v[5] = 6;

    // using 2 different methods for printing the vector 
    print_vector(v);
    v.to_string();

    // modifying element 5 form 6 to 7
    v.safe_set(5, 7);

    print_vector(v);

    return 0;
}
