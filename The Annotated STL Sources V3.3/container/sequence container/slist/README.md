## slist

STL slist 作为单链表，如果在尾端插入，效率很低，所以只提供首端插入 push_front() 操作。

slist 容器并没有归入标准规格。

C++11 提供 `std::forward_list`(正向链表)，与 slist 功能类似。

[forward_list](http://classfoo.com/ccby/article/5wWLx) 没有像 slist 提供 size() 成员函数，因为 forward_list 类模板是专为极度考虑性能的程序而设计的。

ctor：constructor

dtor：destructor

slist 内部实现就是对单向链表的操作。

### vector 和 list 区别

* vector 拥有一段连续的内存空间，能很好的支持随机存取

* list 的内存空间可以是不连续，它不支持随机访问；由于链表的特点，能高效地进行插入和删除
