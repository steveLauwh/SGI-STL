## 配置器(allocator)

配置器：负责空间配置与管理，从实现的角度来看，配置器是一个实现了动态空间配置、空间管理、空间释放的 class template。

空间配置器：整个 STL 的操作对象(所有的数值)都存放在容器之内，而容器一定需要配置空间以存放内容。

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/allocator.PNG)

## 具有次配置力(sub-allocation)的 SGI 空间配置器

### SGI STL 空间配置器的结构

SGI STL 的配置器，其名称是 alloc 而不是 allocator，而且不接受任何参数。

SGI STL 的每一个容器都已经指定其缺省的空间配置器为 alloc。

```cpp
template <class T, class Alloc = alloc>  // 缺省使用 alloc 为配置器
class vector {...};

vector<int, std::alloc> iv; 
```

* <defalloc.h>----SGI 标准的空间配置器，std::allocator

  allocator 只是基层内存配置/释放行为(::operator::new 和 ::operator::delete)的一层薄薄的包装，并没有考虑到任何效率上的强化。

* SGI 特殊的空间配置器，std::alloc

  + <stl_construct.h>：定义了全局函数 construct() 和 destroy()，负责对象的构造和析构。 
  + <stl_alloc.h>：定义了一、二级配置器，配置器名为 alloc。
  + <stl_uninitialized.h>：定义了全局函数，用来填充(fill)或复制(copy)大块内存数据。

* 构造和析构基本工具

  具体看 <stl_construct.h> 源码，功能是构造和析构操作。

* 空间的配置和释放，std::alloc
  + 向 system heap 要求空间
  + 考虑多线程(multi-threads)状态
  + 考虑内存不足时的应变措施
  + 考虑过多 “小型区块” 可能造成的内存碎片问题

  对象构造前的空间配置 和 对象析构后的空间释放，具体看 <stl_alloc.h>。

### SGI STL 空间配置器的分析

考虑到小型区块可能造成内存碎片问题，SGI 采用两级配置器，第一级配置器直接使用 malloc() 和 free() 实现；第二级配置器使用 memory pool 内存池管理。

第二级配置器的原理：

* 当配置区块超过 128 bytes，就使用第一级配置器
* 当配置区块小于 128 bytes，使用内存池管理

```c
enum {_ALIGN = 8};  // 小型区块的上调边界
enum {_MAX_BYTES = 128}; // 小区区块的上限
enum {_NFREELISTS = 16}; // _MAX_BYTES/_ALIGN  free-list 的个数

// free-list 的节点结构，降低维护链表 list 带来的额外负担
union _Obj {
    union _Obj* _M_free_list_link;  // 利用联合体特点
    char _M_client_data[1];    /* The client sees this. */
};
static _Obj* __STL_VOLATILE _S_free_list[_NFREELISTS];  // 注意，它是数组，每个数组元素包含若干相等的小额区块
 ```

其中 free-list 是指针数组，16 个数组元素，就是 16 个 free-list，各自管理大小分别为 8， 16， 24， 32，...128 bytes(8 的倍数)的小额区块。

小额区块的结构体 `union _Obj` 使用链表连接起来。

配置器负责配置，同时也负责回收。

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/allocator_memorypool.PNG)


