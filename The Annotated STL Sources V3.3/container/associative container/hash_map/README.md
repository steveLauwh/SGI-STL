## hash_map

* hash_map 的元素结构：<key, value> 键值对
* hash_map 底层机制为 hash table
* hash_map 元素是无序的，不会自动排序
* hash_map 默认使用 hashtable 大小为 100
* hash_map 不允许键值重复的元素

```cpp
// hash_map 实现 <key, value>
template <class _Key, class _Tp, class _HashFcn, class _EqualKey,
          class _Alloc>
class hash_map
{
private:
    typedef hashtable<pair<const _Key,_Tp>,_Key,_HashFcn,
                    _Select1st<pair<const _Key,_Tp> >,_EqualKey,_Alloc> _Ht;  // 底层机制 hash table
    _Ht _M_ht;
public:
    hash_map(const value_type* __f, const value_type* __l)
      : _M_ht(100, hasher(), key_equal(), allocator_type())
    { _M_ht.insert_unique(__f, __l); }   // hash_map 不允许键值有重复的元素
};
```

## hash_multimap

* hash_multimap 可以允许键值重复的元素，其它与 hash_map 特性相同

```cpp
template <class _Key, class _Tp, class _HashFcn, class _EqualKey, 
          class _Alloc>
class hash_multimap
{
private:
    typedef hashtable<pair<const _Key, _Tp>, _Key, _HashFcn,
          _Select1st<pair<const _Key, _Tp> >, _EqualKey, _Alloc> _Ht; // 底层机制也是 hash table
    _Ht _M_ht;
public:
    hash_multimap(const value_type* __f, const value_type* __l)
      : _M_ht(100, hasher(), key_equal(), allocator_type())  
    { _M_ht.insert_equal(__f, __l); } // 与 hash_map 唯一差别是允许键值重复    
};
```
