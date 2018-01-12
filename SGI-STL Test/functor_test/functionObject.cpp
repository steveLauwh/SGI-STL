#include <iostream>
#include <functional>

using namespace std;

int main()
{
	// 算法运算函数对象
	plus<int> plusobj;
	minus<int> minusobj;
	multiplies<int> multipliesobj;
	divides<int> dividesobj;
	modulus<int> modulusobj;
	negate<int> negateobj;

	cout << "Arithmetic function objects: " << endl;
	cout << plusobj(3, 5) << endl;
	cout << minusobj(3, 5) << endl;
	cout << multipliesobj(3, 5) << endl;
	cout << dividesobj(3, 5) << endl;
	cout << modulusobj(3, 5) << endl;
	cout << negateobj(3) << endl;

	// 以函数对象的临时对象履行函数功能 functor<T>()
	cout << endl;
	cout << plus<int>()(3, 5) << endl;
	cout << minus<int>()(3, 5) << endl;
	cout << multiplies<int>()(3, 5) << endl;
	cout << divides<int>()(3, 5) << endl;
	cout << modulus<int>()(3, 5) << endl;
	cout << negate<int>()(3) << endl;

	// 关系运算函数对象
	equal_to<int> equal_to_obj;
	not_equal_to<int> not_equal_to_obj;
	greater<int> greaterobj;
	greater_equal<int> greater_equal_obj;
	less<int> less_obj;
	less_equal<int> less_equal_obj;
	
	cout << "Relational function objects: " << endl;
	cout << equal_to_obj(3, 5) << endl;
	cout << not_equal_to_obj(3, 5) << endl;
	cout << greaterobj(3, 5) << endl;
	cout << greater_equal_obj(3, 5) << endl;
	cout << less_obj(3, 5) << endl;
	cout << less_equal_obj(3, 5) << endl;

	// 以函数对象的临时对象履行函数功能 functor<T>()
	cout << endl;
	cout << equal_to<int>()(3, 5) << endl;
	cout << not_equal_to<int>()(3, 5) << endl;
	cout << greater<int>()(3, 5) << endl;
	cout << greater_equal<int>()(3, 5) << endl;
	cout << less<int>()(3, 5) << endl;
	cout << less_equal<int>()(3, 5) << endl;

	// 逻辑运算函数对象
	logical_and<int> and_obj;
	logical_or<int> or_obj;
	logical_not<int> not_obj;
	
	cout << "Logical function objects: " << endl;
	cout << and_obj(true, false) << endl;
	cout << or_obj(true, false) << endl;
	cout << not_obj(false) << endl;

	// 以函数对象的临时对象履行函数功能 functor<T>()
	cout << endl;
	cout << logical_and<int>()(true, false) << endl;
	cout << logical_or<int>()(true, false) << endl;
	cout << logical_not<int>()(false) << endl;

	return 0;
}
