// file: 1config3.cpp
// 测试在 class template中 拥有 static data members.
// test __STL_STATIC_TEMPLATE_MEMBER_BUG, defined in <stl_config.h>
// ref. C++ Primer 3/e, p.839
// vc6[o] cb4[x] gcc[o]
// cb4 does not support static data member initialization.

// 如果编译器无法处理static member of template classes(模板类静态成员)就定义。
// 即对于模板类中，模板类型不同时的静态变量不同。

#include <iostream>
using namespace std;

// C++中的模板编译期间会实例化, 使用这个工具可以查看实例化的结果: https://cppinsights.io/
template<typename T>
class TestClass {
public:
	// 这里的static声明int是一个静态变量, 未来所有实例化的对象都会共享同一个变量
	static int _data;
};

/**
 * template<>
 * class TestClass<int> {
 *   public: 
 *   = 所有的TestClass<int>类的实例共享同一个遍历
 *   static int _data;
 * };
 * 
 * template<>
 * class TestClass<char> {
 *   public: 
 *   = 所有的TestClass<char>类的实例共享同一个遍历
 *   static int _data;
 * };
*/

// C++模板特例化, 这两行代码会首先实例化出上面的模板实例, 然后再赋值
template<>
int TestClass<int>::_data = 1;

template<>
int TestClass<char>::_data = 1;

int main() {

	cout << TestClass<int>::_data << endl;
	cout << TestClass<char>::_data << endl;

	TestClass<int> obji1, obji2;
	TestClass<char> objc1, objc2;
	cout << obji1._data << " " << obji2._data << endl;
	cout << objc1._data << " " << objc2._data << endl;

	// obji1和obji2共享同一个data, 所以任意一个修改, 其他的都会改变
	obji1._data = 3;
	// 同理, objc2修改data, objc1的值也会改变
	objc2._data = 4;

	cout << obji1._data << " " << obji2._data << endl;
	cout << objc1._data << " " << objc2._data << endl;
}