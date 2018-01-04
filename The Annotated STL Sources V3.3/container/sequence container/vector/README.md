## vector

### vector 上的常见操作复杂度

* 随机访问——常数 O(1)
* 在末尾插入或移除元素——均摊常数 O(1)
* 插入或移除元素到 vector 结尾的距离成线性 O(n)

### vector 的迭代器类型 Random Access Iterator

vector 的迭代器涵盖了指针所有的算术能力(`operator*，operator->，operator++，operator--，operator+，operator-，operator+=，operator-=`)，
同时 vector 支持随机存取，所以 vector 提供是 Random Access Iterator。

### vector 的数据结构

```cpp
template <class T, class Alloc = alloc>
class vector
{
public:
    typedef T value_type;
    typedef value_type* iterator; // vector 的迭代器是普通指针
protected:
    iterator start;  // 表示目前使用空间的头
    iterator finish; // 表示目前使用空间的尾
    iterator end_of_storage; // 表示目前可用空间的尾
};
```

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/vector.PNG)

### 看 vector 底层实现的记录

size_type：无符号整数类型（通常是 std::size_t）

#### uninitialized_fill_n 功能

```cpp
template< class ForwardIt, class Size, class T >
ForwardIt uninitialized_fill_n( ForwardIt first, Size count, const T& value );
```
函数功能是：从 first 起始，将 value 的值复制 count 个。

函数的参数：

* first	-	要初始化的元素范围起始
* count	-	要构造的元素数量
* value	-	构造元素所用的值

#### uninitialized_copy 功能

```cpp
template< class InputIt, class ForwardIt >
ForwardIt uninitialized_copy( InputIt first, InputIt last, ForwardIt d_first );
```
函数的功能：复制来自范围 `[first, last)` 的元素到始于 d_first 的未初始化内存。

函数的参数：

* first, last	-	要复制的元素范围
* d_first	-	目标范围的起始

#### uninitialized_fill 功能

```cpp
template< class ForwardIt, class T >
void uninitialized_fill( ForwardIt first, ForwardIt last, const T& value );
```
函数的功能：复制给定的 value 到以 `[first, last)` 定义的未初始化内存区域。

函数的参数：

* first, last	-	要初始化的元素的范围
* value	-	构造元素所用的值

#### copy 功能

```cpp
template< class InputIt, class OutputIt >
OutputIt copy( InputIt first, InputIt last, OutputIt d_first );
```
函数的功能：复制 `[first, last)` 所定义的范围中的元素到始于 d_first 的另一范围。

函数的参数：

* first, last	-	要复制的元素范围
* d_first	-	目标范围的起始

#### vector insert 形式

```cpp
// 在 pos 前插入 value，底层实现 _M_insert_aux
iterator insert( iterator pos, const T& value );

// 在 pos 前插入 value 的 count 个副本，底层实现 _M_fill_insert
void insert( iterator pos, size_type count, const T& value );

// 在 pos 前插入来自范围 `[first, last)` 的元素，底层实现 _M_range_insert
template< class InputIt >
void insert( iterator pos, InputIt first, InputIt last);
```
