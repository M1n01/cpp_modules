#include "../includes/MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Stack size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\nStack contents (forward): ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Stack contents (reverse): ";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Stack contents (const forward): ";
    for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    MutantStack<int> s(mstack);
    MutantStack<int> s2;
    s2 = s;

    std::cout << "Copy assigned stack contents: ";
    for (MutantStack<int>::iterator it = s2.begin(); it != s2.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "\nTesting with std::list:" << std::endl;
    std::list<int> lstack;
    lstack.push_back(5);
    lstack.push_back(17);
    std::cout << "List contents: ";
    for (std::list<int>::iterator it = lstack.begin(); it != lstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
