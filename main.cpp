#include <stdio.h>
#include <iostream>
#include <string>
#include <chrono>

int main() {

	std::string a(1000000, 'a');
	std::string b(1000000, 'b');
	std::string c(1000000, 'c');

	auto copyStart = std::chrono::high_resolution_clock::now();
	c = a;
	auto copyEnd = std::chrono::high_resolution_clock::now();
	auto copyDuration = std::chrono::duration_cast<std::chrono::microseconds>(copyEnd - copyStart);


	auto moveStart = std::chrono::high_resolution_clock::now();
	b = std::move(a);
	auto moveEnd = std::chrono::high_resolution_clock::now();
	auto moveDuration = std::chrono::duration_cast<std::chrono::microseconds>(moveEnd - moveStart);
	
	std::cout << "1000000�������ړ��ƃR�s�[�Ŕ�r���܂����B\n�R�s�[: " << copyDuration.count() << " ��s\n" << "�ړ��F" << moveDuration.count() << " ��s\n" << std::endl;

	return 0; }