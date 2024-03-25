#include "../includes/PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: Incorrect number of arguments. Usage: ./PmergeMe <positive_integers>" << std::endl;
        return 1;
    }
    else
    {
        std::deque<int> inputDeque;
        std::list<int> inputList;

        for (int i = 1; argv[i]; i++)
        {
            char *endptr;
            long num = std::strtol(argv[i], &endptr, 10);

            if (*endptr != '\0' || num <= 0 || num > std::numeric_limits<int>::max())
            {
                std::cerr << "Error: Invalid input. Please provide positive integers only." << std::endl;
                return 1;
            }
            inputDeque.push_back(static_cast<int>(num));
            inputList.push_back(static_cast<int>(num));
        }

        PMergeMe pmergeMe(inputDeque, inputList);
        const PMergeMeResult &result = pmergeMe.sort();
        if (result.success)
            print(inputList, result.value);
        else
            std::cerr << result.error << std::endl;
    }
    return 0;
}
