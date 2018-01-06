## Red Black Tree

红黑树原理：[RB-tree](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Tree/RB-tree)

### SGI STL RB-tree 实现技巧

```cpp
typedef _Rb_tree_node* _Link_type;

_Rb_tree_node<_Tp>* _M_header;

// 利用 header 快速找到 RB-tree 最小值，最大值，根节点
_Link_type& _M_root() const 
  { return (_Link_type&) _M_header->_M_parent; }
_Link_type& _M_leftmost() const 
  { return (_Link_type&) _M_header->_M_left; }
_Link_type& _M_rightmost() const 
  { return (_Link_type&) _M_header->_M_right; }
  
_S_color(_M_header) = _S_rb_tree_red;  // header 的颜色为红色
```

SGI STL 特别为 root 根节点设计一个父节点 header，同时 header 的父节点为 root 根节点。

```cpp
// 插入新值，节点键值允许重复
template <class _Key, class _Value, class _KeyOfValue, 
          class _Compare, class _Alloc>
typename _Rb_tree<_Key,_Value,_KeyOfValue,_Compare,_Alloc>::iterator
_Rb_tree<_Key,_Value,_KeyOfValue,_Compare,_Alloc>
  ::insert_equal(const _Value& __v)
{
  _Link_type __y = _M_header;
  _Link_type __x = _M_root(); // 从根节点开始
  while (__x != 0) {
    __y = __x;  
    // 当插入值大于当前节点的值，向右，否则反之
    __x = _M_key_compare(_KeyOfValue()(__v), _S_key(__x)) ? 
            _S_left(__x) : _S_right(__x);
  }
  return _M_insert(__x, __y, __v); // __x 为插入节点，__y 为插入节点的父节点， __v 为插入节点的值
}
```

```cpp
// 插入新值，节点键值不允许重复，唯一
template <class _Key, class _Value, class _KeyOfValue, 
          class _Compare, class _Alloc>
pair<typename _Rb_tree<_Key,_Value,_KeyOfValue,_Compare,_Alloc>::iterator, 
     bool>
_Rb_tree<_Key,_Value,_KeyOfValue,_Compare,_Alloc>
  ::insert_unique(const _Value& __v)
{
  _Link_type __y = _M_header;
  _Link_type __x = _M_root(); // 从根节点开始
  bool __comp = true;
  while (__x != 0) { // 找适当位置插入
    __y = __x;
    __comp = _M_key_compare(_KeyOfValue()(__v), _S_key(__x));
    __x = __comp ? _S_left(__x) : _S_right(__x);
  }
  iterator __j = iterator(__y);   // 迭代器 __j 指向插入节点之父节点 __y
  if (__comp)  
    if (__j == begin())     // 插入节点为父节点的最左节点
      return pair<iterator,bool>(_M_insert(__x, __y, __v), true);
    else
      --__j;
  if (_M_key_compare(_S_key(__j._M_node), _KeyOfValue()(__v))) // 不重复，执行
    return pair<iterator,bool>(_M_insert(__x, __y, __v), true);
  return pair<iterator,bool>(__j, false); // 重复，不插入
}
```
## 总结

插入新节点或者删除旧节点，需要维护 header 节点、需要满足 RB-tree 特性。
