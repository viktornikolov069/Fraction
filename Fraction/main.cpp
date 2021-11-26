#include <iostream>
#include "Operations.h"


int main() {
	
	std::string first;
	std::string second;
	
	while (true) {
		std::cout << "First: ";
		std::cin >> first;
		std::cout << "Second: ";
		std::cin >> second;
		
		if (!isFraction(first)) {
			printFraction(first, second);
		} else {
			printNumber(first, second);
		}
		std::cout << std::endl;
		
	}
}