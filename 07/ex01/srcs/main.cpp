#include <iostream>
#include "iter.hpp"

void printInt(int const &i)
{
    std::cout << i << " ";
}

void printFloat(float const &f)
{
    std::cout << f << " ";
}

void printString(std::string const &s)
{
    std::cout << s << " ";
}

int main(void)
{
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string stringArray[] = {"one", "two", "three", "four", "five"};

    std::cout << "intArray: ";
    iter<int>(intArray, 5, printInt);
    std::cout << std::endl;

    std::cout << "floatArray: ";
    iter<float>(floatArray, 5, printFloat);
    std::cout << std::endl;

    std::cout << "stringArray: ";
    iter<std::string>(stringArray, 5, printString);
    std::cout << std::endl;

    return 0;
}
