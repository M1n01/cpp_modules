#pragma once

#include <cmath>
#include <deque>
#include <list>
#include <vector>

void fordJohnsonMerge(std::deque<int> &deque, std::deque<int>::iterator begin, std::deque<int>::iterator end);
{
	
}

void fordJohnsonSort(std::deque<int> &deque)
{
    std::deque<int>::iterator begin = deque.begin();
    std::deque<int>::iterator end = deque.begin() + static_cast<int>(std::pow(2, std::floor(std::log2(deque.size()))));

    fordJohnsonMerge(deque, begin, end);
    insertionSort(deque, end, deque.end());
    std::inplace_merge(begin, end, deque.end());
}
