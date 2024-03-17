#include "Base.hpp"
#include <iostream>

int main()
{
    Base *base = generate();

    std::cout << "Identify by pointer:" << std::endl;
    identify(base);
    std::cout << "Identify by reference:" << std::endl;
    identify(*base);
    delete base;

    return 0;
}
