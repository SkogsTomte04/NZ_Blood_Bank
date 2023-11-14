#pragma once
#include <iostream>
#include <fstream>
#include "json.hpp"

void updateJson(nlohmann::ordered_json, std::string);

nlohmann::ordered_json getUserdata();

nlohmann::ordered_json getScheduledata();