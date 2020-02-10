#include "capture.hpp"
#include <iostream>
#include <string>
#include <limits>
int main(){
	std::string fname = "";
	int senseToChange = 0;
	int numberToChange = 0;
	double amtToChange = 0.0;
	char repeat = 'n';
	char list = 'f';
	char method = 'l';
	//char defVal = 'y';
	//Capture capture();
	//std::cout << "Press \"Y/y\" to use default input and output files: ";//FIXME
	//if(defVal == 'y' || defVal =='Y'){
		Capture capture(/*"../EcuSim_19-11-04/CSVLog_20191031_125215.csv*/"testin.csv");
	//}
	//else{
	//	std::cout << "\nEnter the full name and relative path of the .csv file to import: ";
	//	std::cin >> fname;
	//	Capture capture(fname);
	//}
	
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
	do{
		while(method != 'r' && method != 'R' && method != 'm' && method != 'M' && method != 'x' && method != 'X'){
			std::cout << "Press \"R\" to randomly inject bad data into the file.\n";
			std::cout << "Press \"M\" to manually change all values in a field to a constant.\n";
			std::cout << "Press \"X\" to quit selection.\n";
			std::cin >> method;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&	
		switch(method){
			case 'm':
			case 'M':
				while(std::cout << "\nEnter the number for the sensor you want to change: " && !(std::cin >> senseToChange)){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
		
				while(std::cout << "\nHow much would you like to change it by: " && !(std::cin >> amtToChange)){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				capture.ChangeValues(senseToChange, amtToChange);
				break;
			case 'r':
			case 'R':
				while(std::cout << "\n How many values would you like to randomly change?" && !(std::cin >> numberToChange)){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				capture.RandomChanges(numberToChange);
				break;
			default:
		
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
				std::cout << "Are you sure you want to quit? Press \"N\" to cancel.";
				std::cin >> repeat;
				break;
		}
		method = 'l';
	}while(repeat == 'n' || repeat == 'N');

	if(capture.UnusedSensors() != ""){
		std::cout << "Unused sensors are:\n";
		std::cout << capture.UnusedSensors();
	}
	capture.WriteFile("testout.csv");

	return 0;
}
