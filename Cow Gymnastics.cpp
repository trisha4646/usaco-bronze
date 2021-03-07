/*
 USACO 2019 December Contest, Bronze
 Problem 1. Cow Gymnastics
 http://www.usaco.org/index.php?page=viewproblem2&cpid=963
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin ("gymnastics.in");
    ofstream fout ("gymnastics.out");
    int n, k;
    fin >> k >> n;
    int rankings[k][n];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            fin >> rankings[i][j];
        }
    }
       
    int totalconsistencies = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            int pairconsistencies = 0;
            for (int p = 0; p < k; p++) {
                int index_i = 0, index_j = 0;
                for (int b = 0; b < n; b++) {
                    if (rankings[p][b] == i) {
                        index_i = b;
                    }
                    else if (rankings[p][b] == j) {
                        index_j = b;
                    }
                }
                if (index_i < index_j) {
                    pairconsistencies++;
                }
            }
            if (pairconsistencies == 0 || (pairconsistencies == k)) {
                totalconsistencies++;
            }
        }
    }
    
    fout << totalconsistencies << endl;
    return 0;
}

