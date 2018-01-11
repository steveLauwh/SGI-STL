## 算法(algorithm)

![](https://github.com/steveLauwh/SGI-STL/raw/master/The%20Annotated%20STL%20Sources%20V3.3/Other/STLAlgorithm.png)

算法：各种常用算法如 sort，search，copy，erase 等，从实现的角度来看，STL 算法是一种 function template。

所有泛型算法的前两个参数都是一对迭代器，STL 习惯使用前闭后开的区间，`[first, last)`。

最后一个元素的下一位置，称为 end()。

数值的传递由 pass-by-value 改为 pass-by-reference，好处是，在模板中，参数的类型可以任意，当对象一大，传递成本便会上升，所以用 pass-by-reference 可以节省空间。

### 数值算法 <stl_numeric.h>

STL 将数值算法的内部实现放在 <stl_numeric.h> 中，用户调用数值算法的接口，需要包含 <numeric> 头文件。
  
> **元素累加 `accumulate`**

算法 `accumulate` 用来计算 init 和 `[first, last)` 内所有元素的总和。

> **相邻元素的差值 `adjacent_difference`**

算法 `adjacent_difference` 用来计算 `[first, last)` 中相邻元素的差值。

> **内积 `inner_product`**

算法 `inner_product` 计算 `[first1, last1)` 和 `[first2, first2 + (last1 - first1))` 的一般内积。 

> **局部求和 `partial_sum`**

算法 `partial_sum` 用来计算局部求和。

> **幂次方 `power`**

算法 `power` 用来计算某数的 n 幂次方。

> **递增 `iota`**

在某区间 `[first, last)` 填入某指定值 `value` 的递增序列。

### 基本算法 <stl_algobase.h>

> **判断两个区间是否相等 `equal`**

如果两个序列在 `[first, last)` 区间内相等，`equal()` 返回 true。

注意，如果第二个序列的元素比较多，多出来的元素不予考虑，只要与第一个序列的元素相等，就返回 true。

> **改填元素 `fill`**

将 `[first, last)` 内的所有元素改填新值。

> **改填元素的值 n 次 `fill_n`**

将 `[first, last)` 内的前 n 个元素改填新值，返回的迭代器指向被填入的最后一个元素的下一位置。

> **元素互换 `iter_swap`**

将两个 Forwarditerators 所指的对象对调。

> **以字典顺序进行比较 `lexicographical_compare`**

以 "字典排列方式" 对两个序列 `[first1, last1)` 和 `[first2, last2)` 进行比较。

> **最大值 `max`**

取两个对象的较大值。

> **最小值 `min`**

取两个对象的最小值。

> **找出不匹配的点 `mismatch`**

用来平行比较两个序列，指出两者之间的第一个不匹配点。

> **交换 `swap`**

该函数用来交换两个对象的内容。

> **复制 `copy`**

`copy` 算法可将输入区间 `[first, last)` 内的元素复制到输出区间 `[result, result + (last-first))` 内。

> **逆向复制 `copy_backward`**

将 `[first, last)` 区间内的每一个元素，以逆行的方向复制到以 `result-1` 为起点，方向亦为逆行的区间上。

### set 相关算法

* 并集 `set_union`

算法 `set_union` 可构造 S1、S2 之并集(S1 U S2)，此集合内含 S1 或 S2 内的每一个元素。其中 S1、S2 及其并集都是以排序区间表示。

* 交集 `set_intersection`

算法 `set_intersection` 可构造 S1、S2 之交集。

* 差集 `set_difference`

算法 `set_difference` 可构造 S1、S2 之差集。此集合内含出现于 S1 但不出现于 S2 的每一个元素。

* 对称差集 `set_symmetric_difference`

算法 `set_symmetric_difference` 可构造 S1、S2 之对称差集。此集合内容`出现于 S1 但不出现于 S2` 以及 `出现于 S2 但不出现 S1` 的每一个元素。

### heap 算法

头文件 <stl_heap.h>

* make_heap() 建堆
* pop_heap() 从堆中取出一个元素
* push_heap() 将一个元素推进堆内
* sort_heap() 对堆排序

### 其它算法 <stl_algo.h>

定义于 SGI <stl_algo.h> 内的所有算法。

> **查找相邻而重复的元素 `adjacent_find`**

对一个序列，查找相邻元素值相等的第一个元素。

> **计数 `count`** 

将 `[first, last)` 区间内的每一个元素拿来和指定值 `value` 比较，并返回与 `value` 相等的元素个数。

> **在特定条件下计数 `count_if`**

将指定操作(一个仿函数) pred 实施于 `[first, last)` 区间内的每一个元素身上，并将造成 pred 计算结果为 true 的所有元素的个数返回。

> **循环查找 `find`**

循环查找 `[first, last)` 内的所有元素，找出第一个匹配条件的，返回指向该元素的迭代器。

> **在特定条件下循环查找 `find_if`**

根据指定的 pred 运算条件，循环查找 `[first, last)` 内的所有元素，找出第一个令 pred 运算结果为 true，返回指向该元素的迭代器。

> **查找某个子序列的最后一次出现点 `find_end`**

在序列一 `[first, last)` 所涵盖的区间中，查找序列二 `[first, last)` 的最后一个出现点。

> **查找某些元素的第一次出现点 `find_first_of`**

本算法以 `[first2, last2)` 区间内的某些元素作为查找目标，寻找在 `[first1, last1)` 区间内的第一次出现地点。

> **对区间内的每一个元素进行某操作 `for_each`**

将仿函数 f 作用于 `[first, last)` 区间内的每一个元素上。

> **以特定操作之运算结果填充特定区间内的元素 `generate`**

将仿函数 gen 的运算结果赋值给 `[first, last)` 区间内的所有元素上。 

> **以特定操作之运算结果填充 n 个元素内容 `generate_n`**

将仿函数 gen 的运算结果填写在从迭代器 first 开发的 n 个元素身上。

> **应用于有序区间 `includes`**

S1 和 S2 必须是有序集合，其中的元素可以重复，判断 S1 是否包含于 S2。includes 算法可供用户选择采用 less 或 greater 进行两元素的大小比较。

> **最大值所在位置 `max_element`**

这个算法返回一个迭代器，指向序列之中数值最大的元素。

> **应用于有序区间的合并操作 `merge`**

将两个经过排序的集合 S1 和 S2，合并起来置于另一段空间。所得结果也是一个有序序列。

> **最小值所在位置 `min_element`**

这个算法返回一个迭代器，指向序列之中数值最小的元素。

> **分割 `partition`**

`partition` 将区间 `[first, last)` 中的元素重新排列。所有被一元条件运算 `pred` 判定为 true 的元素，都会被放在区间的前段，被判定为 false 的元素，都会被放在区间的后段。

如果需要保留原始相对位置，应使用 `stable_partition`。

> **移除并不删除 `remove`**

移除 `[first, last)` 之中所有与 value 相等的元素，这一算法并不真正从容器中删除那些元素，而是将每一个不与 value 相等的元素轮番赋值给 first 之后的空间。

> **移除某类元素并将结果复制到另一容器 `remove_copy`**

移除 `[first, last)` 之中所有与 value 相等的元素。它并不真正从容器中删除那些元素，而是将结果复制到一个以 result 标示起始位置的容器身上。

> **有条件地删除某类元素 `remove_if`**

移除 `[first, last)` 区间内所有被仿函数 pred 认定为 true 的元素，每一个不符合 pred 条件的元素都会被轮番赋值给 first 之后的空间。

> **有条件地删除某类元素并将结果复制到另一容器 `remove_copy_if`**

移除 `[first, last)` 区间内所有被仿函数 pred 认定为 true 的元素，它并不真正从容器中删除那些元素，而是将结果复制到一个以 result 标示起始位置的容器身上。

> **替换某类元素 `replace`**

将 `[first, last)` 区间内的所有 old_value 都以 new_value 取代。

> **替换某类元素，并将结果复制到另一个容器 `repalce_copy`**

唯一不同的是新序列会被复制到 result 所指的容器中。

> **有条件地替换 `replace_if`**

将 `[first, last)` 区间内的所有被 pred 评估为 true 的元素，都以 new_value 取而代之。

> **有条件地替换，并将结果复制到另一个容器 `replace_copy_if`**

行为与 `replace_if()` 类似，新序列会被复制到 result 所指的区间内。

> **反转元素次序 `reverse`**

将序列 `[first, last)` 的元素在原容器中颠倒重排。

> **反转元素次序并将结果复制到另一个容器 `reverse_copy`**

行为与 `reverse()` 类似，新序列会被复制到 result 所指的容器中。

> **旋转 `rotate`**

将 `[first, middle)` 内的元素和 `[middle, last)` 内的元素互换，middle 所指的元素会成为容器的第一个元素。

> **旋转，并将结果复制到另一个容器 `rotate_copy`**

行为与 `rotate_copy()` 类似，新序列会被复制到 result 所指的容器中。

> **查找某个子序列 `search`**

在序列一 `[first1, last1)` 所涵盖的区间中，查找序列二 `[first2, last2)` 的首次出现点。

> **查找连续发生 n 次的子序列 `search_n`**

在序列 `[first, last)` 所涵盖的区间中，查找连续 count 个符合条件之元素所形成的子序列，并返回一个迭代器指向该子序列起始处。

> **指定区间交换 `swap_ranges`**

将 `[first1, last1)` 区间内的元素与从 first2 开始、个数相同的元素互相交换。这两个序列可位于同一容器中，也可位于不同的容器中。

> **以两个序列为基础，交互作用产生第三个序列 `transform`**

transform() 两个版本都执行结果放进迭代器 result 所标示的容器中。

> **将重复的元素删除，只保留一个 `unique`**

算法 unique 能够移除重复的元素。每当在 `[first, last)` 内遇到重复元素群，它便移除该元素群中第一个以后的所有元素。

> **将重复的元素删除，只保留一个， 并复制 result 中`unique_copy`**

算法 unique_copy 可从 `[first, last)` 中将元素复制到以 result 开头的区间上。

> **lower_bound (应用于有序区间)**

二分查找，在已排序的 `[first, last)` 中的寻找元素 value，返回位置。

> **upper_bound (应用于有序空间)**

二分查找，在已排序的 `[first, last)` 中的寻找元素 value，与 `lower_bound` 区别是返回查找值的位置。

> **二分查找 `binary_search (应用于有序空间)`**

二分查找法，在已排序的 `[first, last)` 中的寻找元素 value，查找到，返回 true，否则 false。

> **求下一个排列组合 `next_permutation`**

`next_permutation()` 获取 `[first, last)` 所标示之序列的下一个排列组合。

实现原理：

在当前序列中，从尾端往前寻找两个相邻元素，前一个记为 `*i`，后一个记为 `*ii`，并且满足 `*i < *ii`。然后再从尾端寻找另一个元素 `*j`，如果满足 `*i < *j`，即将第 i 个元素与第 j 个元素对调，并将第 ii 个元素之后（包括ii）的所有元素颠倒排序，即求出下一个序列了。

> **求上一个排列组合 `prev_permutation`**

`prev_permutation()` 获取 `[first, last)` 所标示之序列的上一个排列组合。

实现原理：

在当前序列中，从尾端往前寻找两个相邻元素，前一个记为 `*i`，后一个记为 `*ii`，并且满足 `*i > *ii`。然后再从尾端寻找另一个元素 `*j`，如果满足 `*i > *j`，即将第 i 个元素与第 j 个元素对调，并将第 ii 个元素之后（包括ii）的所有元素颠倒排序，即求出上一个序列了。

> **随机重排元素 `random-shuffle`**

这个算法将 `[first, last)` 的元素次序随机重排, 在 N！种可能的元素排列顺序中随机选出一种，此处 N 为 last-first。

> **局部排序 `partial_sort/partial_sort_copy`**

本算法接受一个 middle 迭代器(位于序列 `[first, last) 之内`)，然后重新安排 `[first, last)`，使序列中的 middle-first 个最小元素以递增顺序排序，置于 `[first, middle)`内。其余 `last-middle` 个元素安置于 `[middle, last)` 中，不保证有任何特定顺序。

> **排序算法 sort**

STL 的 sort 算法，数据量大时采用 Quick Sort，分段递归排序，当数据量小于某个门槛(5-20)，就改用 Insertion Sort。

**Insertion Sort**

插入排序是以双层循环的形式进行。时间复杂度为 O(N^2)。

将一个记录插入到已排序好的有序表中，从而得到一个新，记录数增1的有序表。即：先将序列的第1个记录看成是一个有序的子序列，然后从第2个记录逐个进行插入，直至整个序列有序为止。

**Quick Sort**

平均时间复杂度为 O(NlogN)，最坏情况下将达 O(N^2)。

STL 早期采用 Quick Sort，现在 SGI STL 改用 IntroSort(极类似 median-of-three QuickSort 的一种排序算法)。

递归

Median-of-Three(三点中值) 中间值

Partitioning 分割

**SGI STL sort**

混合式排序算法，Introspective Sorting，当做 Partitioning 操作，有恶化为二次行为的倾向时，改用 Heap Sort，使其效率维持在 Heap Sort 的 O(NlogN)。

用 __lg() 控制分割恶化的情况：

```cpp
// 找出 2^k <= n 的最大值 k
template <class size>
inline Size __lg(Size n) {
    Size k;
    for (k = 0; n > 1; n >>= 1)
        ++k;
        
    return k;
}
```
最多允许分割 2k 层；

混合式排序思想：

* 先判断序列大小，当大于阈值 `__stl_threshold(16)`，再检查分割层次，如果分割层次超过指定值 0，就改用 Heap Sort完成；
* 在大于阈值 `__stl_threshold(16)`，分割层次不为 0，就继续使用 Quick Sort；
* 如果小于阈值，则用插入排序；

> **equal_range(应用于有序区间)**

算法 `equal_range` 是二分查找法的一个版本，试图在已排序的 `[first, last)` 中寻找 value。

返回一个上下区间。

> **inplace_merge(应用于有序区间)**

合并 并且 就地排序

> **nth_element**

使第 n 大元素处于第 n 位置（从0开始,其位置是下标为 n的元素），并且比这个元素小的元素都排在这个元素之前，比这个元素大的元素都排在这个元素之后，但不能保证他们是有序的。

> **归并排序 merge sort**

Merge Sort 的复杂度为 O(NlogN)。需要借用额外的内存。底层是调用 `inplace_merge` 实现。
