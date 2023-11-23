#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <limits>
#include "colors.hpp"
#include "json.hpp"

int getInt();

std::string getString(std::string);

int getInt(std::string);

std::vector <std::string> getVector(std::string);

std::array <int, 3> getDate(std::string);

std::string getUsername(nlohmann::ordered_json);