#include "../includes/PmergeMe.hpp"

PMergeMe::PMergeMe()
{
}

PMergeMe::PMergeMe(const std::deque<int> &inputDeque, const std::list<int> &inputList)
    : _inputDeque(inputDeque), _inputList(inputList)
{
}

PMergeMe::PMergeMe(const PMergeMe &other) : _inputDeque(other._inputDeque), _inputList(other._inputList)
{
}

PMergeMe &PMergeMe::operator=(const PMergeMe &other)
{
    if (this != &other)
    {
        _inputDeque = other._inputDeque;
        _inputList = other._inputList;
    }
    return *this;
}

PMergeMe::~PMergeMe()
{
}

PMergeMeResult PMergeMe::sort()
{
    std::vector<int> outputVector;
    std::merge(_inputDeque.begin(), _inputDeque.end(), _inputList.begin(), _inputList.end(),
               std::back_inserter(outputVector));
    return outputVector;
}
