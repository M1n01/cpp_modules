#pragma once

template <typename T>
class Array
{
private:
    T *_array;
    unsigned int _size;

public:
    Array(unsigned int n);
    Array(Array const &src);
    ~Array();
    Array &operator=(Array const &rhs);
    T &operator[](unsigned int index);
};
