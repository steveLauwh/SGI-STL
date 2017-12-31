## deque

deque 是一种双向进出的连续线性空间。它是动态地分段连续空间组合而成，随时可以增加一段新的空间并链接起来。

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/deque.PNG)

### deque 内部实现原理

因为 deque 是一段段的定量连续空间构成。为了方便管理这些一段段连续空间，同时对用户来说，deque 整体是连续的，所以需要采用一小块连续空间 map 作为控制单元，
其中 map 中的每个节点 node 都是指针，指向 deque 的一段段连续空间 buffer 缓冲区。

SGI STL 允许指定 buffer 的大小，默认值为 0 表示将使用 512 bytes 缓冲区。

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/deque%20DS.PNG)

