#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "json.hpp"

std::string getUsername(nlohmann::ordered_json);

void Register();