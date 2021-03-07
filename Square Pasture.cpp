/*
 USACO 2016 December Contest, Bronze
 Problem 1. Square Pasture
 http://usaco.org/index.php?page=viewproblem2&cpid=663
*/

#include <iostream>
#include <fstream>
#include <cmath>
 
using namespace std;
 
int main() {
    ifstream fin ("square.in");
    ofstream fout ("square.out");
    int points[2][4];
    
    for (int i = 0; i < 2; i++) {
        fin >> points[i][0] >> points[i][1] >> points[i][2] >> points[i][3];
    }
 
    int xmin = min(points[0][0], points[1][0]);
    int xmax = max(points[0][2], points[1][2]);
    int ymin = min(points[0][1], points[1][1]);
    int ymax = max(points[0][3], points[1][3]);
    
    int xdist, ydist, totaldist;
    xdist = abs(xmax - xmin);
    ydist = abs(ymax - ymin);
        
    totaldist = max(xdist, ydist);
    fout << (totaldist*totaldist) << endl;
    return 0;
}
