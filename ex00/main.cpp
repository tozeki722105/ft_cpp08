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

	std::vector<int>::iterator it = easyfind(vec, vec[0]);
	if (it != vec.end()) {
		std::cout << "easyfind success: i=" << it - vec.begin() << std::endl;
	} else {
		std::cout << "easyfind fail" << std::endl;
	}

	int vecBeginVal = *(vec.begin());
	const std::vector<int> vec2(vec.begin() + 1, vec.end());

	std::vector<int>::const_iterator con_it = easyfind(vec2, vecBeginVal);
	if (con_it != vec2.end()) {
		std::cout << "easyfind success: i=" << con_it - vec2.begin() << std::endl;
	} else {
		std::cout << "easyfind fail" << std::endl;
	}
}