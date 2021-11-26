#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <array>

#include "Fraction.h"

template<typename T>
T calcPercentage(const T& a, const T& b) {
	return (a * 100) / b;
}

template<typename T1, typename T2> std::string concatValues(const T1& a, const T2& b) {
	std::ostringstream out;
	out << a << b;
	return out.str();
}

template<typename T1, typename T2> void printValues(const T1& a, const T2& b) {
	std::cout << concatValues(a, b) << std::endl;
}

template<typename T>
void swapValues(T& a, T& b) {
	T aBeforeSwap = a;
	a = b;
	b = aBeforeSwap;
}

bool isFraction(const std::string& first) {
	if (first.find('/') != std::string::npos) {
		return false;
	}
	return true;
}

void printFraction(const std::string& first, const std::string& second) {
	const char separator = '/';
	std::istringstream istr(first + '/' + second);
	std::istringstream out;
	std::array<int, 4> fracNumbers;
	std::string currNumberStr;
	int number = 0;
	for (int i = 0; i < 4; ++i) {
		getline(istr, currNumberStr, separator);
		out.str(currNumberStr);
		out >> number;
		fracNumbers[i] = number;
		out.str("");
		out.clear();
	}
	std::string text = first + " out of " + second + " = ";
	printValues(text, concatValues(calcPercentage(Fraction{fracNumbers[0], fracNumbers[1]},
												  Fraction{ fracNumbers[2], fracNumbers[3]}), "%"));
}

void printNumber(const std::string& first, const std::string& second) {
	double firstNum = 0;
	double secondNum = 0;
	std::istringstream istr(first + " " + second);
	std::string text = first + " out of " + second + " = ";
	istr >> firstNum >> secondNum;
	printValues(text, concatValues(calcPercentage(firstNum, secondNum), "%"));
}
#endif // !OPERATIONS_H

