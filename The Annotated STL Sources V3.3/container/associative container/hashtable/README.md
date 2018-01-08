## hashtable

哈希表原理：[hash table](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Hash%20Table)

SGI STL hash table 使用（separate chaining）开链法来解决（碰撞 collision）问题。

### hashtable 内部实现

* 桶 buckets：用 vector 表示
* hash table 节点：链表的节点

大致描述：对于一个数，进行散列函数处理，获得一个索引(就是桶的节点)；当数量很大时，经过散列函数处理，会得到相同的索引，那么桶的节点位置一样，
此时，将相同的节点使用链表连接起来。

```cpp
// hash table 节点
template <class _Val>
struct _Hashtable_node
{
    _Hashtable_node* _M_next;
    _Val _M_val;
}; 
```

hash table 迭代器必须永远维持整个 "buckets vector" 的关系，同时并记录目前所指的节点。hash table 迭代器类型为 forward_iterator。

迭代器进行 operator++ 操作，如果目前节点正好是当前 list 的尾端，就跳到下一个 bucket 上。

```cpp
// hash table 迭代器
template <class _Val, class _Key, class _HashFcn,
          class _ExtractKey, class _EqualKey, class _Alloc>
struct _Hashtable_iterator {
    typedef hashtable<_Val,_Key,_HashFcn,_ExtractKey,_EqualKey,_Alloc> _Hashtable;
    typedef _Hashtable_node<_Val> _Node; // hash table 节点

    typedef forward_iterator_tag iterator_category; // 迭代器类型：前向迭代器

    _Node* _M_cur; // 迭代器目前所指的节点
    _Hashtable* _M_ht; // 保持对容器的连接关系，bucket
    ...
};
```

```cpp
// hash table 数据结构
template <class _Val, class _Key, class _HashFcn,
          class _ExtractKey, class _EqualKey, class _Alloc>
class hashtable {
public:
public:
    typedef _Key key_type; // 节点的键值
    typedef _Val value_type; // 节点的实值
    typedef _HashFcn hasher; // 哈希函数
    typedef _EqualKey key_equal; // 判断键值是否相同
private:
    typedef _Hashtable_node<_Val> _Node; // 节点
    vector<_Node*,_Alloc> _M_buckets; // vector 容器
};
```


