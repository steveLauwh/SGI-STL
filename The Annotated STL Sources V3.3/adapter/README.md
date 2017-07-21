## 配接器(adapter)

配接器：一种用来修饰容器、仿函数或迭代器接口的东西。例如，STL 提供的 queue 和 stack，虽然看似容器，其实只能算是一种容器配接器，因为它们的底部完全借助 deque，所有操作都由底层的 deque 供应。改变 functor 接口者，称为 function adapter等。
