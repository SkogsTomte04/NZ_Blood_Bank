#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include "json.hpp"

nlohmann::ordered_json getSchedulejson();

void inSchedule(std::string, int, std::string, nlohmann::json);

int getHour(nlohmann::json, std::string);

std::string getDay();

void BookAppointment(std::string);