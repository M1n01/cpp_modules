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
                this->bitcoinPriceHistory[date] = std::stof(price);
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

void BitcoinExchange::printPrice(std::string date)
{
    std::map<std::string, double>::iterator it = this->bitcoinPriceHistory.find(date);
    if (it != this->bitcoinPriceHistory.end())
    {
        std::cout << "Price on " << date << " was " << it->second << std::endl;
    }
    else
    {
        std::cerr << "Error: date not found." << std::endl;
    }
}
