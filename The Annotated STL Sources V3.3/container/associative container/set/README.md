## set 

set 的底层机制为 红黑树(RB-tree)。

set 的 iterator 被定义为底层 RB-tree 的 const_iterator，所以不能通过迭代器改变 set 的元素值。

```cpp
template <class _Key, class _Compare, class _Alloc>
class set {
private:
    typedef _Rb_tree<key_type, value_type, 
                  _Identity<value_type>, key_compare, _Alloc> _Rep_type;  // set 的底层实现为 RB-tree
    _Rep_type _M_t;  // red-black tree representing set
    
    typedef typename _Rep_type::const_iterator iterator; // iterator 的类型为 const_iterator
};
```
## 总结

set 集合：

* 元素有序
* 元素不能重复，唯一
