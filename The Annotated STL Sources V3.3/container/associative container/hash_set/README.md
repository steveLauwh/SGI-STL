## hash_set

* hash_set 底层实现机制是 hash table，所以 hash_set 内部实现就是封装 hashtable 类
* hash_set 的键值就是实值
* hash_set 不允许有重复元素存在，因为底层调用 hashtable 的 insert_unique()
* hash_set 默认指定 hashtable 大小为 100(质数 193)
* hash_set 元素是无序的

```cpp
// hash_set 实现
template <class _Value, class _HashFcn, class _EqualKey, class _Alloc>
class hash_set
{
private:
    typedef hashtable<_Value, _Value, _HashFcn, _Identity<_Value>, 
                    _EqualKey, _Alloc> _Ht; // 底层机制 hash table
    _Ht _M_ht;
public:
    hash_set(const value_type* __f, const value_type* __l)
        : _M_ht(100, hasher(), key_equal(), allocator_type())
    { _M_ht.insert_unique(__f, __l); }
    ....
};
```

## hash_multiset

* hash_multiset 与 hash_set 除了底层调用 hashtable 的 insert_equal()，允许重复元素存在；其它特性都相同

```cpp
// hash_multiset 实现
template <class _Value, class _HashFcn, class _EqualKey, class _Alloc>
class hash_multiset
{
private:
    typedef hashtable<_Value, _Value, _HashFcn, _Identity<_Value>, 
                    _EqualKey, _Alloc> _Ht; // 底层机制 hash table
    _Ht _M_ht;
public:
    hash_multiset(const value_type* __f, const value_type* __l)
        : _M_ht(100, hasher(), key_equal(), allocator_type())
    { _M_ht.insert_equal(__f, __l); }  // 与 hash_set 唯一差别，允许键值重复
....
```
