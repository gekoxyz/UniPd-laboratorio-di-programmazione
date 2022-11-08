#include <iostream>
#include "myvector.h"
using namespace std;

class invalid_parameter {};

myvector::myvector(int length) {
    if (length > 0) {
        this->length = length;
        double* pointer = new double[length];
        elem_pointer = pointer;
    }
    for (int i = 0; i < length; i++) {
        elem_pointer[i] = 0;
    }
    
}

myvector::myvector(initializer_list<double> double_list) {
    if(double_list.size() > 0) {
        length = double_list.size();
        double* pointer = new double[length];
        elem_pointer = pointer;
    }
    copy(double_list.begin(), double_list.end(), elem_pointer);
}

myvector::myvector(const myvector& old_vector) {
    length = old_vector.get_size();
    double* pointer = new double[length];
    elem_pointer = pointer;
    copy(old_vector.elem_pointer, old_vector.elem_pointer + length, elem_pointer);
}

// costruttore per un rvalue
myvector::myvector(myvector&& old_vector) {
    old_vector.length = 0;
    old_vector.elem_pointer = nullptr;
}

myvector::~myvector() { delete[] elem_pointer;}

// not const
double& myvector::operator[](int index) { return elem_pointer[index];}

// const
double myvector::operator[](int index) const { return elem_pointer[index];}

int myvector::get_size() const{ return length;}

void myvector::safe_set(const int index, const double new_elem) {
    if (0 < index && index < length) elem_pointer[index] = new_elem;
}

double myvector::safe_get(const int index) {
    if (0 < index && index < length) return elem_pointer[index];
    throw invalid_parameter();
}

void myvector::to_string() {
    for (int i = 0; i < length; i++) {
        cout << elem_pointer[i] << " "; 
    }
    cout << endl;
}