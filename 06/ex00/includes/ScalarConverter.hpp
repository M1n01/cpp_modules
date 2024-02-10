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
    static ConvertToCharResult convertToChar(const std::string &str);
    static ConvertToIntResult convertToInt(const std::string &str);
    static ConvertToFloatResult convertToFloat(const std::string &str);
    static ConvertToDoubleResult convertToDouble(const std::string &str);
    static bool isDoubleLiteral(const std::string& literal);

  public:
    static void convert(const std::string str);
};

bool isprintChars(std::string str);
