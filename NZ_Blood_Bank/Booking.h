#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include "json.hpp"

void inSchedule(std::string, int, std::string);

int getHour();

std::string getDay();

void BookAppointment(std::string);