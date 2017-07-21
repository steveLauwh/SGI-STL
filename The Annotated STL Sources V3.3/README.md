## STL 六大组件

「STL 六大组件」：其交互关系是 Container 通过 Allocator 取得数据储存空间，Algorithm 通过 Iterator 存取 Container 内容，
 Functor 可以协助 Algorithm 完成不同的策略变化，Adapter 可以修饰或套接 Functor、Iterator。
