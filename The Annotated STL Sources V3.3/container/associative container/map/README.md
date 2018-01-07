## map

map 的底层机制是 RB-tree(红黑树)，插入，删除，查找的时间复杂度都是 O(logn)。

```cpp
template <class _Key, class _Tp, class _Compare, class _Alloc>
class map {
public:
    typedef _Key                  key_type; // 键值类型
    typedef _Tp                   data_type; // 实值类型
    typedef _Tp                   mapped_type;
    typedef pair<const _Key, _Tp> value_type;  // 元素类型(键值/实值)
    typedef _Compare              key_compare; // 键值比较函数

private:
    typedef _Rb_tree<key_type, value_type, 
                   _Select1st<value_type>, key_compare, _Alloc> _Rep_type; // map 的底层机制 RB-tree 
    _Rep_type _M_t;  // red-black tree representing map 以红黑树(RB-tree) 表现 map
    
public:
    typedef typename _Rep_type::iterator iterator;  // map 迭代器
};
```

## 总结

* map 的结构是键值对 <Key, value>，键值是唯一的
* 键值是有序
