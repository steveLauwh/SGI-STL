## 容器(container)

容器：包括序列式容器和关联式容器；即各种数据结构，如 vector，list，deque，set，map 等用来存储数据；从实现的角度来看，STL 容器是一种 class template。

任何特定的数据结构都是为了实现某种特定的算法。

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/container.PNG)

## [序列式容器(sequence container)](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/sequence%20container)

* array (C++ 提供，build-in)
* vector
* heap (内含一个 vector)
* priority-queue (内含一个 heap)
* list
* slist (非标准)
* deque
* stack (内含一个 deque)  (adapter 配接器)
* queue (内含一个 deque)  (adapter 配接器)

怎么理解序列式容器，其中的元素都可序(ordered), 但未必有序(sorted)？

ordered 是容器集合被排序，可以使用指定的顺序去遍历集合。 sorted 是一个容器集合根据某些规则确定排序的。

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/sequencecontainer.PNG)

## [关联式容器(associative container)](https://github.com/steveLauwh/SGI-STL/tree/master/The%20Annotated%20STL%20Sources%20V3.3/container/associative%20container)

* RB-tree (非公开)
* set (内含一个 RB-tree)
* map (内含一个 RB-tree)
* multiset (内含一个 RB-tree)
* multimap (内含一个 RB-tree)
* hashtable (非标准)
* hash_set (内含一个 hashtable)  (非标准)
* hash_map (内含一个 hashtable)  (非标准)
* hash_multiset (内含一个 hashtable)  (非标准)
* hash_multimap (内含一个 hashtable)  (非标准)

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/associativecontainer.PNG)

熟悉关联式容器，需要有 [RB-tree](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Tree/RB-tree)(红黑树原理) 和 [hash table](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Hash%20Table)(哈希表原理) 基础。

