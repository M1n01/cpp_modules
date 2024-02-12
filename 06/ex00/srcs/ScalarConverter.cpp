#include "ScalarConverter.hpp"

namespace utils
{
bool isprintChars(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isprint(str[i]))
            return false;
    }
    return true;
}

double stod(const std::string &str)
{
    char *fail;
    const double value = std::strtod(str.c_str(), &fail);
    std::cout << "errno: " << errno << std::endl;
    if (str == "f" || (value == 0 && *fail != 'f'))
        throw std::invalid_argument("impossible");
    return value;
}
} // namespace utils

ConvertToCharResult ScalarConverter::convertToChar(const std::string &input)
{
    try
    {
        char *fail;
        double value = std::strtod(input.c_str(), &fail);
        if (*fail != 'f')
            return ConvertToCharResult::Error("impossible");
        std::cout << "HERE: " << value << ":" << *fail << std::endl;
        char charValue = static_cast<char>(value);
        return ConvertToCharResult::Success(charValue);
    }
    catch (const std::exception &e)
    {
        return ConvertToCharResult::Error("Huge value");
    }
}

ConvertToIntResult ScalarConverter::convertToInt(const std::string &input)
{
    if (utils::isCharLiteral(input))
        return ConvertToIntResult::Error("impossible");
    // else
    {
        const double value = std::stod(input);
        // if (std::isnan(value) || std::isinf(value))
        //     return ConvertToIntResult::Error("impossible");
        const int intValue = static_cast<int>(value);
        return ConvertToIntResult::Success(intValue);
    }
}

ConvertToFloatResult ScalarConverter::convertToFloat(const std::string &input)
{
    // if (utils::isCharLiteral(input))
    //     return ConvertToFloatResult::Error("impossible");
    // else
    {
        const double value = std::stod(input);
        const float floatValue = static_cast<float>(value);
        return ConvertToFloatResult::Success(floatValue);
    }
}

ConvertToDoubleResult ScalarConverter::convertToDouble(const std::string &input)
{
    // if (utils::isCharLiteral(input))
    //     return ConvertToDoubleResult::Error("impossible");
    // else
    {
        const double value = std::stod(input);
        const float floatValue = static_cast<float>(value);
        return ConvertToDoubleResult::Success(floatValue);
    }
}

void ScalarConverter::convert(const std::string str)
{
    const ConvertToCharResult charResult = convertToChar(str);
    const ConvertToIntResult intResult = convertToInt(str);
    const ConvertToFloatResult floatResult = convertToFloat(str);
    const ConvertToDoubleResult doubleResult = convertToDouble(str);

    std::cout << "char: ";
    if (charResult.success)
        std::cout << "\'" << charResult.value << "\'" << std::endl;
    else
        std::cout << charResult.error << std::endl;

    std::cout << "int: ";
    if (intResult.success)
        std::cout << intResult.value << std::endl;
    else
        std::cout << intResult.error << std::endl;

    std::cout << "float: ";
    if (floatResult.success)
        std::cout << std::setprecision(1) << std::fixed << floatResult.value << "f" << std::endl;
    else
        std::cout << floatResult.error << std::endl;

    std::cout << "double: ";
    if (doubleResult.success)
        std::cout << std::setprecision(1) << std::fixed << doubleResult.value << std::endl;
    else
        std::cout << doubleResult.error << std::endl;
}
