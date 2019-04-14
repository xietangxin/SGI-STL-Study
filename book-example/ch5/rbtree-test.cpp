#include <iostream>

#include "tree.h"
#include "function.h"

using namespace std;

int main()
{
    rb_tree<int, int, identity<int>, less<int>> itree;
    cout << itree.size << endl;
}