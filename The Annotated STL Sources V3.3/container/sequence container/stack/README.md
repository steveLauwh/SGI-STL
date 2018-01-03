## stack

stack(栈) 数据结构的特点是先进后出(一端进出)，不允许遍历。

stack 不像 vector、list、deque 那样独立实现，它是可以使用某种容器作为底部结构，来实现 stack 的功能，更确却说 stack 是 adapter(配接器)。

SGI STL 里的 stack 使用的是以 deque 为底部结构来实现其所有功能。

同时 list(双向开口) 数据结构，只要关闭首端，也可以作为 stack 的底部结构。

stack 没有迭代器。

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/stack.PNG)
