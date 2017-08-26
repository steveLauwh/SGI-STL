## 算法(algorithm)

算法：各种常用算法如 sort，search，copy，erase等，从实现的角度来看，STL 算法是一种 function template。

所有泛型算法的前两个参数都是一对迭代器，STL 习惯使用前闭后开的区间，`[first, last)`。

最后一个元素的下一位置，称为 end。

数值的传递由 pass-by-value 改为 pass-by-reference，好处是，在模板中，参数的类型可以任意，当对象一大，传递成本便会上升，所以用 pass-by-reference 可以节省空间。

### 数值算法 <stl_numeric.h>

STL 将数值算法的内部实现放在 <stl_numeric.h> 中，用户调用数值算法的接口，需要包含 <numeric> 头文件。
  
> 元素累加 `accumulate`

算法 `accumulate` 用来计算 init 和 `[first, last)` 内所有元素的总和。

> 相邻元素的差值 `adjacent_difference`

算法 `adjacent_difference` 用来计算 `[first, last)` 中相邻元素的差值。

> 内积 `inner_product`

算法 `inner_product` 计算 `[first1, last1)` 和 `[first2, first2 + (last1 - first1))` 的一般内积。 

> 局部求和 `partial_sum`

算法 `partial_sum` 用来计算局部求和。

> 幂次方 `power`

算法 `power` 用来计算某数的 n 幂次方。

> 递增 `iota`

在某区间 `[first, last)` 填入某指定值 `value` 的递增序列。

### 基本算法 <stl_algobase.h>

> 判断两个区间是否相等 `equal`

如果两个序列在 `[first, last)` 区间内相等，`equal()` 返回 true。

注意，如果第二个序列的元素比较多，多出来的元素不予考虑，只要与第一个序列的元素相等，就返回 true。

> 改填元素 `fill`

将 `[first, last)` 内的所有元素改填新值。

> 改填元素的值 n 次 `fill_n`

将 `[first, last)` 内的前 n 个元素改填新值，返回的迭代器指向被填入的最后一个元素的下一位置。

> 元素互换 `iter_swap`

将两个 Forwarditerators 所指的对象对调。

> 以字典顺序进行比较 lexicographical_compare

以 "字典排列方式" 对两个序列 `[first1, last1)` 和 `[first2, last2)` 进行比较。

> 最大值 `max`

取两个对象的较大值。

> 最小值 `min`

取两个对象的最小值。

> 找出不匹配的点 `mismatch`

用来平行比较两个序列，指出两者之间的第一个不匹配点。

> 交换 `swap`

该函数用来交换两个对象的内容。

> 复制 `copy`

`copy` 算法可将输入区间 `[first, last)` 内的元素复制到输出区间 `[result, result + (last-first))` 内。

> 逆向复制 `copy_backward`

将 `[first, last)` 区间内的每一个元素，以逆行的方向复制到以 `result-1` 为起点，方向亦为逆行的区间上。

> `set` 相关算法

* 并集 `set_union`

算法 `set_union` 可构造 S1、S2 之并集(S1 U S2)，此集合内含 S1 或 S2 内的每一个元素。其中 S1、S2 及其并集都是以排序区间表示。

* 交集 `set_intersection`

算法 `set_intersection` 可构造 S1、S2 之交集。

* 差集 `set_difference`

算法 `set_difference` 可构造 S1、S2 之差集。此集合内含出现于 S1 但不出现于 S2 的每一个元素。

* 对称差集 `set_symmetric_difference`

算法 `set_symmetric_difference` 可构造 S1、S2 之对称差集。此集合内容`出现于 S1 但不出现于 S2` 以及 `出现于 S2 但不出现 S1` 的每一个元素。

> `heap` 算法

