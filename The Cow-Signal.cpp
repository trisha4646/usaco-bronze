/*
 USACO 2016 December Contest, Bronze
 Problem 3. The Cow-Signal
 http://www.usaco.org/index.php?page=viewproblem2&cpid=665
*/

#include <iostream>
#include <fstream>
using namespace std;
 
int main() {
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");
    //get the three variables, and save the signal design into a signal array of [m][n]
    int m, n, k;
    fin >> m >> n >> k;
    char signal[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> signal[i][j];
        }
    }
    
    //array that will hold the new signal design once it's made; will have the scaled size
    char newsignal[m*k][n*k];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int a = j*k; a < (j*k)+k; a++) {
                newsignal[i*k][a] = signal[i][j];
            }
        }
    }
    
    for (int i = 0; i < m*k; i += k) {
        for (int j = 0; j < n*k; j++) {
            for (int a = 1; a < k; a++) {
                newsignal[i+a][j] = newsignal[i][j];
            }
        }
    }
    
    for (int i = 0; i < m*k; i++) {
        for (int j = 0; j < n*k; j++) {
            fout << newsignal[i][j];
        }
        fout << endl;
    }
    return 0;
}
