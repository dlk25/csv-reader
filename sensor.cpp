#include "sensor.hpp"

Sensor::Sensor(){
	this->name = "";
}

Sensor::Sensor(std::string name){
	this->name = name;
}

std::string Sensor::GetName(){
	return name;
}

void Sensor::AddValue(double value){
	values.push_back(value);
}

double Sensor::GetValue(int index){
	return values.at(index);
}

std::string Sensor::GetMin(){
	double min = values.at(0);
	for(unsigned int i = 0; i < values.size(); i++){
		if(values.at(i) < min){
			min = values.at(i);
		}
	}
	std::string mins = std::to_string(min);
	return mins;
}

std::string Sensor::GetMax(){
        double max = values.at(0);
        for(unsigned int i = 0; i < values.size(); i++){
                if(values.at(i) > max){
                        max = values.at(i);
                }
        }
	std::string maxs = std::to_string(max);
	return maxs;
}

std::string Sensor::GetAvg(){
	double avg = 0;
	for(unsigned int i = 0; i < values.size(); i++){
		avg += values.at(i);
	}
	avg = avg / values.size();
	std::string avgs = std::to_string(avg);
	return avgs;
}

void Sensor::ChangeValue(double value){
	for(unsigned int i = 0; i < values.size(); i++){
		values.at(i) += value;
	}
}
void Sensor::ChangeRandomValue(){
	int toChange = rand() % values.size() + 1;
	std::cout << "Location to Change: " << toChange << std::endl;
	int changeBy = rand() % (2 * std::stoi(GetMax()) + 1);
	std::cout << "Amount to Change: " << changeBy << std::endl << std::endl;
}
