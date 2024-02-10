#include "ScalarConverter.hpp"

ConvertToCharResult ScalarConverter::convertToChar(const std::string &str)
{
    if (isDoubleLiteral(str))
    {
        ConvertToIntResult intResult = convertToInt(str);
        if (intResult.success)
        {
            if (isprint(intResult.value))
            {
                return (ConvertToCharResult::Success(intResult.value));
            }
            else
            {
                return (ConvertToCharResult::Error("Non displayable"));
            }
        }
        else
        {
            return (ConvertToCharResult::Error("impossible"));
        }
    }
    else
    {
        return (ConvertToCharResult::Success(str[0]));
    }
}

ConvertToIntResult ScalarConverter::convertToInt(const std::string &str)
{
    try
    {
        int value = std::stoi(str);
        return (ConvertToIntResult::Success(value));
    }
    catch (const std::exception &e)
    {
        return (ConvertToIntResult::Error("impossible"));
    }
}

ConvertToFloatResult ScalarConverter::convertToFloat(const std::string &str)
{
    try
    {
        float value = std::stof(str);
        return (ConvertToFloatResult::Success(value));
    }
    catch (const std::exception &e)
    {
        return (ConvertToFloatResult::Error("impossible"));
    }
}

ConvertToDoubleResult ScalarConverter::convertToDouble(const std::string &str)
{
    try
    {
        double value = std::stod(str);
        return (ConvertToDoubleResult::Success(value));
    }
    catch (const std::exception &e)
    {
        return (ConvertToDoubleResult::Error("impossible"));
    }
}

bool ScalarConverter::isDoubleLiteral(const std::string &literal)
{
    try
    {
        std::stod(literal);
        return (true);
    }
    catch (const std::exception &e)
    {
        return (false);
    }
}

void ScalarConverter::convert(const std::string str)
{
    ConvertToCharResult charResult = convertToChar(str);
    ConvertToIntResult intResult = convertToInt(str);
    ConvertToFloatResult floatResult = convertToFloat(str);
    ConvertToDoubleResult doubleResult = convertToDouble(str);

    std::cout << "char: ";
    if (charResult.success)
    {
        std::cout << "\'" << charResult.value << "\'" << std::endl;
    }
    else
    {
        std::cout << charResult.error << std::endl;
    }

    std::cout << "int: ";
    if (intResult.success)
    {
        std::cout << intResult.value << std::endl;
    }
    else
    {
        std::cout << intResult.error << std::endl;
    }

    std::cout << "float: ";
    if (floatResult.success)
    {
        std::cout << std::setprecision(1) << std::fixed << floatResult.value << "f" << std::endl;
    }
    else
    {
        std::cout << floatResult.error << std::endl;
    }

    std::cout << "double: ";
    if (doubleResult.success)
    {
        std::cout << std::setprecision(1) << std::fixed << doubleResult.value << std::endl;
    }
    else
    {
        std::cout << doubleResult.error << std::endl;
    }
}

bool isprintChars(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isprint(str[i]))
        {
            return (false);
        }
    }
    return (true);
}
