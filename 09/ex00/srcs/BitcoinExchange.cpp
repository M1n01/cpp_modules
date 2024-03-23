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

Result<std::vector<std::string>, std::string> splitLine(std::string &line)
{
    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(iss, token, '|'))
        tokens.push_back(token);

    if (!validDate(token[0]))
        return Result<std::vector<std::string>, std::string>::Error("");
    if (!validValue(tokens[1]))
        return Result<std::vector<std::string>, std::string>::Error("");
    if (tokens.size() == 2 && )

    return Result<std::vector<std::string>, std::string>::Success(tokens);
}

void BitcoinExchange::printPrice(const std::string &filepath)
{
    std::ifstream file(filepath);
    std::string line;

    if (file.is_open())
    {
        std::getline(file, line); // 1行目は見出しのため無視
        while (std::getline(file, line))
        {
            Result<std::vector<std::string>, std::string> result = splitLine(line);
            if (result.success)
            {
                const std::string date = result.value[0];
                const int value = stoi(result.value[1]);
                std::cout << date << " => " << value << " = " << value * bitcoinPriceHistory.at(date) << std::endl;
            }
            else
            {
                std::cout << result.error << std::endl;
            }
        }
    }
    else
    {
        std::cerr << "Error: could not open file." << std::endl;
    }
}
