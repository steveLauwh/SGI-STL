## 迭代器(iterator)

迭代器：扮演容器与算法之间的桥梁，是所谓的 “泛型指针”，共有五种类型，以及其它衍生变化。从实现的角度来看，迭代器是一种将 `operator*`，`operator->`，`operator++`，`operator--` 等指针相关操作予以重载的 class template。 所有 STL 容器都附带有自己专属的迭代器。 native pointer 也是一种迭代器。

## 迭代器(iterator) 是一种 smart pointer

迭代器是一种行为类似指针的对象，而指针的各种行为中最常见的用途是 dereference 和 member access。迭代器最重要的就是对 `operator*` 和 `operator->`进行重载工作。

auto_ptr：用来包装原生指针(native pointer)的对象，在头文件 <memory> 中定义。

为什么每一种 STL 容器都提供有专属迭代器的缘故。

主要是暴露太多细节，所以把迭代器的开发工作交给容器去完成，这样所有实现细节可以得到封装，不被使用者看到。

## 迭代器相应类型(associated types)

利用 function template 的参数推导机制，只能推导出参数的类型，无法推导出函数返回值类型。

迭代器相应类型有五种：
  + value type
  + difference type
  + pointer
  + reference
  + iterator category

## Traits 编程技术

traits 意为 “特性”，扮演 “特性萃取机” 角色，萃取各个迭代器的特性(相应类型)。

template partial specialization 模板偏特化：针对 template 参数更进一步的条件限制所设计出来的一个特化版本，本身仍然是 template。

```cpp
tempalte<typename I>
struct iterator_traits
{
    typedef typename I::iterator_category iterator_category;
    typedef typename I::value_type value_type;
    typedef typeanme I:difference_type difference_type;
    typedef typename I::pointer pointer;
    typedef typename I::reference reference;
};
```

