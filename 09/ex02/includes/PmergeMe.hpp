#pragma once

#include "Result.hpp"
#include "sort.hpp"
#include <deque>
#include <list>
#include <vector>

typedef Result<std::vector<int>, std::string> PMergeMeResult;

class PMergeMe
{
  private:
    std::deque<int> _inputDeque;
    std::list<int> _inputList;
    std::vector<int> _outputVector;

    PMergeMe(const PMergeMe &other);
    PMergeMe &operator=(const PMergeMe &other);

  public:
    PMergeMe();
    PMergeMe(const std::deque<int> &inputDeque, const std::list<int> &inputList);
    ~PMergeMe();

    PMergeMeResult sort();
};
