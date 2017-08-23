## 关联式容器

* 标准的 STL 关联式容器分为 set(集合) 和 map(映射表) 两大类。衍生的还有 multiset(多键集合) 和 multimap(多键映射表)。这些容器的底层机制都是 [RB-tree](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Tree/RB-tree)(红黑树原理) 完成。

* 散列表 [hash table](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Hash%20Table)(Hash Table 原理)，以 hash table 为底层机制而完成的 hash_set、hash_map、hash_multiset、hash_multimap。

### 以 RB-tree 为底层机制的关联式容器

### 以 hash table 为底层机制的关联式容器

hash table(散列表)数据结构，在插入、删除、查找等操作具有 “常数平均时间” 的表现，这种表现是以统计为基础，不需要依赖输入元素的随机性。

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

## hash_set

RB-tree 有自动排序功能而 hashtable 没有，所以 set 的元素有自动排序功能而 hash_set 没有。

hash_set 大小指定为 100(根据 SGI 的设计，采用质数 193)。

## hash_map

运用 map 为的是能够根据键值快速查找元素。RB-tree 有自动排序功能而 hashtable 没有，所以 map 的元素有自动排序功能而 hash_map 没有。

## hash_multiset

hash_multiset 与 hash_set 的真正差别是前者插入操作采用底层机制 hashtable 的 insert_equal()，后者采用 insert_unique()。

## hash_multimap

hash_multimap 与 hash_map 的真正差别是前者插入操作采用底层机制 hashtable 的 insert_equal()，后者采用 insert_unique()。
