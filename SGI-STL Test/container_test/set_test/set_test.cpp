#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
void printSet(const set<T>& s)
{
	for (auto& n : s) {
		cout << n << " ";
	}

	cout << endl;
}

int main()
{
	// 默认初始化
	set<int> i;

	i.insert(8);
	i.insert(2);
	i.insert(5);

	printSet(i);

	// initializer_list 构造函数
	set<string> s{"why", "always", "me"};

	printSet(s);

	// 迭代器初始化器
	set<string> d(s.find("me"), s.end());

	printSet(d);

	// 复制构造函数
	set<string> c(s);

	printSet(c);

	// STL find

	if (find(c.begin(), c.end(), "me") != c.end()) {
		cout << "found " << endl;
	}

	c.erase("why");

	printSet(c);
	
	return 0;
}
