#include "capture.hpp"
/*
Capture::Capture(){

}
*/
Capture::Capture(std::string fileName){
	numSensors = 0;
	std::ifstream fileIn;
	source = fileName;
        fileIn.open(fileName.c_str());
	std::getline(fileIn, time);
	std::getline(fileIn, senseList);
	std::stringstream ss(senseList);
	std::string substr = "";
	while(ss.good()){
		getline(ss, substr, ',');
		sensors.push_back(substr);
		used.push_back(false);
		numSensors++;
	}
	while(std::getline(fileIn, temp)){
		ParseSensors(temp);
		numLines++;
	}
	fileIn.close();
}

void Capture::ParseSensors(std::string line){
	std::string data[numSensors];
	std::stringstream ssin(line);
	double dataNum;
	for(int i = 0; i < numSensors; i++){
		getline(ssin, data[i], ',');
	}
	for(int i = 0; i < numSensors; i++){
		if(!data[i].empty()){
			dataNum = 0;
			dataNum = std::stod(data[i]);
			if(dataNum != 0){
				used.at(i) = true;
			}
			sensors.at(i).AddValue(dataNum);
		}
	}
}

std::string Capture::GetUsedSensors(){
	std::string toReturn = "";
	for(int i = 0; i < numSensors; i++){
		if(used.at(i)){
			std::string index = std::to_string(i);
	                toReturn = toReturn + index + ":  ";
	                toReturn = toReturn + sensors.at(i).GetName();
	                toReturn = toReturn + "\n\tMin: " + sensors.at(i).GetMin();
	                toReturn = toReturn + "   Max: " + sensors.at(i).GetMax();
	                toReturn = toReturn + "   Avg: " + sensors.at(i).GetAvg();
	                toReturn = toReturn + "\n\n";
		}
	}
	return toReturn;
}

std::string Capture::GetSensors(){
	std::string toReturn = "";
	for(int i = 0; i < numSensors; i++){
		std::string index = std::to_string(i);
		toReturn = toReturn + index + ":  ";
		toReturn = toReturn + sensors.at(i).GetName();
		toReturn = toReturn + "\n\tMin: " + sensors.at(i).GetMin();
                toReturn = toReturn + "   Max: " + sensors.at(i).GetMax();
                toReturn = toReturn + "   Avg: " + sensors.at(i).GetAvg();
		toReturn = toReturn + "\n\n";
	}
	return toReturn;
}

std::string Capture::UnusedSensors(){
	std::string toReturn = "";
	for(int i = 0; i < numSensors; i++){
		if(!used.at(i)){
			toReturn = toReturn + sensors.at(i).GetName() + "\n";
		}
	}
	return toReturn;
}

void Capture::ChangeValues(int soi, double value){
	sensors.at(soi).ChangeValue(value);
}
//FIXME IN DEVELOPMENT
void Capture::RandomChanges(int toChange){
	for(int i = 0; i < toChange; i++){
		int random = rand() % numSensors;
		sensors.at(random).ChangeRandomValue();
	}
}
//**************************************************

void Capture::WriteFile(std::string fileName){
	std::ofstream fileOut;
	fileOut.open(fileName.c_str());
	fileOut << time << std::endl;
	fileOut << senseList << std::endl;
	for(int i = 0; i < numLines; i++){
		for(int j = 0; j < numSensors; j++){
			if(j < numSensors - 1){
				fileOut << sensors.at(j).GetValue(i) << ",";
			}
			else{
				fileOut << sensors.at(j).GetValue(i);
			}
		}
		fileOut << std::endl;
	}
	fileOut.close();
}
