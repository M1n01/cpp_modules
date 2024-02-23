#include "../includes/Span.hpp"

Span::Span() : _size(0), _numbers()
{
}

Span::Span(unsigned int n) : _size(n), _numbers()
{
}

Span::Span(Span const &other) : _size(other._size), _numbers(other._numbers)
{
}

Span &Span::operator=(Span const &other)
{
    if (this != &other)
    {
        _size = other._size;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (_numbers.size() < _size)
        _numbers.push_back(n);
    else
        throw std::runtime_error("Container is full");
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate span");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[1] - sorted[0];
    for (std::vector<int>::size_type i = 2; i < sorted.size(); i++)
    {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < min)
            min = diff;
    }
    return min;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate span");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    return sorted[sorted.size() - 1] - sorted[0];
}
