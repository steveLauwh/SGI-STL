#include <iostream>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

template <class T>
void myReverse(T first, T last)
{
	typename iterator_traits<T>::difference_type n = distance(first, last);

	--n; 

	// 首尾交换
	while (n > 0) {
		typename iterator_traits<T>::value_type temp = *first;
		*first++ = *--last;
		*last = temp;

		n -= 2;
	}
}

int main(int argc, char *argv[]) 
{
	vector<int> v{1, 2, 3, 4, 5, 6};
	myReverse(v.begin(), v.end());
	for (auto n : v) {
		cout << n << " ";
	}

	cout << endl;


	list<int> l{1, 2, 3, 4, 5, 6};
	myReverse(l.begin(), l.end());
	for (auto n : v) {
		cout << n << " ";
	}

	cout << endl;

	return 0;
}
