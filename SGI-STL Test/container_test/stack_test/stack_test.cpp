#include <iostream>
#include <stack>
#include <deque>
#include <list>

using namespace std;

template <typename T>
void printStack(stack<T>& s)
{
	int stack_size = s.size();

	for (int i = 0; i < stack_size; i++) {
		cout << s.top() << " ";

		s.pop();
	}

	cout << endl;
}

template <typename T>
void printlistStack(stack<T, list<T> >& s)
{
	int stack_size = s.size();
	for (int i = 0; i < stack_size; i++) {
		cout << s.top() << " ";

		s.pop();
	}

	cout << endl;
}

int main()
{
	// 默认以 deque 为底层容器
	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);

	cout << "size = " << s.size() << endl;

	printStack(s);

	// 以 list 为底层容器
	stack<int, list<int> > istack;
	
	istack.push(5);
	istack.push(6);
	istack.push(7);

	cout << "istack size = " << istack.size() << endl;

	printlistStack(istack);
	
	return 0;
}
