#include "../includes/BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    else if (argc > 2)
    {
        std::cerr << "Error: Too many args." << std::endl;
        return 1;
    }
    else
    {
        BitcoinExchange exchange;
        std::ifstream file(argv[1]);
        std::string line;

        if (file.is_open())
        {
            std::getline(file, line); // 1行目は見出しのため無視
            while (std::getline(file, line))
            {
                ParseLineResult result = parseLine(line);
            }
        }
        else
        {
            std::cerr << "Error: could not open file." << std::endl;
        }
        
        return 0;
    }
}
