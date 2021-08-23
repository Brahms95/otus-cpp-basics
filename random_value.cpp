

#include <cstdlib>
#include <ctime>
#include "fstream_file.h"
int random_value(int** max_value) {
	
if (**max_value==0){
	**max_value = 100;
}
	//const int max_value = **_max_value;

	std::srand(std::time(nullptr)); // use current time as seed for random generator

	const int random_value = std::rand() % **max_value;

	std::cout << "random_value " << random_value << std::endl;

	return random_value;
}