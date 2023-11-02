#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"


bool PasswordCheck(nlohmann::json, std::string);

bool FindUsername(nlohmann::json, std::string);

std::string LogIn();