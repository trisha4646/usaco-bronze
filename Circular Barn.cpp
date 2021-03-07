/*
 USACO 2016 February Contest, Bronze
 Problem 2. Circular Barn
 http://www.usaco.org/index.php?page=viewproblem2&cpid=616
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin ("cbarn.in");
    ofstream fout ("cbarn.out");
    
    int n;
    fin >> n;
    int roomlimits[n];
    int optiontotal = 0, total = 2147483647;
    
    int t;
    for (int j = 0; j < n; j++) {
        fin >> t;
        roomlimits[j] = t;
    }
    
    for (int i = 0; i < n; i++) {
        int b = 0;
        for (int a = (i); a < (n+i); a++) {
            optiontotal += roomlimits[(a%n)]*b;
            b++;
        }
        total = min(total, optiontotal);
        optiontotal = 0;
    }
    
    fout << total << endl;
    return 0;
}
