#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <iostream>
#include "myvector.h"

class invalid_parameter {};
class no_elements_exception{};

template <typename T>
myvector<T>::myvector(int length) {
    elements = length;
    max_elements = length;
    T* pointer = new T[length];
    elem_pointer = pointer;
}

template <typename T>
myvector<T>::myvector(std::initializer_list<T> list) {
    if(list.size() > 0) {
        elements = list.size();
        max_elements = list.size();
        T* pointer = new T[elements];
        elem_pointer = pointer;
        for (int i = 0; i < elements; i++)
            elem_pointer[i] = 0;
    }
    std::copy(list.begin(), list.end(), elem_pointer);
}

template <typename T>
myvector<T>::myvector(const myvector<T> &old_vector) {
    elements = old_vector.size();
    max_elements = old_vector.size();
    double* pointer = new double[elements];
    elem_pointer = pointer;
    std::copy(old_vector.elem_pointer, old_vector.elem_pointer + elements, elem_pointer);
}

// costruttore per un rvalue
template <typename T>
myvector<T>::myvector(myvector<T> &&old_vector) {
    old_vector.elements = 0;
    old_vector.max_elements = 0;
    old_vector.elem_pointer = nullptr;
}

// distruttore
template <typename T>
myvector<T>::~myvector() { delete[] elem_pointer;}

// not const
template <typename T>
T& myvector<T>::operator[](int index) { return elem_pointer[index];}

// const
template <typename T>
T myvector<T>::operator[](int index) const { return elem_pointer[index];}

template <typename T>
myvector<T>& myvector<T>::operator=(const myvector &new_vector) {
    if (this->max_elements < new_vector.max_elements) {
        T *new_elem_pointer = new T[new_vector.max_elements];
        std::copy(new_vector.elem_pointer, new_vector.elem_pointer + new_vector.elements, new_elem_pointer);
        delete[] elem_pointer;
        elem_pointer = new_elem_pointer;
        elements = new_vector.elements;
        max_elements = new_vector.max_elements;
    }
    std::copy(new_vector.elem_pointer, new_vector.elem_pointer + new_vector.elements, elem_pointer);
    elements = new_vector.elements;
    max_elements = new_vector.max_elements;
    return *this;
}

// deleting this pointer data, pointing this to new data and deleting new pointer
template <typename T>
myvector<T>& myvector<T>::operator=(myvector &&new_vector) {
    delete[] elem_pointer;
    elem_pointer = new_vector.elem_pointer;
    new_vector.elem_pointer = nullptr;
    elements = new_vector.elements;
    max_elements = new_vector.max_elements;
    return *this;
}

template <typename T>
void myvector<T>::set(const int index, const T new_elem) {
    if (index >= 0 && index < elements) elem_pointer[index] = new_elem;
}

template <typename T>
T myvector<T>::get(const int index) {
    if (index >= 0 && index < elements) return elem_pointer[index];
    throw invalid_parameter();
}

template <typename T>
T& myvector<T>::at(int index) {
    if (index >= 0 && index < elements) return elem_pointer[index];
    throw invalid_parameter();
}

// allocates more space for myvector
template<typename T>
void myvector<T>::reserve() {
    max_elements *= 2;
    T* new_elem_pointer = new T[max_elements];
    copy(elem_pointer, elem_pointer + elements, new_elem_pointer);
    delete[] elem_pointer;
    elem_pointer = new_elem_pointer;
}

template <typename T>
void myvector<T>::push_back(const T newelem) {
    if ((elements + 1) > max_elements) myvector::reserve();
    elem_pointer[elements] = newelem;
    elements++;
}

// ritorno il puntatore all'ultimo elemento e poi decremento il numero di elementi
template <typename T>
T myvector<T>::pop_back() {
    if (elements > 0) return elem_pointer[elements--];
    throw no_elements_exception();
}

template <typename T>
void myvector<T>::to_string() {
    for (int i = 0; i < elements; i++) {
        std::cout << elem_pointer[i] << " ";
    }
    std::cout << std::endl; 
}

template<typename T>
std::ostream &operator<<(std::ostream &os, myvector<T> &myvector) {
    for (int i = 0; i < myvector.size(); i++) {
        os << myvector.get(i) << " "; 
    }
    return os;
}

#endif