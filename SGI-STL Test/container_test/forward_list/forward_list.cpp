#include <forward_list>
#include <iostream>
#include <algorithm>

using namespace std;

/***
 * slist 不是标准，C++11 加入 forward_list 容器，其为单链表
 */
template <typename T>
void printForward_list(forward_list<T>& fl)
{
	for (typename forward_list<T>::iterator it = fl.begin(); it != fl.end(); it++) {
		 cout << *it << " ";
	}

	cout << endl;
}

int main()
{
	forward_list<string> s{"why", "always", "me"};
	
	printForward_list(s);

	s.push_front("what");
	s.push_front("the");

	printForward_list(s);

	forward_list<string>::iterator it = find(s.begin(), s.end(), "always");

	if (it != s.end()) {
		s.erase_after(s.before_begin()); // 没有 erase 功能
	}
	
	printForward_list(s);
}
