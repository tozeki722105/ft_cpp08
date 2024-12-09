#include <iostream>
#include <string>
#include <vector>

#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 5; i++) {
		vec.push_back(i);
	}

	std::vector<int>::const_iterator ptr = easyfind(vec, vec[0]);
	if (ptr != vec.end()) {
		std::cout << "easyfind success: i=" << ptr - vec.begin() << std::endl;
	} else {
		std::cout << "easyfind fail" << std::endl;
	}

	int vecBeginVal = *(vec.begin());
	std::vector<int> vec2(vec.begin() + 1, vec.end());

	ptr = easyfind(vec2, vecBeginVal);
	if (ptr != vec2.end()) {
		std::cout << "easyfind success: i=" << ptr - vec2.begin() << std::endl;
	} else {
		std::cout << "easyfind fail" << std::endl;
	}
}