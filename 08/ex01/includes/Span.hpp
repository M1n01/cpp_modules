#pragma once

#include <algorithm>
#include <vector>

class Span
{
  private:
    unsigned int _size;
    std::vector<int> _numbers;

  public:
    Span();
    Span(unsigned int n);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();

    void addNumber(int n);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan();
    int longestSpan();
};
