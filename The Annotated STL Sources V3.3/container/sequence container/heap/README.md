## heap

heap 的数据结构就是二叉堆(完全二叉树)。

heap 又分 max-heap(最大堆) 和 min-heap(最小堆)。

max-heap(最大堆)：特点是根节点是最大值，每个节点的键值都大于或等于其子节点键值。

min-heap(最小堆)：特点是根节点是最小值，每个节点的键值都小于或等于其子节点键值。

## heap 内部实现

heap 其实就是一个完全二叉树，怎么保存树节点的值，可以用 array 来储存所有节点，由于 array 无法动态改变大小，就用 vector 代替。

SGI STL 的 heap 默认是 max-heap，底层容器为 vector。

完全二叉树使用层次遍历方式，将树的节点依次存储在 vector 容器中，根节点位于 vector 的头部；当 heap 中的某个节点位于 vector 的 i 处，
其左子节点位于 vector 的 2i 处，右子节点位于 vector 的 2i+1 处；然后调整为 heap。

## heap 操作实现

* push_heap 是把新元素插入到底层 vector 的 end() 处，然后做 shift up 调整，使其满足 heap 的特性。

* pop_heap 是将根节点取出(位于 vector 的 begin() 处)，然后做 shift down 调整，使其满足 heap 的特性。
  特别注意，pop_heap 只是将根节点的值移动到 vector 的尾部，并没有取出来，vector 的 `[first, last-1)` 位置元素满足 heap 特性；取出使用底部容器 vector 的 pop_back() 操作函数。

* sort_heap 内部实现就是一直调用 pop_heap，知道迭代器 last 指向 迭代器 first 为止。

* make_heap 是将一个完全二叉树存储在 vector 中，然后调整为一个 heap，内部调用 __adjust_heap 实现。

## heap 没有迭代器

因为 heap 遵循某种规律，所以不提供遍历功能，没有迭代器操作。
