#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
	string s = "AdapterTest";

	reverse_iterator<string::iterator> r = s.rbegin();

	string rev(r, s.rend());

	cout << rev << "\n";

	vector<int> v1{1, 5, 16, 8};

	fill_n(back_inserter(v1), 3, -1); // 用于添加元素到容器的尾部
	for (auto n : v1) {
		cout << n << " ";
	}
	cout << "\n";

	deque<int> v2{1, 5, 16, 8};
	fill_n(front_inserter(v2), 3, -1);  // 用于添加元素到容器的起始
	for (auto n : v2) {
		cout << n << " ";
	}

	return 0;
}


