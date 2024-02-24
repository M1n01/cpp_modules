#include "../includes/BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    else
    {
        BitcoinExchange exchange;

        exchange.printPrice(argv[1]);
        return 0;
    }
}
