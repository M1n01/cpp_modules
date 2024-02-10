#include "Base.hpp"
#include <iostream>

int main()
{
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}
