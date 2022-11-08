#include <iostream>
using namespace std;

class myvector {
private:
    int length {0};
    double* elem_pointer = nullptr;

public:
    myvector(int length);
    myvector(initializer_list<double> double_list);
    myvector(const myvector& old_vector);
    myvector(myvector&& old_vector);

    ~myvector();

    // overload degli operatori
    double& operator[](int index);
    double operator[](int index) const;


    int get_size() const;
    void safe_set(const int index, const double new_elem);
    double safe_get(const int index);
    void print_vector(myvector& v);
    void to_string();
};