#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
void printHeap(vector<T>& ivec)
{
	for (int i = 0; i < ivec.size(); i++) {
		cout << ivec[i] << " ";
	}

	cout << endl;
}

template <typename T>
void printArray(T arr[], size_t size)
{
	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

int main()
{
	// heap 底层使用 vector 容器
	vector<int> iv{1, 5, 9, 3, 2, 0, 4};
	
	// 调整为 heap
	make_heap(iv.begin(), iv.end());

	printHeap(iv);

	// 对 vector 尾部插入 8
	iv.push_back(8);

	// 新插入 8，对 heap 重新调整
	push_heap(iv.begin(), iv.end());

	printHeap(iv);
	
	// 将 vector 的首元素放到尾端
	pop_heap(iv.begin(), iv.end());

	// vector 的操作
	cout << iv.back() << endl;

	iv.pop_back();

	printHeap(iv);

	// 对 heap 排序
	sort_heap(iv.begin(), iv.end());

	printHeap(iv);

	// heap 底层使用 array 数组
	int arr[] = {12, 34, 15, 63, 17};

	make_heap(arr, arr+5);  // array 大小一定，不能做 push_back 操作

	size_t arr_size = sizeof(arr) / sizeof(arr[0]);

	printArray(arr, arr_size);
	
    // 对 heap 排序
	sort_heap(arr, arr+5);

	printArray(arr, arr_size);
}
