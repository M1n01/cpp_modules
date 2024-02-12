#pragma once

#include "Result.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

typedef Result<int, std::string> ConvertToIntResult;
typedef Result<float, std::string> ConvertToFloatResult;
typedef Result<double, std::string> ConvertToDoubleResult;
typedef Result<char, std::string> ConvertToCharResult;

class ScalarConverter
{
  private:
    static ConvertToCharResult convertToChar(const std::string &input);
    static ConvertToIntResult convertToInt(const std::string &input);
    static ConvertToFloatResult convertToFloat(const std::string &input);
    static ConvertToDoubleResult convertToDouble(const std::string &input);

  public:
    static void convert(const std::string str);
};

namespace utils
{
bool isprintChars(const std::string &str);
} // namespace utils
