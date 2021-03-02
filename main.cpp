#include "setSimple.hpp"
#include <iostream>

using namespace std;

int main()
{
    setSimple<10> set;
    setSimple<10> set2;

    set.insert(1);
    set2.insert(2);
    set.insert(9);
    setSimple<10> set3 = set.sum(set2);

    cout << set3 << endl;

    for (int i : set3.simpleSet)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}