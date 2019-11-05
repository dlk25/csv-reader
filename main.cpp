#include "capture.hpp"
#include <iostream>
#include <string>
int main(){
	std::string fname = "";
	int senseToChange = 0;
	double amtToChange = 0.0;
	char repeat = 'y';
	char list = 'f';
	//char defVal = 'y';
	//Capture capture();
	//std::cout << "Press \"Y/y\" to use default input and output files: ";//FIXME
	//if(defVal == 'y' || defVal =='Y'){
		Capture capture(/*"./EcuSim_19-11-04/CSVLog_20191031_125215.csv*/"testin.csv");
	//}
	//else{
	//	std::cout << "\nEnter the full name and relative path of the .csv file to import: ";
	//	std::cin >> fname;
	//	Capture capture(fname);
	//}
	do{	
		if(capture.UnusedSensors() != ""){
			std::cout << "Press \"F/f\" to show the full list of sensors, otherwise only used sensors will be shown: ";
			std::cin >> list;
			if(list == 'f' || list == 'F'){
				std::cout << capture.GetSensors();
			}
			else{
				std::cout << capture.GetUsedSensors();
			}
		}
		else{
			std::cout << capture.GetSensors();
		}

		std::cout << "\nEnter the number for the sensor you want to change: ";
		std::cin >> senseToChange;
		std::cout << "\n How much would you like to change it by: ";
		std::cin >> amtToChange;

		capture.ChangeValues(senseToChange, amtToChange);

		std::cout << "Press \"Y/y\" to change another value: ";
		std::cin >> repeat;
	}while(repeat == 'y' || repeat == 'Y');

	if(capture.UnusedSensors() != ""){
		std::cout << "Unused sensors are:\n";
		std::cout << capture.UnusedSensors();
	}
	capture.WriteFile("testout.csv");

	return 0;
}
