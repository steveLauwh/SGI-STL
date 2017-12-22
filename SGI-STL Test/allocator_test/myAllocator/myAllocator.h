#ifndef MY_ALLOCATOR_H
#define MY_ALLOCATOR_H

#include <new>      // placement new
#include <cstddef>  // ptrdiff_t, size_t
#include <cstdlib>  // exit()
#include <climits>  // UINT_MAX
#include <iostream> // cerr

// 一个简单的空间配置器
namespace myAllocator
{
	// 空间的分配，可以存储 size 个 T 对象
	template <class T>
	inline T* _allocate(ptrdiff_t size, T*) {
		std::set_new_handler(0);  // 分配失败，抛出std::bad_alloc

	    // 空间的分配实现，调用 ::operator new() 全局函数
		T* tmp = (T*)(::operator new((size_t)(size * sizeof(T))));

		if (tmp == 0) {
			std::cerr << "out of memory" << std::endl;
			exit(1);
		}

		return tmp;
	}
	
	// 空间的释放，调用 ::operator delete() 全局函数
	template <class T>
	inline void _deallocate(T* buffer) {
		::operator delete(buffer);
	}

	// 对象的构造
	template <class T1, class T2>
	inline void _construct(T1* p, const T2& value)
	{
		new(p) T1(value); // placement new
	}
	
	// 对象的析构
	template <class T>
	inline void _destroy(T* ptr) {
		ptr->~T();
	}

	// 提供外部使用 allocator
	template <class T>
	class allocator {
	public:
		// 对象的类型
		typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type; // ptrdiff_t 是两个指针相减结果的有符号整数类型

		// 嵌套 allocator
		template <class U>
		struct rebind {
			typedef allocator<U> other;
		};
		
		/***
		 * 以下四个函数提供外部使用，空间的分配和释放，对象的构造和析构
		 */
		pointer allocate(size_type n, const void* hint = 0) {
			return _allocate((difference_type)n, (pointer)0);
		}

		void deallocate(pointer p, size_type n) {
			_deallocate(p);
		}

		void construct(pointer p, const T& value) {
			_construct(p, value);
		}

		void destroy(pointer p) {
			_destroy(p);
		}

		// 返回某个对象的地址
		pointer address(reference x) {
			return (pointer)&x;
		}

		// 返回某个 const 对象的地址
		const_pointer const_address(const_reference x) {
			return (const_pointer)&x;
		}
		
		// 返回可成功分配的最大量  
		size_type max_size() const {  
			return size_type(UINT_MAX/sizeof(T)); // UINT_MAX 是 unsigned long 及 unsigned long long 的最大值
		}
	};
}

#endif
