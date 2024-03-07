#include <MyVector.hpp>
#include <iostream>

MyVector::MyVector() : capacity_(0), length_(0), data_(nullptr) {};

MyVector::MyVector(const int& capacity) :
    capacity_(capacity) {
        data_ = new int[capacity_];
    }
MyVector::~MyVector() {
    delete[] data_;
}

void MyVector::print() const {
    for (int i = 0; i < length_; i++) {
        std::cout << data_[i] << " ";
    }
}

void MyVector::pushBack(const int& val) {
    if (length_ == capacity_) {
        capacity_*=2;
        resize(capacity_);
    }

    data_[length_] = val;
    length_++;
}

void MyVector::resize(const int& newCap) {
    int edge = (length_ < newCap) ? length_ : newCap;
    int* tmp = new int[newCap];
    for (int i = 0; i < edge; i++) {
        tmp[i] = data_[i];
    }
    delete[] data_;
    data_ = tmp;
}

void MyVector::popBack() {
    if (length_ == 0) {
        std::cout << "Nothing to pop\n";
        exit(0);
    }

    length_--;
    
    if (length_ <= capacity_ / 4) {
        capacity_/=2;
        resize(capacity_);
    }
} 

int& MyVector::operator[](const int& i) const {
    if (i >= length_) {
        std::cout << "Index out of range\n";
        exit(0);
    }
    return data_[i];
}

int MyVector::length() const {
    return length_;
}
