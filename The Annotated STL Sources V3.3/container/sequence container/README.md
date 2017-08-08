## vector

* vector 与 array 唯一区别是空间的运用的灵活性。
* array 是静态空间，一旦配置了就不能改变。
* vector 维护的是一个连续线性空间，所以不论其元素类型为何，普通指针都可以作为 vector 的迭代器而满足所有必要条件。
* 增加新元素，如果超过当时的容量，则容量会扩充至两倍。

```cpp
vector<int>::iterator ivite;   // ivite 的类型就是 int*
vector<Shape>::iterator svite; // svite 的类型就是 Shape*
```

<stl_vector.h> 会调用 <stl_bvector.h> 的函数。

**vector 动态增加大小的实现原理 M_insert_aux 函数**

所谓动态增加大小，并不是在原空间之后接续新空间(因为无法保证原空间之后尚有可供配置的空间)，而是以原大小的两倍另外配置一块较大空间，然后将原内容拷贝过来，
然后才开始在原内容之后构造新元素，并释放原空间。因此，对 vector 的任何操作，一旦引起空间重新配置，指向原 vector 的所有迭代器就都失效了。

vector 只能尾端增加空间，三部曲：

* 配置一块更大空间
* 将原内容拷贝过去
* 释放原空间

vector 的基本操作

`push_back`：插入操作(末尾)

`pop_back`：删除操作(末尾)

`erase`：清除某范围 `[first, last)` 元素，或删除某个位置上的元素

`insert`：从某个位置，插入 n 个元素，元素初值为x

`clear`：清除所有元素

## list

STL list 是一个双向链表，迭代器必须具备前移、后移的能力，所以 list 提供的是 Bidirectional Iterator。

只要刻意在环状链表的尾端加上一个空白节点，便符合 STL 规范之 “前闭后开” 区间。

`push_back`：将新元素插入到 list 尾端

`insert`：插入是指 插入在...之前，插入完成后，新节点将位于标示出插入点所指之节点的前方。

list 的元素操作。

## deque

deque 是一种双向开口的连续线性空间。可以在头尾两端分别做元素的插入和删除操作。

deque 和 vector 的差异：第一，deque 允许于常数时间内对起头端进行元素的插入或移除操作；第二，deque 没有容量，它是动态地以分段连续空间组合而成。

deque 由一段段的定量连续空间构成。一旦有必要在 deque 的前端或尾端增加新空间，便配置一段定量连续空间，串接在整个 deque 的头端或尾端。

deque 实现复杂，复杂的迭代器架构。


