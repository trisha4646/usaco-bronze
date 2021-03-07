/*
 USACO 2018 December Contest, Bronze
 Problem 1. Mixing Milk
 http://www.usaco.org/index.php?page=viewproblem2&cpid=855
*/

#include <iostream>
#include <fstream>
#include <array>
using namespace std;
 
int main() {
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");
    
    long long capacities[3];
    long long milkamt[3];
    long long c, m;
    long long amt;
    
    for (int i = 0; i < 3; i++) {
        fin >> c >> m;
        capacities[i] = c;
        milkamt[i] = m;
    }
    
    for (int i = 0; i < 100; i++) {
        amt = min(milkamt[i%3], (capacities[((i+1)%3)] - milkamt[((i+1)%3)]));
        milkamt[i%3] = milkamt[i%3] - amt;
        milkamt[(i+1)%3] = milkamt[(i+1)%3] + amt;
    }
    
    for (int i = 0; i < 3; i++) {
        fout << milkamt[i] << endl;
    }
}
