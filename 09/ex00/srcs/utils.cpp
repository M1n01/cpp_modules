#include "../includes/utils.hpp"

static int calculateMaxDays(const int &year, const int &month)
{
    int maxDays;
    if (month == 2)
    {
        // 2月の場合、うるう年かどうかで最大日数が変わる
        const bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        maxDays = isLeapYear ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDays = 30;
    else
        maxDays = 31;

    return maxDays;
}

static bool validDate(const std::string &date)
{
    int year, month, day;
    char dash;

    std::istringstream iss(date);
    if (!(iss >> year >> dash >> month >> dash >> day))
    {
        return false;
    }

    if (month < 1 || month > 12)
    {
        return false;
    }

    // 日の範囲をチェック
    const int maxDays = calculateMaxDays(year, month);
    if (day < 1 || day > maxDays)
        return false;

    if (year < 2009 || (year == 2009 && month == 1 && day < 2)) // 2009年1月2日以降のデータのみ有効
        return false;

    return true;
}

namespace utils
{
void printError(const std::string &message)
{
    std::cerr << "Error: " << message << std::endl;
}

ParseLineResult parseLine(const std::string &line)
{
    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::string token;

    if (!line.empty())
    {
        while (std::getline(iss, token, '|'))
            tokens.push_back(token);

        if (validDate(tokens[0]))
        {
            if (!tokens[1].empty())
            {
                const double value = std::strtod(tokens[1].c_str(), nullptr);
                if (value >= 0 && value <= INT_MAX)
                    return ParseLineResult::Success(std::pair<std::string, double>(tokens[0], value));
                else if (value < 0)
                    return ParseLineResult::Error("not a positive number");
                else
                    return ParseLineResult::Error("too large a number");
            }
            else
                return ParseLineResult::Error("a value is required");
        }
        else
            return ParseLineResult::Error("bad input => " + tokens[0]);
    }
    else
        return ParseLineResult::Error("empty line");
}
} // namespace utils
