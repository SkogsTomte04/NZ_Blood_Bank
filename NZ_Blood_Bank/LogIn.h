#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"


bool PasswordCheck(nlohmann::json, std::string);

bool getLogin(nlohmann::json, std::string);

std::string LogIn();