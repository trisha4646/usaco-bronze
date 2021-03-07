/*
 USACO 2018 February Contest, Bronze
 Problem 1. Teleportation
 http://www.usaco.org/index.php?page=viewproblem2&cpid=807
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin ("teleport.in");
    ofstream fout ("teleport.out");
    int a, b, c, d;
    fin >> a >> b >> c >> d;
    
    int temp;
    if (b < a) {
        temp = b;
        b = a;
        a = temp;
    }
    if (d < c) {
        temp = d;
        d = c;
        c = temp;
    }
    
    int normaldistance = b - a;
    int teleportdistance = (abs((c-a))) + (abs((d-b)));
    
    if (normaldistance < teleportdistance) {
        fout << normaldistance;
    } else {
        fout << teleportdistance;
    }

    return 0;
}

