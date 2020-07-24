#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iterator>
#include <fstream>
#include <sstream>

typedef uint8_t byte;

constexpr auto ARRAY_SIZE = 3000;


int interpret(std::string& code, std::array<byte, ARRAY_SIZE>& array){
	auto iterator = std::begin(array);	
	int brackets_loop{0};
	for(auto action_it {std::begin(code)}; action_it != std::end(code); action_it++){
		switch(*action_it){
			case '+':
				(*iterator)++;
				break;
			case '-':
				(*iterator)--;
				break;
			case '>':
				iterator++;
				break;
			case '<':
				iterator--;
				break;
			case '.':
				std::cout << static_cast<char>(*iterator);
				break;
			case ',':
				int input;
				std::cin >> input;
				*iterator = input;
				break;
			case '[':
				if(*iterator == 0){
					std::advance(action_it, 1);
					while(brackets_loop > 0 || *action_it != ']'){
						if(*action_it == '['){brackets_loop++;}
						if(*action_it == ']'){brackets_loop--;}
						std::advance(action_it, 1);
					}
				}
				break;
			case ']':
				if(*iterator!=0){
					std::advance(action_it, -1);
					while(brackets_loop > 0 || *action_it != '['){
						if(*action_it == ']'){brackets_loop++;}
						if(*action_it == '['){brackets_loop--;}
						std::advance(action_it, -1);						
					}
					std::advance(action_it, -1);	
				}

				break;
		}

	}
	return 0;

}	

int main(int argc, char* argv[]){
	using namespace std::string_literals;
        	
	if(argc < 2){
		throw std::runtime_error("ArgError: Expecting the file path");
	}
	std::ifstream file{argv[1]};
	std::string line;
	std::string bf_code;
	while(std::getline(file,line)){
		bf_code += line;
	}
	//Definition of the cells array 
	std::array<byte, ARRAY_SIZE> array;
	array.fill(0);	
	
	interpret(bf_code, array);

	std::cout << std::endl;
	
	return 0;
}
