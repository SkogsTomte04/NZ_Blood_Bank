#pragma once
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "colors.hpp"

void printUser(nlohmann::ordered_json, std::string);

void updateJson(nlohmann::ordered_json, std::string);

nlohmann::ordered_json getUserdata();

nlohmann::ordered_json getScheduledata();