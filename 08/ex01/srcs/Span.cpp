#include "../includes/Span.hpp"

Span::Span() : _size(0), _numbers()
{
}

Span::Span(unsigned int n) : _size(n), _numbers()
{
    if (n == 0)
        throw std::runtime_error("Size must be greater than 0");
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

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (static_cast<size_t>(std::distance(begin, end)) <= _size - _numbers.size())
        _numbers.insert(_numbers.end(), begin, end);
    else
        throw std::runtime_error("Container is full");
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate span");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int min = INT_MAX;
    for (std::vector<int>::size_type i = 1; i < sorted.size(); i++)
    {
        const int diff = sorted[i] - sorted[i - 1];
        if (diff < min)
            min = diff;
    }
    return min;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate span");
    return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}
