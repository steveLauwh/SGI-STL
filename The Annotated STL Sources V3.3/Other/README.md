## Other

包含 STL 六大组件之外的内容，如环境配置文件(stl_config.h)。

## 环境配置 stl_config.h

* __STL_STATIC_TEMPLATE_MEMBER_BUG 模板类拥有静态数据成员

为静态数据成员进行定义，并设初始值。
```cpp
template <typename T>
class testClass {
public:
    static int _data;
};
template<> int testClass<int>::_data = 1;
template<> int testClass<char>::_data = 2;
```
