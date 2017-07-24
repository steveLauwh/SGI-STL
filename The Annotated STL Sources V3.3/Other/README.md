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
## 临时对象的产生与作用

临时对象就是一种无名对象。它的出现如果不在程序员的预期之下，往往造成效率上的负担。

刻意制造临时对象的方法是在类型名称后加一对小括号，并可指定初值，例如 Shape(3, 5) 或 int(8)，其意义相当于调用相应的 constructor 且不指定对象名称。

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// 仿函数或函数对象
template <typename T>
class print
{
public:
    void operator() (const T& elem)
    {
        cout << elem << ' ';
    }
};

int main()
{
    int ia[6] = {0, 1, 2, 3, 4, 5};
    vector<int> iv(ia, ia+6);
    
    // print<int>() 是一个临时对象，不是一个函数调用操作
    for_each(iv.begin(), iv.end(), print<int>());
}
```

## 静态常量整数成员在 class 内部直接初始化

在 class 内含 const static integral data member，那么根据 C++ 标准规格，可以在 class 之内直接给予初值。所谓 integral 泛指所有整数类型，不单只是指 int。

```cpp
template <typename T>
class testClass
{
public:
    static const int _datai = 5;
    static const long _datal = 3L;
    static const char _datac = 'c';
};
```

## increment / decrement /derefrence 操作符

increment/derefrence 操作符在迭代器的实现占有很重要地位。

```cpp
class INT
{
public:
    INT(int i) : m_i(i) {};
    
    INT& operator++() {
        ++(this->m_i);
        return *this;
    }
    
    const INT operator++(int) {
        INT temp = *this;
        ++(*this);
        return temp;
    }
    
    INT& operator--() {
        --(this->m_i);
        return *this;
    }
    
    const INT operator--(int) {
        INT temp = *this;
        --(*this);
        return temp;
    }
    
    int& operator*() const {
        return (int&)m_i;
    }

private:
    int m_i;
};
```

## 前闭后开区间表示法 [)

任何一个 STL 算法，都需要获得一对迭代器所标示的区间，该区间为前闭后开区间，以 [first, last) 表示。

整个实际范围从 first 开始，直到 last-1。

## Function call 操作符(operator())

C语言中，函数指针的缺点：无法持有自己的状态，也无法达到组件技术中的可适配性。

仿函数：使用起来就像函数一样的东西。如果针对某个 class 进行 operator() 重载，它就成为一个仿函数。

```cpp
#include <iostream>
using namespace std;

template <class T>
struct plus {
    T operator() (const T& x, const T& y) const {
        return x + y;
    }    
};

template <class T>
struct minus {
    T operator() (const T& x, const T& y) const {
        return x - y;
    }    
};

int main()
{
    // 以下产生仿函数对象
    plus<int> plusobj;
    minus<int> minusobj;
    
    cout << plusobj(3, 5) << endl;
    cout << minusobj(3, 5) << endl;
    
    // 仿函数的临时对象
    cout << plus<int>()(43, 50) << endl;
    cout << minus<int>()(43, 50) << endl;
    
    return 0;
}
```
