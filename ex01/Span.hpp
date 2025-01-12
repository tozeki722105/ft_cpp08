#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <climits>
#include <cstddef>

class Span
{
public:
	Span(unsigned int maxSize);
	~Span();
	Span(const Span& other);
	Span& operator=(const Span& other);
	void addNumber(int n, size_t len = 1, int val_step = 1);
	unsigned int shortestSpan();
	unsigned int longestSpan();

private:
	Span();
	std::vector<int> _vec;
	unsigned int _maxSize;
	static const unsigned int SPAN_MIN = 0;
};

#endif