#include <iostream>
#include <string>
#include <list>

using namespace std;

/***
 * list 的操作 
 */
template <typename T>
void printList(const list<T>& l)
{
	for (auto n : l) {
		cout << n << " ";
	}

	cout << endl;
}

int main()
{	
	// 构造函数
	list<string> list1{"why", "always", "me", "!"};
	printList(list1);

	list<string> list2(list1.begin(), list1.end());
	printList(list2);

	list<string> list3(list1);
	printList(list3);

	list<string> list4(4, "you");
	printList(list4);

	// operator=
	list<string> list5 = list1;
	printList(list5);
	
	// assign
	list<string> list6;
	list6.assign(5, "mo");
	printList(list6);
	
	list<string> list7;
	list7.assign(list1.begin(), list1.end());
	printList(list7);
	
	// front 
	cout << "front() = " << list1.front() << endl;

	// back
	cout << "back() = " << list1.back() << endl;

	// begin, end
	for (list<string>::iterator it = list1.begin(); it != list1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	for (list<string>::reverse_iterator it = list1.rbegin(); it != list1.rend(); it++) {
		cout << *it << " "; 
	}
	cout << endl;
	
	// empty
	if (list1.empty()) {
		cout << "list1 is empty!" << endl;
	} else {
		cout << "list1 isn't empty!" << endl;
	}

	// size
	cout << "size() = " << list1.size() << endl;

	// max_size
	cout << "max_size() = " << list1.max_size() << endl;

	// clear
	list7.clear();
	printList(list7);

	// insert
	list7.insert(list7.begin(), "hello");
	printList(list7);
	
	list7.insert(list7.begin(), 2, "no");
	printList(list7);

	list7.insert(list7.begin(), list6.begin(), list6.end());	
	printList(list7);

	// erase
	list7.erase(list7.begin());
	printList(list7);

	list<string>::iterator range_begin = list7.begin();
	list<string>::iterator range_end = list7.begin();
	advance(range_begin, 2);
	advance(range_end, 5);

	list7.erase(range_begin, range_end);
	printList(list7);

	// push_back
	list7.push_back("12");
	printList(list7);

	//pop_back
	list7.pop_back();
	printList(list7);

	// push_front
	list7.push_front("12");
	printList(list7);

	// pop_front
	list7.pop_front();
	printList(list7);
	
	// resize
	list<int> list8 = {1, 2, 3};
	printList(list8);

	list8.resize(5);
	printList(list8);

	// swap
	list7.swap(list6);
	printList(list6);
	printList(list7);

	// sort
	list<int> list9 = {7, 4, 2, 1, 5};
	list<int> list10 = {2, 3, 4, 6, 10};
	list9.sort();
	list10.sort();

	// merge
	list9.merge(list10);
	printList(list9);

	// splice
	list<int> list11 = {1, 4, 5, 6, 8};
	list<int> list12 = {3, 1, 5, 2, 9};

	auto it = list11.begin();
	advance(it, 2);

	list11.splice(it, list12);
	printList(list11);
	printList(list12);

	list12.splice(list12.begin(), list11, it, list11.end());
	printList(list11);
	printList(list12);

	// remove
	list12.remove(5);
	printList(list12);

	// reverse
	list12.reverse();
	printList(list12);

	// unique
	list11.unique();
	printList(list11);

	return 0;
}


