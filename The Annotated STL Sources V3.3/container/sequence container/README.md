## [vector](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/sequence%20container/vector)

* vector 与 array 唯一区别是空间的运用的灵活性。
* array 是静态空间，一旦配置了就不能改变。
* vector 维护的是一个连续线性空间，所以不论其元素类型为何，普通指针都可以作为 vector 的迭代器而满足所有必要条件。
* 增加新元素，如果超过当时的容量，则容量会扩充至两倍。
* <stl_vector.h> 会调用 <stl_bvector.h> 的函数。

```cpp
vector<int>::iterator ivite;   // ivite 的类型就是 int*
vector<Shape>::iterator svite; // svite 的类型就是 Shape*
```

**vector 动态增加大小的实现原理 M_insert_aux 函数：**

所谓动态增加大小，并不是在原空间之后接续新空间(因为无法保证原空间之后尚有可供配置的空间)，而是以原大小的两倍另外配置一块较大空间，然后将原内容拷贝过来，
然后才开始在原内容之后构造新元素，并释放原空间。因此，对 vector 的任何操作，一旦引起空间重新配置，指向原 vector 的所有迭代器就都失效了。

**vector 只能尾端增加空间，三部曲：**

* 配置一块更大空间
* 将原内容拷贝过去
* 释放原空间

**vector 的基本操作：**

`push_back()`：插入操作(末尾)

`pop_back()`：删除操作(末尾)

`erase()`：清除某范围 `[first, last)` 元素，或删除某个位置上的元素

`insert()`：从某个位置，插入 n 个元素，元素初值为x

`clear()`：清除所有元素

## [list](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/sequence%20container/list)

* STL list 是一个双向链表，迭代器必须具备前移、后移的能力，所以 list 提供的是 Bidirectional Iterator。
* 只要刻意在环状链表的尾端加上一个空白节点，便符合 STL 规范之 “前闭后开” 区间。

**list 的元素操作：**

`push_front()`：插入一个节点，作为头节点

`push_back()`：将新元素插入到 list 尾端

`pop_front()`：移除头节点

`pop_back()`：移除尾节点

`insert()`：插入是指 插入在...之前，插入完成后，新节点将位于标示出插入点所指之节点的前方。

## [deque](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/sequence%20container/deque)

* deque 是一种双向开口的连续线性空间。可以在头尾两端分别做元素的插入和删除操作。
* deque 和 vector 的差异：第一，deque 允许于常数时间内对起头端进行元素的插入或移除操作；第二，deque 没有容量，它是动态地以分段连续空间组合而成。
* deque 由一段段的定量连续空间构成。一旦有必要在 deque 的前端或尾端增加新空间，便配置一段定量连续空间，串接在整个 deque 的头端或尾端。
* deque 实现复杂，其复杂的迭代器架构。
* 在 deque 的以前版本中，还有一个额外的模板参数，以便用户可以控制节点的大小。 这种扩展证明是违反 C++ 标准（可以使用模板模板参数检测到），并且已被删除。

> deque 的中控器 `map`

deque 采用一块所谓的 map 作为主控。这个 map 是一小块连续空间，其中每个节点都是指针，指向另一段连续线性空间，称为缓冲区。

> deque 的迭代器 `_Deque_iterator`

deque 是分段连续空间，维持其“整体连续”假象的任务。

迭代器包含 cur 指向缓冲区的当前元素，first 指向缓冲区的头，last 指向缓冲区的尾，node 指向中控器某一个 node 节点。

`push_back()`：尾端插入

`push_front()`：前端插入

`pop_back()`：尾端取出

`pop_front()`：前端取出

## [stack](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/sequence%20container/stack)

stack 是一种先进后出的数据结构。它只有一个出口。

SGI STL 默认是以 deque 作为缺省情况下的 stack 底部结构，也可以 list 作为 stack 的底层容器。

STL stack 往往不被归类为 container(容器)，而被归类为 container adapter。

`push()`：顶部进

`pop()`：顶部出

`top()`：指向顶部

## [queue](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/sequence%20container/queue)

queue 是一种先进先出的数据结构。从最底端加入元素，从最顶端取出元素。

SGI STL 默认是以 deque 作为缺省情况下的 queue 底部结构。

STL queue 往往不被归类为 container(容器)，而被归类为 container adapter。

`push()`：尾端进

`pop()`：首端出

`front()`：返回首端元素

`back()`：返回尾端元素

## [heap](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/sequence%20container/heap)

二叉搜索树的输入需要足够的随机性。

binary max heap 作为 priority queue 的底层机制。

STL 提供的是 max-heap。

`push_heap()`：入堆，新元素插入到容器 vector 底部，然后做 shift up 操作保证满足 max-heap 条件。

`pop_heap()`：取出根节点，然后做 shift down 操作保证满足 max-heap 条件， 最大元素只是被置放到底部容器的最尾端。

`sort_heap()`：内部实现是调用 pop_heap 函数。

`make_heap()`：用来将一段现有的数据转化为一个 heap。

## [priority_queue](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/sequence%20container/queue)

priority_queue 是一个拥有权值观念的 queue。

默认情况下以 vector 为底部容器完成其所有工作，再加上 heap 处理规则。

`priority_queue()`：调用 make_heap()， 使进入的元素后，始终保持一个堆。

`top()`：队顶元素。

`push()`：尾端插入元素，然后调用 push_heap() 重排堆。

`pop()`：用 pop_heap() 将最大元素放到底部容器的最尾端，并不是真正弹出，再调用底部容器 vector 所提供的 pop_back() 弹出元素。

## [slist](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/sequence%20container/slist)

STL slist 是一个单向链表。

迭代器属于单向的 Forward Iterator。

插入操作会将新元素插入到指定位置之前，而非之后。

`push_front()`：从头部插入元素

`pop_front()`：从头部取出元素

`front()`：取头部元素


