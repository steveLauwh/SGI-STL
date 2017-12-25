#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	const int arrSize = sizeof(arr) / sizeof(arr[0]);

	// vector 容器
	vector<int> ivect(arr, arr + arrSize);

	// list 容器
	list<int> ilist(arr, arr + arrSize);

	// deque 容器
	deque<int> ideque(arr, arr + arrSize);

	/***
	 * 通过不同的迭代器，算法 find 对不同的容器进行查找操作 
	 */
	vector<int>::iterator itv = find(ivect.begin(), ivect.end(), 4);
	if (itv == ivect.end()) {
		cout << " The value 4 not found in the vector" << endl;
	} else {
		cout << " The value 4 found in the vector -> " << *itv << endl;
	}

	list<int>::iterator itl = find(ilist.begin(), ilist.end(), 5);
	if (itl == ilist.end()) {
		cout << " The value 5 not found in the list" << endl;
	} else {
		cout << " The value 5 found in the list -> " << *itl << endl;
	}

	deque<int>::iterator itd = find(ideque.begin(), ideque.end(), 6);
	if (itd == ideque.end()) {
		cout << " The value 6 not found in the deque" << endl;
	} else {
		cout << " The value 6 found in the deque -> " << *itd << endl;
	}
	
	return 0;
}
