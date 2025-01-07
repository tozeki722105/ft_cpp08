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
	typedef typename std::stack<T>::container_type::iterator Iter;
	typedef typename std::stack<T>::container_type::const_iterator CONST_Iter;
	typedef typename std::stack<T>::container_type::reverse_iterator RIter;
	typedef typename std::stack<T>::container_type::const_reverse_iterator CONST_RIter;

public:
	MutantStack() {}
	virtual ~MutantStack() {}
	MutantStack(const MutantStack<T> &other);
	MutantStack<T> &operator=(const MutantStack<T> &other);

	Iter begin() { return this->c.begin(); }
	Iter end() { return this->c.end(); }

	CONST_Iter begin() const { return this->c.begin(); }
	CONST_Iter end() const { return this->c.end(); }

	RIter rbegin() { return this->c.rbegin(); }
	RIter rend() { return this->c.rend(); }

	CONST_RIter rbegin() const { return this->c.rbegin(); }
	CONST_RIter rend() const { return this->c.rend(); }
};

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

#endif