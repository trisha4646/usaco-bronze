/*
 USACO 2019 December Contest, Bronze
 Problem 3. Livestock Lineup
 http://www.usaco.org/index.php?page=viewproblem2&cpid=965
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
struct constraint {
    string cow1;
    string cow2;
};
 
bool testorder(string cowsorder[], constraint constraints[], int n) {
    int indexofcow1 = 0;
    int indexofcow2 = 0;
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            if (cowsorder[j] == constraints[i].cow1) {
                indexofcow1 = j;
            }
            else if (cowsorder[j] == constraints[i].cow2) {
                indexofcow2 = j;
            }
        }
        for (int j = 0; j < 8; j++) {
            if (abs(indexofcow2 - indexofcow1) != 1) {
                return false;
            }
        }
    }
    return true;
}
 
int main() {
    string cows[8] = {"Beatrice", "Belinda",  "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    
    ifstream fin ("lineup.in");
    ofstream fout ("lineup.out");
    int n;
    fin >> n;
    
    constraint constraints[n];
    for (int i = 0; i < n; i++) {
        string t;
        fin >> constraints[i].cow1 >> t >> t >> t >> t >> constraints[i].cow2;
    }
    
    while (true) {
        if ((testorder(cows, constraints, n) == true)) {
            fout << cows[0] << "\n" << cows[1] << "\n" << cows[2] << "\n" << cows[3] << "\n" << cows[4] << "\n" << cows[5] << "\n" << cows[6] << "\n" << cows[7];
            return 0;
        }
        else {
            next_permutation(cows, cows+8);
        }
    }
    return 0;
}
