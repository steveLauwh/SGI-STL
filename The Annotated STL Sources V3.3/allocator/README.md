## 配置器(allocator)

配置器：负责空间配置与管理，从实现的角度来看，配置器是一个实现了动态空间配置、空间管理、空间释放的 class template。

空间配置器：整个 STL 的操作对象(所有的数值)都存放在容器之内，而容器一定需要配置空间以存放内容。

## 具有次配置力(sub-allocation)的 SGI 空间配置器

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

