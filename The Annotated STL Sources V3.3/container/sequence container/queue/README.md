## queue

queue 的数据结构特点是 FIFO(先进先出)，尾端进，首端出；所以 queue 也是不允许遍历。

queue 与 stack 一样，以某种容器为底层结构，被称为 container adapter。

在 SGI STL 里，queue 默认是以 deque 为底层容器，将 deque 的尾端出关闭，首端进关闭，就可以实现 queue 的功能。

queue 还可以使用 list 作为底层容器。

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/queue.PNG)

## priority_queue

STL priority_queue 的内部实现：默认情况下，以 vector 为底层容器，加上 heap(默认max-heap) 处理规则；具有权值高者先出的特性。

被归为 container adapter，就是对 container 进行封装一层。

priority_queue 本质还是 queue，只允许在尾部加入元素，并从首部取出元素；只不过内部元素具有优先级，优先级高者先出。

priority_queue 的所有元素进出具有一定规则，所以不提供遍历功能，也不提供迭代器。
