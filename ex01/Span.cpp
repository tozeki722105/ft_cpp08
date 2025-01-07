#include "Span.hpp"

#include <algorithm>
#include <iostream>

Span::Span(unsigned int maxSize) : _maxSize(maxSize) {}

Span::~Span() {}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	_maxSize = other._maxSize;
	_vec = other._vec;
	return *this;
}

void Span::addNumber(int n, size_t len, int val_step)
{
	for (size_t i = 0; i < len; i++) {
		if (_vec.size() == _maxSize)
			throw std::length_error("Span is full");
		_vec.push_back(n);
		n += val_step;
	}
}

unsigned int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw std::logic_error("Not enough elements to calculate shortest span");

	std::vector<int> sortedData = _vec;
	std::sort(sortedData.begin(), sortedData.end());

	// if (std::adjacent_find(sortedData.begin(), sortedData.end()) != sortedData.end())
	// 	return 0;

	unsigned int res = UINT_MAX;
	unsigned int newSpan;
	std::vector<int>::iterator i = sortedData.begin();
	for (std::vector<int>::iterator next = i + 1; next != sortedData.end(); next++) {
		newSpan = static_cast<unsigned int>(*next - *i);
		if (newSpan == SPAN_MIN)
			return newSpan;
		if (newSpan < res)
			res = newSpan;
		i = next;
	}
	return res;
}

unsigned int Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw std::logic_error("Not enough elements to calculate longest span");

	int min = *(std::min_element(_vec.begin(), _vec.end()));
	int max = *(std::max_element(_vec.begin(), _vec.end()));
	return static_cast<unsigned int>(max - min);
}