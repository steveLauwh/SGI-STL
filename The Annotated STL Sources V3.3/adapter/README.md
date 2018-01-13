## 适配器(adapter)

适配器：一种用来修饰容器、仿函数或迭代器接口的东西。例如，STL 提供的 queue 和 stack，虽然看似容器，其实只能算是一种容器适配器，因为它们的底部完全借助 deque，所有操作都由底层的 deque 供应。改变 functor 接口者，称为 function adapter等。

适配器(adapter) 在 STL 组件的灵活组合运用功能上，扮演者转换器的角色。

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/adapter.PNG)

### 应用于容器，container adapter

STL 提供的两个容器 queue 和 stack，它们修饰 deque 的接口而形成的。

### 应用于迭代器，iterator adapter

STL 提供了许多应用于迭代器的适配器。

> insert iterator

插入迭代器内部都维护有一个容器，容器当然有自己的迭代器，当客户端对插入迭代器做赋值操作时，就在插入迭代器中被转为对该容器的迭代器做插入操作。

`back_insert_iterator`

用于在容器尾部插入的迭代器适配器。

`front_insert_iterator`

用于在容器头部插入的迭代器适配器。

> reverse iterator

将迭代器的移动行为倒转。以尾到头的方向来处理序列中的元素。

> stream iterator

将迭代器绑定到一个 stream 对象身上，绑定到 istream 对象为 istream_iterator，拥有输入能力。

绑定到 ostream 对象为 ostream_iterator，拥有输出能力。

### 应用于仿函数，function adapter

> 对返回值进行逻辑否定：not1, not2

> 对参数进行绑定：bind1st, bind2nd

> 用于函数合成：compose1, compose2

> 用于函数指针：ptr_fun

> 用于成员函数指针：mem_fun, mem_fun_ref
