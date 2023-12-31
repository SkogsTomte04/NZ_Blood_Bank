#pragma once
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "colors.hpp"

void printuserSchedule(nlohmann::ordered_json, std::string, std::string);

void printuserInfo(nlohmann::ordered_json, std::string, std::string);

void printUser(nlohmann::ordered_json, std::string, std::string);

void updateJson(nlohmann::ordered_json, std::string);

nlohmann::ordered_json getUserdata();

nlohmann::ordered_json getScheduledata();