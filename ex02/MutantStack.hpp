#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

// namespace example
// {
// template <typename T>
// class Stack : public std::deque<T>
// {
// public:
// 	typedef std::deque<T> container_type;

// protected:
// 	std::deque<T> c;  // container_data
// };
// }  // namespace example

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator MSIterator;
	typedef typename std::stack<T>::container_type::reverse_iterator MSRIterator;

	MutantStack();
	virtual ~MutantStack();
	MutantStack<T> &operator=(const MutantStack<T> &other);
	MutantStack(const MutantStack<T> &other);

	MSIterator begin();
	MSIterator end();
	MSRIterator rbegin();
	MSRIterator rend();
};

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	if (this == &other)
		return *this;
	std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend()
{
	return this->c.rend();
}

#endif