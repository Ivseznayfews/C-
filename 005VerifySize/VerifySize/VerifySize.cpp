#include <iostream>

int main() {
	std::cout << "char: " << sizeof(char) << "字节\n";
	std::cout << "short: " << sizeof(short) << "字节\n";
	std::cout << "int: " << sizeof(int) << "字节\n";
	std::cout << "long long: " << sizeof(long long) << "字节\n";
	std::cout << "float: " << sizeof(float) << "字节\n";
	std::cout << "double: " << sizeof(double) << "字节\n";
	std::cout << "bool: " << sizeof(bool) << "字节\n";

	return 0;
}