/*
 USACO 2017 January Contest, Bronze
 Problem 3. Cow Tipping
 http://www.usaco.org/index.php?page=viewproblem2&cpid=689
*/

#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
int n;
 
int main() {
    ifstream fin("cowtip.in");
    ofstream fout ("cowtip.out");
    fin >> n;
    int cowpos[n][n];
    
    for (int i = 0; i < n; i++) {
        string line;
        fin >> line;
        for (int j = 0; j < n; j++) {
            cowpos[i][j] = stoi(line.substr(j, 1));
        }
    }
    
    int count = 0;
    for (int i = n-1; i > -1; i--) {
        for (int j = n-1; j > -1; j--) {
            if (cowpos[i][j] == 1) {
                for (int a = 0; a <= i; a++) {
                    for (int b = 0; b <= j; b++) {
                        if (cowpos[a][b] == 0) {
                            cowpos[a][b] = 1;
                        }
                        else if (cowpos[a][b] == 1) {
                            cowpos[a][b] = 0;
                        }
                    }
                }
                count++;
            }
        }
    }
    fout << count << endl;
    return 0;
}

