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
    std::deque<int> deque(_inputDeque);
    std::list<int> list(_inputList);

    fordJohnsonSort(deque);
    // fordJohnsonSort(list);

    // if (!std::equal(deque.begin(), deque.end(), list.begin()))
    //     return PMergeMeResult::Error("Error: Deque and List results do not match");

    _outputVector = std::vector<int>(deque.begin(), deque.end());
    return PMergeMeResult::Success(_outputVector);
}
