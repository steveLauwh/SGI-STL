## queue

queue 的数据结构特点是 FIFO(先进先出)，尾端进，首端出；所以 queue 也是不允许遍历。

queue 与 stack 一样，以某种容器为底层结构，被称为 container adapter。

在 SGI STL 里，queue 默认是以 deque 为底层容器，将 deque 的尾端出关闭，首端进关闭，就可以实现 queue 的功能。

queue 还可以使用 list 作为底层容器。
