## vector

* vector 与 array 唯一区别是空间的运用的灵活性。
* array 是静态空间，一旦配置了就不能改变。
* vector 维护的是一个连续线性空间，所以不论其元素类型为何，普通指针都可以作为 vector 的迭代器而满足所有必要条件。
* 增加新元素，如果超过当时的容量，则容量会扩充至两倍。

```cpp
vector<int>::iterator ivite;   // ivite 的类型就是 int*
vector<Shape>::iterator svite; // svite 的类型就是 Shape*
```
