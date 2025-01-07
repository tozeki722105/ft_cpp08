#include <iostream>
#include <stack>

#include "MutantStack.hpp"

void checkLeaks()
{
	system("leaks -q ex02");
}

int main()
{
	atexit(checkLeaks);  // 処理の頭に呼び出す
	// stackと同じ挙動かテスト
	{
		std::stack<int> stack;
		stack.push(5);
		stack.push(17);
		stack.pop();
		stack.push(3);
		stack.push(5);
		stack.push(737);  //[...] stack.push(0);
		while (stack.size()) {
			std::cout << stack.top() << std::endl;
			stack.pop();
		}

		std::cout << std::endl;

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.pop();
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);  //[...] mstack.push(0);
		while (mstack.size()) {
			std::cout << mstack.top() << std::endl;
			mstack.pop();
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;

	// // iterator_test
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.pop();
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		MutantStack<int>::container_type::iterator begin = mstack.begin();
		MutantStack<int>::container_type::iterator end = mstack.end();
		++end;
		--end;
		while (begin != end) {
			std::cout << *begin << std::endl;
			++begin;
		}
	}
	std::cout << "\nend\n" << std::endl;
}