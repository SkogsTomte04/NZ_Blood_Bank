#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include "json.hpp"

nlohmann::json NewDate(nlohmann::json, std::string, std::string, std::string);

nlohmann::json updateUserdate(nlohmann::json, std::string, int, std::string);

int getHour(nlohmann::json, std::string);

std::string getDay();

void BookAppointment(std::string);