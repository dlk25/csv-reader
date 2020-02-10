#ifndef CAPTURE_HPP
#define CAPTURE_HPP
#include "sensor.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
class Capture
{
	private:
		std::vector<Sensor> sensors;
		std::vector<bool> used;
		std::string source;
		std::string time;
		std::string senseList;
		std::string temp;
		int numSensors;
		int numLines;
	public:
		Capture();
		Capture(std::string);
		void ParseSensors(std::string);
		void ChangeValues(int, double);
		void RandomChanges(int);
		std::string GetSensors();
		std::string GetUsedSensors();
		std::string UnusedSensors();
		void WriteFile(std::string);

};
#endif
