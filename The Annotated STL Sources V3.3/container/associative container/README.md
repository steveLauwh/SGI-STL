# 关联式容器

* 标准的 STL 关联式容器分为 set(集合) 和 map(映射表) 两大类。衍生的还有 multiset(多键集合) 和 multimap(多键映射表)。这些容器的底层机制都是 [RB-tree](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Tree/RB-tree)(红黑树原理) 完成。

* 散列表 [hash table](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Hash%20Table)(Hash Table 原理)，以 hash table 为底层机制而完成的 hash_set、hash_map、hash_multiset、hash_multimap。

## 以 RB-tree 为底层机制的关联式容器

### [底层机制 RB-tree](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/associative%20container/RB-tree)

SGI STL 有实现 RB-tree(红黑树) 的源码。

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/RBTree.PNG)

红黑树是一棵特殊的二叉搜索树。

二叉搜索树的元素插入操作：插入新元素时，可以从根节点开始，遇到键值比插入元素大就向左，遇到键值比插入元素小就向右，一直到尾端，即为插入点。

二叉搜索树的元素删除操作：删除节点 A，当 A 只有一个子节点，就直接将 A 的子节点连接到 A 的父节点，并将 A 删除。当 A 有两个子节点，将其右子树内的
最小节点取代 A。

### [set](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/associative%20container/set)

set 元素的键值就是实值，实值就是键值。简单理解，含有 Key 类型对象的已排序集。

set 不允许两个元素有相同的键值，同时所有元素根据键值自动排序。

```cpp
template<
    class Key,
    class Compare = std::less<Key>, // 默认递增排序
    class Allocator = std::allocator<Key>
> class set;
```

### [map](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/associative%20container/map)

map 元素是键值对 pair，同时拥有键值(key)和实值(value)。

map 不允许元素的键值有相同，必须唯一。

map 所有元素按照元素的键值自动排序。

```cpp
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> >
> class map;
```

### [multiset](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/associative%20container/multiset)

multiset 和 set 的用法和特性完全相同，唯一的差别是 multiset 允许键值重复。

multiset 的插入操作采用的是底层机制 RB-tree 的 insert_equal()。

头文件：`#include <set>`

### [multimap](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/associative%20container/multimap)

multimap 和 map 的用法和特性完全相同，唯一的差别是 multimap 允许键值重复。

multimap 的插入操作采用的是底层机制 RB-tree 的 insert_equal()。

头文件：`#include <map>`

## 以 hash table 为底层机制的关联式容器

### [底层机制 hashtable](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/associative%20container/hashtable)

hash table(散列表)数据结构，在插入、删除、查找等操作具有 “常数平均时间” O(1) 的表现，这种表现是以统计为基础，不需要依赖输入元素的随机性。

当索引值非常庞大，造成需要很大的 array，这样需要使用某种映射函数，将大数映射为小数。负责将某一个元素映射为一个“大小可接受之索引”，这种映射函数称为散列函数(hash function)。

SGI STL 的 hash table 采用 separate chaining 链接法来处理碰撞问题。

散列表使用 vector，包含 N 个 bucket，每个 bucket 所维护的 linked list 是自构造的。

hash table 的迭代器没有后退操作，也没有逆向迭代器。

客户端程序不能直接包含 <stl_hashtable.h>, 而是包含有用到 hashtable 的容器头文件，如 <hash_set.h> 或 <hash_map.h>。

**hash table 的 API**

`insert_unique(): 插入元素，不允许重复`

`insert_equal(): 插入元素，允许重复`

`find(): 查找元素`

`resize(): 调整表格`

SGI hashtable 的 hash function 无法处理 string， double， float 等类型的元素。

hashtable 大小指定为 50(根据 SGI 的设计，采用质数 53)。

### [hash_set](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/associative%20container/hash_set)

RB-tree 有自动排序功能而 hashtable 没有，所以 set 的元素有自动排序功能而 hash_set 没有。

hash_set 大小指定为 100(根据 SGI 的设计，采用质数 193)。

### [hash_map](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/associative%20container/hash_map)

运用 map 为的是能够根据键值快速查找元素。RB-tree 有自动排序功能而 hashtable 没有，所以 map 的元素有自动排序功能而 hash_map 没有。

### [hash_multiset](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/associative%20container/hash_set)

hash_multiset 与 hash_set 的真正差别是前者插入操作采用底层机制 hashtable 的 insert_equal()，后者采用 insert_unique()。

### [hash_multimap](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/associative%20container/hash_map)

hash_multimap 与 hash_map 的真正差别是前者插入操作采用底层机制 hashtable 的 insert_equal()，后者采用 insert_unique()。
