/*
 USACO 2020 February Contest, Bronze
 Problem 1. Triangles
 http://www.usaco.org/index.php?page=viewproblem2&cpid=1011
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    ifstream fin ("triangles.in");
    ofstream fout ("triangles.out");
    int n;
    fin >> n;
    int pointsx[n];
    int pointsy[n];
    
    int xdist = 0, ydist = 0;
    int overalltotalarea = 0;
    
    for (int i = 0; i < n; i++) {
        fin >> pointsx[i] >> pointsy[i];
    }
    
    for (int i = 0; i < n; i++) {
        xdist = 0; ydist = 0;
        for (int a = 0; a < n; a++) {
            if ((i != a) && (pointsx[i] == pointsx[a])) {
                xdist = max(xdist, abs((pointsy[a] - pointsy[i])));
            }
            if ((i != a) && (pointsy[i] == pointsy[a])) {
                ydist = max(ydist, abs((pointsx[a] - pointsx[i])));
            }
        }
        overalltotalarea = max(overalltotalarea, xdist*ydist);
    }
    fout << overalltotalarea << endl;
    return 0;
}
