// 测试一个函数参数为函数指针，返回为函数指针
#include <iostream>
using namespace std;
// 参数
void param() {
    cout << "call param()" << endl;
}

/*
 * @param void (*f)() 函数指针
 * @return void (*f)() 函数指针
 */
void (*set_malloc_handler( void (*__f)() ))(  ) {
    cout << "call __f()" << endl;
    __f();
    return __f;
}

int main()
{
    void (*func)() = set_malloc_handler(param);
    cout << "call return func()" << endl;
    func();
    return 0;
}