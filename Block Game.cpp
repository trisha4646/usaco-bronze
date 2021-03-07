/*
 USACO 2016 December Contest, Bronze
 Problem 2. Block Game
 http://usaco.org/index.php?page=viewproblem2&cpid=664
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
int main() {
    ifstream fin ("blocks.in");
    ofstream fout ("blocks.out");
    int n;
    fin >> n;
    
    string boards[2][n];
    for (int i = 0; i < n; i++) {
        fin >> boards[0][i] >> boards[1][i];
    }
    
    int alphabet[n][26][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 3; k++) {
                alphabet[i][j][k] = 0;
            }
        }
    }
    
    //for every board (box of two letters)
    for (int i = 0; i < n; i++) {
        //for every letter in that board/box #1
        for (int a = 0; a < boards[0][i].length(); a++) {
            char c = boards[0][i].at(a);
            int t = int(c);
            alphabet[i][t-97][0]++;
        }
        for (int a = 0; a < boards[1][i].length(); a++) {
            char c = boards[1][i].at(a);
            int t = int(c);
            alphabet[i][t-97][1]++;
        }
        for (int a = 0; a < 26; a++) {
            alphabet[i][a][2] = max(alphabet[i][a][0], alphabet[i][a][1]);
        }
    }
    for (int j = 0; j < 26; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += alphabet[i][j][2];
        }
        fout << sum << endl;
    }
}
