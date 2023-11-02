#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include "json.hpp"
//using json = nlohmann::json;
//using namespace std;

int getHour();

std::string getDay();

void BookAppointment(std::string user);