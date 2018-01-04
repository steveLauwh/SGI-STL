#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
void printPQueue(priority_queue<T>& ipq)
{
	while (!ipq.empty()) {
		cout << ipq.top() << " ";
		ipq.pop();
	}

	cout << endl;
}

int main()
{
	vector<int> iv{4, 8, 9, 7, 32, 12};

	// priority_queue 构造函数，调整为 heap
	priority_queue<int> ipq(iv.begin(), iv.end());

	cout << "ipq size = " << ipq.size() << endl;

	printPQueue(ipq); // 调用完后，容器为空

	cout << "ipq size = " << ipq.size() << endl;

	// 向容器尾端插入元素，会重新调整
	ipq.push(1);
	ipq.push(100);
	ipq.push(12);
	ipq.push(44);

	cout << "ipq insert size = " << ipq.size() << endl;

	printPQueue(ipq);
	
	return 0;
}
