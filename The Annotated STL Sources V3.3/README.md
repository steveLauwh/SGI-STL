## STL 六大组件

「STL 六大组件的交互关系」
 * [Container](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container) 通过 [Allocator](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/allocator) 取得数据储存空间
 * [Algorithm](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/algorithm) 通过 [Iterator](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/iterator) 存取 [Container](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container) 内容
 * [Functor](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/functor-function%20object) 可以协助 [Algorithm](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/algorithm) 完成不同的策略变化
 * [Adapter](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/adapter) 可以修饰或套接 [Functor](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/functor-function%20object)、[Iterator](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/iterator)。

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/SGISTL.PNG)
