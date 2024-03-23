#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    this->loadDataBase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->bitcoinPriceHistory = other.bitcoinPriceHistory;
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
                this->bitcoinPriceHistory[date] = std::strtod(price.c_str(), NULL);
            }
            catch (std::invalid_argument &e)
            {
                utils::printError(e.what());
            }
        }
        file.close();
    }
    else
    {
        utils::printError("could not open file.");
    }
}

double BitcoinExchange::getPrice(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = this->bitcoinPriceHistory.begin();
    double prevPrice = it->second;
    while (it != this->bitcoinPriceHistory.end())
    {
        if (it->first == date)
        {
            return it->second;
        }
        else if (it->first > date)
        {
            break;
        }
        prevPrice = it->second;
        it++;
    }
    return prevPrice;
}
