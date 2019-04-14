#include <iostream>

#include "stl_tree.h"
#include "stl_function.h"

using namespace std;

int main()
{
    _Rb_tree<int, int, _Identity<int>, less<int> > itree;
    cout << itree.size() << endl;
}
