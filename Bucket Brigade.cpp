/*
 USACO 2019 US Open Contest, Bronze
 Problem 1. Bucket Brigade
 http://www.usaco.org/index.php?page=viewproblem2&cpid=939
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin ("buckets.in");
    ofstream fout ("buckets.out");
    char map[10][10];
    char value;
    int Bx = 0, By = 0, Lx = 0, Ly = 0, Rx = 0, Ry = 0;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fin >> value;
            map[i][j] = value;
        }
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 'B') {
                Bx = i;
                By = j;
            }
            else if (map[i][j] == 'L') {
                Lx = i;
                Ly = j;
            }
            else if (map[i][j] == 'R') {
                Rx = i;
                Ry = j;
            }
        }
    }
    
    int total = (((abs(Bx-Lx)) + (abs(By-Ly))) - 1);
    
    if (((Bx-Lx) == 0) && (Bx == Rx)) {
        if (((Ry < By) && (Ry > Ly)) || ((Ry > By) && (Ry < Ly))) {
            total += 2;
        }
    }
    else if (((By-Ly) == 0) && (By == Ry)) {
        if (((Rx < Bx) && (Rx > Lx)) || ((Rx > Bx) && (Rx < Lx))) {
            total += 2;
        }
    }
        
    fout << total << endl;
    return 0;
}

