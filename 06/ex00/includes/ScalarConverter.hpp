#pragma once

#include "Result.hpp"
#include <iostream>
#include <iomanip>

typedef Result<int, std::string> ConvertToIntResult;
typedef Result<float, std::string> ConvertToFloatResult;
typedef Result<double, std::string> ConvertToDoubleResult;
typedef Result<char, std::string> ConvertToCharResult;

class ScalarConverter
{
  private:
    ConvertToCharResult convertToChar(const std::string &str);
    ConvertToIntResult convertToInt(const std::string &str);
    ConvertToFloatResult convertToFloat(const std::string &str);
    ConvertToDoubleResult convertToDouble(const std::string &str);
    bool isDoubleLiteral(const std::string& literal);

  public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter &operator=(const ScalarConverter &rhs);
    ~ScalarConverter();

    void convert(const std::string str);
};

bool isprintChars(std::string str);
