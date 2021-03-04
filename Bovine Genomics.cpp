/*
 USACO 2017 US Open Contest, Bronze
 Problem 2. Bovine Genomics
 http://www.usaco.org/index.php?page=viewproblem2&cpid=736
*/

#include <iostream>
#include <fstream>
#include <set>
 
using namespace std;
int n, m;
 
set<char> spottedcowschars;
set<char> plaincowschars;
 
bool testsimilars() {
    for (auto sc : spottedcowschars) {
        for (auto pc : plaincowschars) {
            if (sc == pc) {
                return false;
            }
        }
    }
    return true;
}
 
 
int main() {
    ifstream fin ("cownomics.in");
    ofstream fout ("cownomics.out");
    fin >> n >> m;
    
    char spottedcows[n][m];
    char plaincows[n][m];
 
    string t;
    for (int i = 0; i < n; i++) {
        fin >> t;
        for (int j = 0; j < m; j++) {
            spottedcows[i][j] = t[j];
        }
    }
    for (int i = 0; i < n; i++) {
        fin >> t;
        for (int j = 0; j < m; j++) {
            plaincows[i][j] = t[j];
        }
    }
    
    int total = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            spottedcowschars.insert(spottedcows[j][i]);
            plaincowschars.insert(plaincows[j][i]);
        }
        if (testsimilars()) {
            total++;
        }
        spottedcowschars.clear();
        plaincowschars.clear();
    }
    fout << total << endl;
    return 0;
}
