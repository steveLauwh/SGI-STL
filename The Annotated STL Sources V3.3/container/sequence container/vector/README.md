## vector

### vector 上的常见操作复杂度

* 随机访问——常数 O(1)
* 在末尾插入或移除元素——均摊常数 O(1)
* 插入或移除元素到 vector 结尾的距离成线性 O(n)

### vector 的迭代器类型 Random Access Iterator

vector 的迭代器涵盖了指针所有的算术能力(operator*，operator->，operator++，operator--，operator+，operator-，operator+=，operator-=)，
同时 vector 支持随机存取，所以 vector 提供是 Random Access Iterator。
