#pragma once

#include <fstream>
#include <iostream>
#include <map>

const std::string DATABASE_PATH = "database/data.csv";

class BitcoinExchange
{
  private:
    std::map<std::string, double> bitcoinPriceHistory;

    void loadDataBase(void);

  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void printPrice(std::string date);
};
