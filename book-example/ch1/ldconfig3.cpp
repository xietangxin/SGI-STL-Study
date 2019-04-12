// file ldconfig3.cpp
// 测试在 class tempalte 中拥有 static data members
// test __STL_STATIC_TEMPLATE_MEMBER_BUG, defined  in <stl_config.h>
// g++ test


#include <iostream>

using namespace std;

template <typename T>
class testClass {
public:
	static int _data;
};

// 为static data members 进行定义(配置内存)， 并设定初值
template<> int testClass<int>::_data = 1;
template<> int testClass<char>::_data = 2;

int main()
{
#ifdef __STL_STATIC_TEMPLATE_MEMBER_BUG
	cout << "__STL_STATIC_TEMPLATE_MEMBER_BUG defined" << endl;
#else
	cout << "__STL_STATIC_TEMPLATE_MEMBER_BUG undefined" << endl;
#endif

	cout << testClass<int>::_data << endl; // 1
	cout << testClass<char>::_data << endl; // 2

	testClass<int> obji1, obji2;
	testClass<char> objc1, objc2;
	cout << obji1._data << endl; // 1
	cout << obji2._data << endl; // 1
	cout << objc1._data << endl; // 2
	cout << objc2._data << endl; // 2

	obji1._data = 3;
	objc2._data = 4;

	cout << obji1._data << endl; //3
	cout << obji2._data << endl; //3
	cout << objc1._data << endl; //4
	cout << objc2._data << endl; //4
	return 0;
}
