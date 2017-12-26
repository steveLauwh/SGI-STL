#include <iostream>
#include <vector>

using namespace std;

/**
 * vector 的操作
 */
template <typename T>
void printVector(const vector<T>& vec)
{
	for (auto x : vec) {
		cout << x << " ";
	}

	cout << endl;
}

int main()
{
	// 构造函数:四种形式
	vector<string> iv(2, "hi");
	printVector(iv);

	vector<string> sv{"why", "always", "me"};
	printVector(sv);

	vector<string> sv2(sv.begin(), sv.end());
	printVector(sv2);

	vector<string> sv3(sv);
	printVector(sv3);

	// operator= 赋值运算符
	vector<string> sv4;
	sv4 = sv;
	printVector(sv4);

	// assign
	vector<char> cv;
	cv.assign(5, 'x');
	printVector(cv);
	
	vector<char> cv1;
	cv1.assign(cv.begin(), cv.end());
	printVector(cv1);

	// at(索引)
	cout << cv1.at(1) << endl;

	// operator[] 
	cv1[1] = 'a';
	printVector(cv1);

	// front 容器首元素
	cout << sv.front() << endl;
	
	// back 容器最后一个元素
	cout << sv.back() << endl;

	// begin 返回指向容器第一个元素的迭代器
	// end 返回指向容器尾端的迭代器
	for (vector<string>::iterator it = sv.begin(); it != sv.end(); it++) {
		cout << *it << " ";	
	}
	cout << endl;

	// rbegin 返回一个指向容器最后一个元素的反向迭代器 
	// rend 返回一个指向容器前端的反向迭代器
	for (vector<string>::reverse_iterator it = sv.rbegin(); it != sv.rend(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	// empty 若容器为空则为 true ，否则为 false
	if (sv.empty()) {
		cout << "container is null." << endl;
	} else {
		cout << "container is not null." << endl;
	}

	// size	容器中的元素个数
	cout << sv.size() << endl;

	// max_size 元素数量的最大值
	cout << sv.max_size() << endl;

	// capacity 当前分配存储的容量
	cout << sv.capacity() << endl;

	// resize 改变容器中可存储元素的个数 
	sv.resize(10);
	cout << sv.capacity() << endl;
	
	// shrink_to_fit 请求移除未使用的容量
	sv.shrink_to_fit();
	cout << sv.capacity() << endl;

  	// clear 从容器移除所有元素
	iv.clear();
	printVector(iv);

	// insert:三种形式
	auto it = sv.begin();
	it = sv.insert(it, "YES");
	printVector(sv);
	
	sv.insert(it, 2, "NO");
	printVector(sv);

	it = sv.begin();
	vector<string> sv5(2, "xx");
	sv.insert(it+2, sv5.begin(), sv5.end());
	printVector(sv);

	// erase 从容器移除指定的元素
	sv.erase(sv.begin());
	printVector(sv);
	
	sv.erase(sv.begin() + 2, sv.begin() + 4);
	printVector(sv);
	
	// push_back 向容器尾部插入元素
	cout << sv.size() << endl;
	sv.push_back("add");
	printVector(sv);

	// pop_back 移除容器的最末元素
	sv.pop_back();
	printVector(sv);
	
	// swap
	sv.swap(sv5);
	printVector(sv);
	printVector(sv5);

	return 0;
}

