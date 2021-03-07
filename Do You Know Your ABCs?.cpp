/*
 USACO 2020 December Contest, Bronze
 Problem 1. Do You Know Your ABCs?
 http://www.usaco.org/index.php?page=viewproblem2&cpid=1059
*/

#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main() {
    int a, b, c, d;
    multiset<int> values;
    for (int i = 0; i < 7; i++) {
        cin >> a;
        values.insert(a);
    }
    
    int j = 0;
    for (auto it = values.begin(); it != values.end(); it++) {
        if (j == 0) {
            a = *it;
        }
        else if (j == 1) {
            b = *it;
        }
        else if (j == 6){
            d = *it;
        }
        j++;
    }
    
    c = ((d-a) - b);
    cout << a << " " << b << " " << c;
    return 0;
}
