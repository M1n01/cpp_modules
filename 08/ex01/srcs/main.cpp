#include "../includes/Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        sp.addNumber(12);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Span sp(10000);
        std::vector<int> largeNumbers;
        for (int i = 1; i <= 10000; ++i)
        {
            largeNumbers.push_back(i);
        }
        sp.addNumbers(largeNumbers.begin(), largeNumbers.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        Span sp2(5);
        sp2.addNumbers(largeNumbers.begin(), largeNumbers.begin() + 3);
        std::cout << "Shortest span after partial fill: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span after partial fill: " << sp2.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Span sp(0);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Span sp(5);
        sp.addNumber(1);
        std::cout << "Shortest span on empty Span: " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
