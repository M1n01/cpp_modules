#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
    if (this != &rhs)
    {
    }
    return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

Result<char, std::string> ScalarConverter::convertChar(const char *value)
{
    _c = static_cast<char>(std::stoi(value));

    if (_c < 32 || _c > 126)
        return Result<char, std::string>::Error("impossible");
    std::cout << "'" << _c << "'" << std::endl;
    return Result<char, std::string>::Success(_c);
}

Result<int, std::string> ScalarConverter::convertInt(const char *value)
{
    if (std::strlen(value) == 1 && !std::isdigit(value[0])) // if value is a char
        return Result<int, std::string>::Error("impossible");

    _i = static_cast<int>(std::stoi(value));

    std::cout << _i << std::endl;
    return Result<int, std::string>::Success(_i);
}

Result<float, std::string> ScalarConverter::convertFloat(const char *value)
{
    if (std::strlen(value) == 1 && !std::isdigit(value[0])) // if value is a char
        return Result<float, std::string>::Error("impossible");

    _f = static_cast<float>(std::stof(value));

    std::cout << _f;
    if (_f - static_cast<int>(_f) == 0)
        std::cout << ".0";
    std::cout << "f" << std::endl;
    return Result<float, std::string>::Success(_f);
}

Result<double, std::string> ScalarConverter::convertDouble(const char *value)
{
    if (std::strlen(value) == 1 && !std::isdigit(value[0])) // if value is a char
        return Result<double, std::string>::Error("impossible");

    _d = static_cast<double>(std::stod(value));

    std::cout << _d;
    if (_d - static_cast<int>(_d) == 0)
        std::cout << ".0";
    std::cout << std::endl;
    return Result<double, std::string>::Success(_d);
}

void ScalarConverter::convert(const char *value)
{
    std::cout << "char: ";
    Result<char, std::string> charResult = convertChar(value);
    if (!charResult.success)
        std::cout << charResult.error << std::endl;
    else
        std::cout << charResult.value << std::endl;

    std::cout << "int: ";
    Result<int, std::string> intResult = convertInt(value);
    if (!intResult.success)
        std::cout << intResult.error << std::endl;
    else
        std::cout << intResult.value << std::endl;

    std::cout << "float: ";
    Result<float, std::string> floatResult = convertFloat(value);
    if (!floatResult.success)
        std::cout << floatResult.error << std::endl;
    else
        std::cout << floatResult.value << std::endl;

    std::cout << "double: ";
    Result<double, std::string> doubleResult = convertDouble(value);
    if (!doubleResult.success)
        std::cout << doubleResult.error << std::endl;
    else
        std::cout << doubleResult.value << std::endl;
}
