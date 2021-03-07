/*
 USACO 2019 January Contest, Bronze
 Problem 2. Sleepy Cow Sorting
 http://www.usaco.org/index.php?page=viewproblem2&cpid=892
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int n;
 
int main() {
    ifstream fin("sleepy.in");
    ofstream fout ("sleepy.out");
    fin >> n;
    
    int order[n];
    for (int i = 0; i < n; i++) {
        fin >> order[i];
    }
    
    int count = 0;
    for (int i = n-1; i > 0; i--) {
        if (order[i] > order[i-1]) {
            count++;
        }
        else {
            break;
        }
    }
    
    fout << (n-count)-1 << endl;
    return 0;
}
