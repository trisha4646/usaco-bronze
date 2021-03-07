/*
 USACO 2015 December Contest, Bronze
 Problem 1. Fence Painting
 http://www.usaco.org/index.php?page=viewproblem2&cpid=567
*/

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
 
int main() {
    ifstream fin ("paint.in");
    ofstream fout ("paint.out");
    int a, b, c, d;
    fin >> a >> b >> c >> d;
    bool fence[101] = {false};
    
    for (int i = a; i < b; i++) {
        fence[i] = true;
    }
    for (int i = c; i < d; i++) {
        fence[i] = true;
    }
    
    int count = 0;
    for (int i = 0; i <= 100; i++) {
        if (fence[i] == true) {
            count++;
        }
    }
    
    fout << count << endl;
    return 0;
}
