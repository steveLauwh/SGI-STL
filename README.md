## SGI-STL V3.3 源代码的学习

* SGI-STL V3.3(源代码)
  + STL 标准头文件(无扩展名)，例如 `vector`，`deque`，`list`...
  + C++ Standard 定案前，HP 规范的 STL 头文件(扩展名 .h)
  + SGI STL 内部私用文件(SGI STL 真正实现于此)
  
* The Annotated STL Sources V3.3(学习源代码的注释)
  + [容器 (container)](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container) ：序列式容器 (sequence container) 和 关联式容器 (associattive container)
  + [算法 (algorithm)](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/algorithm)
  + [迭代器 (iterator)](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/iterator)
  + [仿函数或函数对象 (functor / function object)](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/functor-function%20object)
  + [配接器(adapter)](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/adapter)
  + [配置器(allocator)](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/allocator)

* SGI-STL Test(代码测试)

  + [Code Test](https://github.com/steveLauwh/SGI-STL/tree/master/SGI-STL%20Test)

## GCC 编译器

SGI STL 被归纳到 GNU C++ 标准程序库中，例如 gcc 使用 4.8.4 版本，STL源码 在 Linux 系统的位置是：/usr/include/c++/4.8.4/bits。

## 参考资料

* <<STL 源代码剖析>> 侯捷
