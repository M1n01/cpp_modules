#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    this->loadDataBase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    this->bitcoinPriceHistory = other.bitcoinPriceHistory;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDataBase(void)
{
    std::ifstream file(DATABASE_PATH);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            const std::string date = line.substr(0, line.find(","));
            const std::string price = line.substr(line.find(",") + 1);
            try
            {
                this->bitcoinPriceHistory[date] = std::strtof(price.c_str(), NULL);
            }
            catch (std::invalid_argument &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        file.close();
    }
    else
    {
        std::cerr << "Error: could not open file." << std::endl;
    }
}

void BitcoinExchange::printPrice(const std::string &filepath)
{
    std::ifstream file(filepath);
    std::string line;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            const std::string date = line.substr(0, line.find(" | "));
            try
            {
                const int value = std::stoi(line.substr(line.find(" | ") + 3));
                std::cout << date << " | " << value << " | " << this->bitcoinPriceHistory.at(date) << std::endl;
            }
            catch (std::out_of_range &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    else
    {
        std::cerr << "Error: could not open file." << std::endl;
    }
}
