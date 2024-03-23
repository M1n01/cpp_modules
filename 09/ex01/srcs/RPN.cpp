#include "../includes/RPN.hpp"

static bool isOperator(const std::string &token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

static int parseToken(const std::string &token)
{
    if (isOperator(token))
        return token[0];

    std::istringstream iss(token);
    int num;
    if (!(iss >> num) || num < 0 || num > 9)
        throw std::out_of_range("Error");

    return num;
}

static int applyOperator(const int &lhs, const int &rhs, const char &op)
{
    switch (op)
    {
    case '+':
        return lhs + rhs;
    case '-':
        return lhs - rhs;
    case '*':
        return lhs * rhs;
    case '/':
        return lhs / rhs;
    default:
        throw std::invalid_argument("Error: invalid operator");
    }
}

static void validateResult(const int &result)
{
    if (result < 0 || result > 1000)
        throw std::out_of_range("Error: result out of range");
}

int rpn(const std::string &expression)
{
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    try
    {
        while (iss >> token)
        {
            const int parsed = parseToken(token);

            if (isOperator(token))
            {
                if (stack.size() < 2)
                    throw std::underflow_error("Error: not enough operands");
                const int rhs = stack.top();
                stack.pop();
                const int lhs = stack.top();
                stack.pop();
                stack.push(applyOperator(lhs, rhs, parsed)); // push result
            }
            else
            {
                stack.push(parsed); // push number
            }
        }

        if (stack.size() != 1)
            throw std::overflow_error("Error: too many operands");

        validateResult(stack.top());
        std::cout << stack.top() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
