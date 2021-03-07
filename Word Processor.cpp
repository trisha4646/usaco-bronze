/*
 USACO 2020 January Contest, Bronze
 Problem 1. Word Processor
 http://www.usaco.org/index.php?page=viewproblem2&cpid=987
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin ("word.in");
    ofstream fout ("word.out");
    int n, k;
    fin >> n >> k;
    
    string essay[n];
    string t;
    for (int i = 0; i < n; i++) {
        fin >> t;
        essay[i] = t;
    }
    
    int currentvalue = 0;
    fout << essay[0];
    currentvalue += essay[0].length();
    
    for (int i = 1; i < n; i++) {
        if (currentvalue + essay[i].length() <= k) {
            fout << " " << essay[i];
            currentvalue += essay[i].length();
        }
        else {
            fout << "\n" << essay[i];
            currentvalue = essay[i].length();
        }
    }
    return 0;
}
