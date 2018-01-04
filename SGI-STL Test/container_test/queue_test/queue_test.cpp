#include <queue>
#include <iostream>
#include <list>

using namespace std;

template <typename T>
void printQueue(queue<T>& q) 
{
	int queue_size = q.size();

	for (int i = 0; i < queue_size; i++) {
		cout << q.front() << " ";
		q.pop();
	}

	cout << endl;
}

template <typename T>
void printlistQueue(queue<T, list<T> >& q) {
	int queue_size = q.size();

	for (int i = 0; i < queue_size; i++) {
		cout << q.front() << " ";
		q.pop();
	}

	cout << endl;
}

int main()
{
	// 默认以 queue 为底层容器
	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);

	cout << "size = " << q.size() << endl;

	printQueue(q);

	// 以 list 为底层容器
	queue<string, list<string> > iq;
	
	iq.push("why");
	iq.push("always");
	iq.push("me");

	cout << "iq size = " << iq.size() << endl;

	printlistQueue(iq);

}
