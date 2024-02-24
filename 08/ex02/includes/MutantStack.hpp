#pragma once

#include <algorithm>
#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> > class MutantStack : public std::stack<T, Container>
{
  public:
    MutantStack();
    MutantStack(const MutantStack &other);
    MutantStack &operator=(const MutantStack &other);
    virtual ~MutantStack();

    typedef typename std::stack<T, Container>::container_type::iterator iterator;
    typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;

    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"
