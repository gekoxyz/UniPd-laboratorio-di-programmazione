#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

template <typename T>
class myvector {
private:
    int max_elements {0};
    int elements {0};
    T* elem_pointer = nullptr;

    void reserve();

public:
    // costruttori
    myvector(int length);
    myvector(std::initializer_list<T> list);
    myvector(const myvector &old_vector);
    myvector(myvector &&old_vector);

    // distruttore
    ~myvector();

    // overload operatori
    T &operator[](int index);
    T operator[](int index) const;

    int size() const { return elements; };

    void set(const int index, const T new_elem);
    T get(const int index);
    T& at(const int index);
    int lenght();

    void push_back(const T newelem);
    T pop_back();

    static void print_vector(myvector &v);
    void to_string();
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const myvector<T> &myvector);

#include "myvector.hpp"
#endif