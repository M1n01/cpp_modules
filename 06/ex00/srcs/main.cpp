#include "../includes/ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2 || !utils::isprintChars(argv[1]))
    {
        std::cout << "Usage: ./convert [print chars]" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
