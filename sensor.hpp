#ifndef SENSOR_HPP
#define SENSOR_HPP
#include <string>
#include <vector>
#include <iostream>
class Sensor
{
	private:
		std::string name;
		std::vector<double> values;
	public:
		Sensor();
		Sensor(std::string);
		std::string GetName();
		void AddValue(double);
		double GetValue(int);
		std::string GetMin();
		std::string GetMax();
		std::string GetAvg();
		void ChangeValue(double);
	
};
#endif
