#include "../includes/BitcoinExchange.hpp"

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
                const ParseLineResult result = utils::parseLine(line);
                if (result.success)
                {
                    const std::string &date = result.value.first;
                    const double &value = result.value.second;
                    std::cout << date << " => " << value << " = " << value * exchange.getPrice(date) << std::endl;
                }
                else
                {
                    utils::printError(result.error);
                }
            }
        }
        else
        {
            utils::printError("could not open file.");
        }

        return 0;
    }
}
