#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <string>

class MyVector
{
    int length_ = 0, capacity_;
    int* data_;

    public:
        MyVector();
        MyVector(const int& length);
        void pushBack(const int& val);
        void popBack();
        int& operator[](const int& i) const;
        void print() const;
        int length() const;
        ~MyVector();
    protected:

    private:
        void resize(const int& newCap);
};

#endif // MYVECTOR_H