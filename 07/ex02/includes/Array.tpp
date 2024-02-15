#include "Array.hpp"

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    _array = new T[n];
}
