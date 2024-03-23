#pragma once

#include "Result.hpp"
#include <iostream>
#include <utility>

const std::string DATABASE_PATH = "database/data.csv";

typedef Result<std::pair<std::string, double>, std::string> ParseLineResult;
