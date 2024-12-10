#include <iostream>

#include "Span.hpp"

int main()
{
	// min/maxテスト
	{
		try {
			Span span(100);
			span.addNumber(INT_MIN, 99, 1);
			span.addNumber(INT_MAX);
			std::cout << "shortest: " << span.shortestSpan() << std::endl
					  << "longest: " << span.longestSpan() << std::endl;
			// span.addNumber(100); // 例外が投げられる
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;

	// 同値が入る時のテスト
	{
		try {
			Span span(100);
			span.addNumber(1, 99, 1);
			span.addNumber(1);
			std::cout << "shortest: " << span.shortestSpan() << std::endl
					  << "longest: " << span.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
}