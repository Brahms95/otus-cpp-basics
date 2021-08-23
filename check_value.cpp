#include <iostream>
#include "check_value.h"
#include "random_value.h"

#define CHECHING_ERROR 0
#define CHECHING_OK 1
#define ONLY_TABLE 2

int checking_argc(int *argc,char* argv[], int *max_value){

	// Let's print this argument
	if (*argc > 0) {
		std::cout << "We have at least one argument!" << std::endl;
		std::cout << "argv[0] = " << argv[0]<< std::endl;
	}

	if (*argc == 2) {
	std::string arg1_value_table{ argv[1] };
		if (arg1_value_table == "–table"){
			return ONLY_TABLE;
		} 
	}

	// To check - does use print some other argument we should check if the argc >= 2
	if (*argc >= 2) {
		std::cout << "We have one more argument!" << std::endl;
		std::cout << "argv[1] = " << argv[1] << std::endl;
		std::string arg1_value{ argv[1] };
		if (arg1_value == "–max") {
			std::cout << "-parameter argument was detected!" << std::endl;

			// We've detected the '-parameter' argument. And we extect that after this argument there is a value:
	
			if (*argc < 3) {
				std::cout << "Wrong usage! The argument '-max' requires some value!" << std::endl;
				return CHECHING_ERROR;
			}
			// We need to parse the string to the int value
			*max_value = std::stoi(argv[2]);
			std::cout << "The '–max' value = " << *max_value << std::endl;
		}else if(arg1_value == "–level") {
			std::cout << "-parameter argument was detected!" << std::endl;

			// We've detected the '-parameter' argument. And we extect that after this argument there is a value:
			if (*argc < 3) {
				std::cout << "Wrong usage! The argument '–level' requires some value!" << std::endl;
				return CHECHING_ERROR;
			}
			*max_value = std::stoi(argv[2]);
			switch (*max_value){
			case 10:
				*max_value = 9;
				break;
			
			case 50:
				*max_value = 49;
				break;

			case 100:
				*max_value = 99;
				break;

			default:
				std::cout << "Wrong usage! The argument '–level' requires some value!";
				return CHECHING_ERROR;
			}

			std::cout << "The '–level' value = " << *max_value << std::endl;
		}
	
	}
	return CHECHING_OK;
}

int check_value(int *input_max_random, int &attempts_count) {
	
	int current_value = 0;
	int target_value = random_value(&input_max_random);
	bool not_win = true;

	std::cout << "Enter your guess:" << std::endl;

	do {
		std::cin >> current_value;
		if (std::cin.fail()) {
    		std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
    		std::cin.ignore(sizeof(int),'\n'); // и удаляем значения предыдущего ввода из входного буфера
			return CHECHING_ERROR;
		}
	else {		
		if (current_value < target_value) {
			attempts_count++;
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			attempts_count++;
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			attempts_count = attempts_count+1;
			std::cout << "you win!" << "attempts =" << attempts_count << std::endl;
			break;
		}
		}	
	} while(true);

	return CHECHING_OK;
}