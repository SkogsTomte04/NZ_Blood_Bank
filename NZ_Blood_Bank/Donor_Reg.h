#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include "json.hpp"

std::array<int, 3> getDate(std::string);

std::string getString(std::string);

std::string getUsername(nlohmann::json);

void Register();