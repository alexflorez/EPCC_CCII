#include <iostream>

bool passOrFail() {
	static int passes = 3;
	--passes;
	return (passes >= 0);
}

int main() {
	std::cout << "1: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "2: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "3: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "4: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "5: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "6: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "7: " << (passOrFail() ? "Pass\n" : "Fail\n");

	return 0;
}
