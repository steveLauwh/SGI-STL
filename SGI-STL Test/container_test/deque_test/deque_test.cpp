#include <deque>
#include <iostream>
#include <string>

using namespace std;

// g++ deque_test.cpp -o deque_test -std=c++11
template <typename T>
void printDeque(const deque<T>& deq)
{
	for (auto n : deq) {
		cout << n << " ";
	}

	cout << endl;
}

int main()
{
	// deque 构造函数
	deque<string> words1{"The", "is", "deque"};
	printDeque(words1);

	deque<string> words2(words1.begin(), words1.end());
	printDeque(words2);

	deque<string> words3(words1);
	printDeque(words3);

	deque<string> words4(5, "YES");
	printDeque(words4);
	
	// front
	cout << words1.front() << endl;

	// back
	cout << words1.back() << endl;

	// size
	cout << "words contains : " << words4.size() << endl;

	// push_back
	words4.push_back("NO");
	printDeque(words4);

	// pop_back
	words4.pop_back();
	printDeque(words4);

	// push_front
	words4.push_front("SS");
	printDeque(words4);

	// pop_front
	words4.pop_front();
	printDeque(words4);

	// erase
	words4.erase(words4.begin());
	printDeque(words4);

	words1.erase(words1.begin()+2, words1.end());
	printDeque(words1);

	// insert
	words1.insert(words1.begin()+1, words4.begin(), words4.end());
	printDeque(words1);

	words1.insert(words1.begin()+3, "strat");
	printDeque(words1);

	words1.insert(words1.begin()+3, 5, "IS");
	printDeque(words1);
	
	// iterator
	for (deque<string>::iterator it = words1.begin(); it != words1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	// reverse_iterator
	for (deque<string>::reverse_iterator it = words1.rbegin(); it != words1.rend(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}

