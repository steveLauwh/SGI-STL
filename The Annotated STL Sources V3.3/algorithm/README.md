## 算法(algorithm)

算法：各种常用算法如 sort，search，copy，erase等，从实现的角度来看，STL 算法是一种 function template。

所有泛型算法的前两个参数都是一对迭代器，STL 习惯使用前闭后开的区间，`[first, last)`。

最后一个元素的下一位置，称为 end。

数值的传递由 pass-by-value 改为 pass-by-reference，好处是，在模板中，参数的类型可以任意，当对象一大，传递成本便会上升，所以用 pass-by-reference 可以节省空间。

### 数值算法 <stl_numeric.h>

STL 将数值算法的内部实现放在 <stl_numeric.h> 中，用户调用数值算法的接口，需要包含 <numeric> 头文件。
  
元素累加 `accumulate`


