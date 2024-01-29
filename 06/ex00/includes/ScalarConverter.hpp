#pragma once

#include "Result.hpp"
#include <iostream>

class ScalarConverter
{
  private:
    char _c;
    int _i;
    float _f;
    double _d;

	Result<char, std::string> convertChar(const char *value);
	Result<int, std::string> convertInt(const char *value);
	Result<float, std::string> convertFloat(const char *value);
	Result<double, std::string> convertDouble(const char *value);

  public:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter &operator=(const ScalarConverter &rhs);
    ~ScalarConverter(void);

    void convert(const char *value);
};
