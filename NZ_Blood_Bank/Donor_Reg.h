#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include "json.hpp"

std::string getString(std::string);

long int getInt(std::string);

std::vector <std::string> getVector(std::string);

std::array<int, 3> getDate(std::string);

std::string getUsername(nlohmann::json);

void Register();