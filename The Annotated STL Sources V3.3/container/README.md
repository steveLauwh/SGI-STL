## 容器(container)

容器：包括序列式容器和关联式容器；即各种数据结构，如 vector，list，deque，set，map 等用来存储数据；从实现的角度来看，STL 容器是一种 class template。

任何特定的数据结构都是为了实现某种特定的算法。

## 序列式容器(sequence container)

* array (C++ 提供，build-in)
* vector
* heap (内含一个 vector)
* priority-queue (内含一个 heap)
* list
* slist (非标准)
* deque
* stack (内含一个 deque)  (adapter 配接器)
* queue (内含一个 deque)  (adapter 配接器)



## 关联式容器(associative container)

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

