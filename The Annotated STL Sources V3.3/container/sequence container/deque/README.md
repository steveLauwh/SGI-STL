## deque

deque 是一种双向进出的连续线性空间。它是动态地分段连续空间组合而成，随时可以增加一段新的空间并链接起来。

特点：

* deque(double-ended queue ，双端队列)是有下标顺序容器，它允许在其首尾两段快速插入及删除
* deque 的元素不是相接存储的，典型实现用单独分配的固定大小数组的序列，外加额外的标记，这表示下标访问必须进行二次指针解引用，与之相比 vector 的下标访问只进行一次

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/deque.PNG)

### deque 内部实现原理

因为 deque 是一段段的定量连续空间构成。为了方便管理这些一段段连续空间，同时对用户来说，deque 整体是连续的，所以需要采用一小块连续空间 map 作为控制单元，其中 map 中的每个节点 node 都是指针，指向 deque 的一段段连续空间 buffer 缓冲区。

SGI STL 允许指定 buffer 的大小，默认值为 0 表示将使用 512 bytes 缓冲区。

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/deque%20DS.PNG)

一个小块连续空间 map 包含节点数，最少 8 个，最多是所需节点数加上 2。

### deque 常见的时间复杂度

* 随机访问——常数 O(1)
* 在结尾或起始插入或移除元素——常数 O(1)
* 插入或移除元素——线性 O(n)
