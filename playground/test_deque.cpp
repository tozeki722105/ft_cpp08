#include <deque>
#include <iostream>

int main()
{
	std::deque<int> deq;
	for (int i = 0; i < 5; i++) {
		deq.push_back(i);
	}
	std::cout << *deq.begin() << std::endl;
	std::cout << *deq.rbegin() << std::endl;
	// std::cout << *deq.end() << std::endl;
	// std::cout << *deq.rend() << std::endl;
}