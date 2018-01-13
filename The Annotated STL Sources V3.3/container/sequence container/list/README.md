## list

SGI STL 的 list 是一个双向链表，同时还是一个环状的双向链表；对于任何位置的元素插入或元素移除，list 永远是常数时间。

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/list.PNG)

### list 的节点(node)

```cpp
// 双向链表
struct _List_node_base {
  _List_node_base* _M_next;
  _List_node_base* _M_prev;
};

// list 节点
template <class _Tp>
struct _List_node : public _List_node_base {
  _Tp _M_data; // 节点存储的值
};
```

### list 的迭代器

list 的节点可以在存储空间中不连续，所以 list 的迭代器必须具备前移、后移的能力，list 提供是 Bidirectional iterator。

```cpp
// List 迭代器基类
struct _List_iterator_base {
  typedef size_t                     size_type;
  typedef ptrdiff_t                  difference_type;
  typedef bidirectional_iterator_tag iterator_category;  // 双向移动迭代器

  _List_node_base* _M_node; // 迭代器内部当然要有一个普通指针，指向 list 的节点

  _List_iterator_base(_List_node_base* __x) : _M_node(__x) {}
  _List_iterator_base() {}

  void _M_incr() { _M_node = _M_node->_M_next; }  // 前驱
  void _M_decr() { _M_node = _M_node->_M_prev; }  // 后继

  // 比较两个容器操作
  bool operator==(const _List_iterator_base& __x) const {
    return _M_node == __x._M_node;
  }
  bool operator!=(const _List_iterator_base& __x) const {
    return _M_node != __x._M_node;
  }
};  
```

### list 的数据结构

```cpp
// list 的基类
template <class _Tp, class _Alloc>
class _List_base 
{
public:
  typedef _Alloc allocator_type;
  allocator_type get_allocator() const { return allocator_type(); }

  _List_base(const allocator_type&) {
    _M_node = _M_get_node();
    _M_node->_M_next = _M_node;
    _M_node->_M_prev = _M_node;
  }
  ~_List_base() {
    clear();
    _M_put_node(_M_node);
  }

  void clear();

protected:
  // 专属之空间配置器，每次配置一个节点大小
  typedef simple_alloc<_List_node<_Tp>, _Alloc> _Alloc_type;
  _List_node<_Tp>* _M_get_node() { return _Alloc_type::allocate(1); } // 配置一个节点并传回
  void _M_put_node(_List_node<_Tp>* __p) { _Alloc_type::deallocate(__p, 1); }  // 释放一个节点

protected:
  _List_node<_Tp>* _M_node;  // 只要一个指针，便可表示整个环状双向链表，空白节点
};
```
list 数据结构设计的是环状的双向链表，由于遵循 STL 的前闭后开原则，默认有一个 node 指针刻意置于尾端的一个空白节点。
