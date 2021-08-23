#include <iostream>
#include <fstream>
#include <string>
#include "check_value.h"
#include "fstream_file.h"
#include <limits>

#define MAIN_OK 1
#define MAIN_ERROR 0
#define MAIN_TABLE 2


int main(int argc, char *argv[]) {

int input_max_value = 0;
unsigned int _result_checking_argc= 0;

_result_checking_argc = checking_argc(&argc,argv, &input_max_value);
if (_result_checking_argc == MAIN_ERROR){return -1;}
if (_result_checking_argc == MAIN_TABLE) {
	table_request(); 
	return MAIN_OK;
}

	// Ask about name
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

	// Get the last high score
	std::cout << "Enter your high score:" << std::endl;
	int expected_attempts_count = 0;
	int attempts_count = 0;

	unsigned int number_of_attempts=  0;
/*Проверка на ввод типа int, всего 3 попытки */
	while (number_of_attempts <=3){

		std::cin >> expected_attempts_count;
		if (std::cin.fail()) {
			if (number_of_attempts==3) return -1;
			else{
				number_of_attempts ++;
				std::cout << "Bad value!" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				std::cout << "You have " << number_of_attempts<< " more attempts!" << std::endl;
			}
		}
		else break;
	}
	
if (MAIN_ERROR == check_value(&input_max_value, attempts_count))
	return MAIN_ERROR;

ofstream_file(user_name, attempts_count);	

return MAIN_OK;
}