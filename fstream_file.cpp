#include "fstream_file.h"
 	
#include <iostream>
#include <map>

static const std::string high_scores_filename = "high_scores.txt";

//для вывода таблицы
int table_request(){

	std::ifstream in_file{high_scores_filename};
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		std::cout << "High scores table:" << std::endl;
//здесь проверяется кол-во попыток ,если в файле одно и тоже имя ,выбирается min
		std::map <std::string, int> table ;	
		std::map <std::string, int> ::iterator it ;
		std :: string first_name = "";
		int number = 0;

		while (true) {
			// Read thtable_request username first
			in_file >> first_name;
			
			// Read the high score next
			in_file >> number;
						
			it = table.find(first_name);

  			if (it== table.end()){
				table.insert ( make_pair(first_name,number) );
				in_file.ignore();
				if (in_file.fail()) {
					break;	
				}
				continue;
			  }
    		
			if (it->second > number)
				table[first_name]=number;
			in_file.ignore();
			if (in_file.fail()) {
			break;	
			}
		}
///вывод не явно инициализированной map на экран
  	for (auto it = table.begin(); it != table.end(); ++it){
      std::cout << it->first  << " : " << it->second  << std::endl;
  	}		
	return 1;
}
	
int ofstream_file( std::string &user_name, int &attempts_count){// Write new high score to the records table
	/*Перед записью в файл провер ,есть он вообще и тогда добавляем первоезначение ( то если так не сделать ,то выводит ккой-то бред , или я не так делала)*/
	std::ifstream open_file(high_scores_filename);
	if (!open_file.good()){
		std::ofstream out_file_first{high_scores_filename};
	if (!out_file_first.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		return -1;
	}
		out_file_first << user_name << ' ';
		out_file_first << attempts_count;

		out_file_first.close();
		table_request();
		return 1;
		}

	std::ifstream out_file{high_scores_filename};
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		return -1;
		}

	else{
	//узнаем колличества строк в файле
		char *str = new char [1024];
 		int line=0;

    	while (!out_file.eof())
    	{
        	out_file.getline(str, 1024, '\n');
        	line++;
    	}
		//std::cout << "Line: " << line << std::endl;


		out_file.clear();
		out_file.seekg(0, std::ios::beg);

		std::string*  username = new std::string [line];
		int* high_score= new int[line];
		for (int index=0; index<line; index++){
			out_file >> username[index];
			out_file >> high_score[index];

			out_file.ignore();
			if (out_file.fail()) {
				break;
			}
		}	
	out_file.close();
	std::ofstream ate_file{high_scores_filename};
	if (!ate_file.is_open()) {
		std::cout << "Failed to open file for ate: " << high_scores_filename << "!" << std::endl;
		return -1;
		}
	bool flag_write =true;

	for (int index=0; index<line; index++){
	//переписываем на лучший рещультат
		if (username[index]==user_name &&  high_score[index] > attempts_count) {
			high_score[index]=attempts_count;
			flag_write =false;
		}	
	}
	for (int index=0; index<line; index++){
		ate_file << username[index] << ' ';
		ate_file << high_score[index];
		if (index != line-1)
			ate_file << std::endl;
		}
		if (flag_write){
		ate_file << std::endl;
		ate_file << user_name << ' ';
		ate_file << attempts_count;
	}	

	ate_file.close();
	}	
	
	table_request();	
	return 1;		
}