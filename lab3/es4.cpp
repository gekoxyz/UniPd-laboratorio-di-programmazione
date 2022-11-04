#include <iostream>
using namespace std;

class invalid_parameter {};

class myvector {
    int size;
    double *elem;

    public:
    
    myvector(int s) : size{s}, elem{new double[s]} {
        if(s == 0) elem = nullptr;
    }

    ~myvector() { delete[] elem;}

    // non const
    double& operator[](int n) { return elem[n];}

    // const
    double operator[](int n) const { return elem[n];}

    int get_size() { return size;}

    void safe_set(const int n, const double new_elem) {
        if (0 < n && n < size) elem[n] = new_elem;
    }

    double safe_get(const int n) {
        if (0 < n && n < size) return elem[n];
        throw invalid_parameter();
    }
};

void print_vector(myvector& v) {
    for (int i = 0; i < v.get_size(); i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
}

int main() {
    // initialization
    myvector v(10);
    v[5] = 6;

    print_vector(v);

    // modifying element 5 form 6 to 7
    v.safe_set(5, 7);

    print_vector(v);

    return 0;
}