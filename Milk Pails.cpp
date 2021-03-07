/*
 USACO 2016 February Contest, Bronze
 Problem 1. Milk Pails
 http://www.usaco.org/index.php?page=viewproblem2&cpid=615
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    ifstream fin ("pails.in");
    ofstream fout ("pails.out");
    int x, y, m;
    fin >> x >> y >> m;
    
    int dx;
    dx = floor(m/x);
    int totalpossiblem = 0;
    int remaindery = 0;
    
    for (int i = 0; i <= dx; i++) {
        remaindery = floor((m-(i*x))/y);
        totalpossiblem = max(totalpossiblem, i*x + remaindery*y);
    }
    
    fout << totalpossiblem << endl;
    return 0;
}
