## 迭代器(iterator)

迭代器：扮演容器与算法之间的桥梁，是所谓的 “泛型指针”，共有五种类型，以及其它衍生变化。从实现的角度来看，迭代器是一种将 `operator*`，`operator->`，`operator++`，`operator--` 等指针相关操作予以重载的 class template。 所有 STL 容器都附带有自己专属的迭代器。 native pointer 也是一种迭代器。

## 迭代器(iterator) 是一种 smart pointer

迭代器是一种行为类似指针的对象，而指针的各种行为中最常见的用途是 dereference 和 member access。迭代器最重要的就是对 `operator*` 和 `operator->`进行重载工作。

auto_ptr：用来包装原生指针(native pointer)的对象，在头文件 <memory> 中定义。

为什么每一种 STL 容器都提供有专属迭代器的缘故。

主要是暴露太多细节，所以把迭代器的开发工作交给容器去完成，这样所有实现细节可以得到封装，不被使用者看到。

## 迭代器相应类型(associated types)

迭代器所指对象的类型。

利用 function template 的参数推导机制，只能推导出参数的类型，无法推导出函数返回值类型。

迭代器相应类型有五种：
  + value type
  + difference type
  + pointer
  + reference
  + iterator category

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/iteratortraits.PNG)

## Traits 编程技术

traits 意为 “特性”，扮演 “特性萃取机” 角色，萃取各个迭代器的特性(相应类型)。

template partial specialization 模板偏特化：针对 template 参数更进一步的条件限制所设计出来的一个特化版本，本身仍然是 template。

```cpp
tempalte<typename I>
struct iterator_traits
{
    typedef typename I::iterator_category  iterator_category;
    typedef typename I::value_type  value_type;
    typedef typename I::difference_type  difference_type;
    typedef typename I::pointer  pointer;
    typedef typename I::reference  reference;
};
```

* 迭代器相应类型之一：value type

value type 就是迭代器所指对象的类型。

```cpp
template <class T>
typename iterator_traits<I>::value_type func(I ite)
{
    return *ite;
}
```

* 迭代器相应类型之二：difference type

difference type 用来表示两个迭代器之间的距离。

```cpp
template <class I, class T>
typename iterator_traits<I>::difference_type cout(I first, I last, const T& value)
{
    typename iterator_traits<I>::difference_type n = 0;
    for (; first != last; ++first)
    {
        ++n;
    }
    
    return n;
}
```

* 迭代器相应类型之三：reference type

在 c++ 中，函数如果要传回左值，都是以 by reference 的方式进行，所以如果 p 是一个迭代器，它的 value type 是 T ，那么`*p` 应该是T& (即reference type)

* 迭代器相应类型之四：pointer type

* 迭代器相应类型之五：iterator_category

  + 输入迭代器 (InputIterator) 是能从所指向元素读取的迭代器 (Iterator) 。输入迭代器 (InputIterator) 仅保证单趟算法的合法性。
  + 输出迭代器 (OutputIterator) 是能写入所指元素的迭代器 (Iterator) 。
  + 向前迭代器 (ForwardIterator) 是一种能从所指向元素读取数据的迭代器 (Iterator) 。
  + 双向迭代器 (BidirectionalIterator) 是能双向移动（即自增与自减）的向前迭代器 (ForwardIterator) 。
  + 随机访问迭代器 (RandomAccessIterator) 是能在常数时间内移动到指向任何元素的双向迭代器 (BidirectionalIterator) 。

## 总结

traits 本质是什么？  

多一层间接性，换来灵活性。

iterator_traits 负责萃取迭代器的特性，__type_traits 负责萃取类型的特性。


