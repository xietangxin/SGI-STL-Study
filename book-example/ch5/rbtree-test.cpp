// 编译程序链接SGI-STL源码，编译问题很多
// 在linux中编译 指定 /usr/include/c++/5/ 中的头文件，编译时成功的
#include <iostream>

#include "stl_tree.h"
#include "stl_function.h"

int main()
{
    _Rb_tree<int, int, _Identity<int>, less<int>>
        itree;
    cout << itree.size() << endl;
    return 0;
}
