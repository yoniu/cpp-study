#include <iostream>
#include "echo.h"
#define ECHO(T) std::cout << T << std::endl;

void increament(int& value) {
	value++;
}

int main2() {
	int a = 0;
	increament(a);
	ECHO(a);
	std::cin.get();
	return 0;
}