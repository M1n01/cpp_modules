#pragma once

#include "alias.hpp"
#include <iostream>
#include <sstream>
#include <vector>

namespace utils
{
void printError(const std::string &message);
ParseLineResult parseLine(const std::string &line);
} // namespace Utils
