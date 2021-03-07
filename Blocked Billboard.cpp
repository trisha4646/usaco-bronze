/*
 USACO 2017 December Contest, Bronze
 Problem 1. Blocked Billboard
 http://www.usaco.org/index.php?page=viewproblem2&cpid=759
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;
 
int main() {
    ifstream fin ("billboard.in");
    ofstream fout ("billboard.out");
    bool locations[2000][2000];
    int items[3][4];
    
    for (int i = 0; i < 3; i++) {
        //x1 value
        fin >> items[i][0];
        //y1 value
        fin >> items[i][1];
        //x2 value
        fin >> items[i][2];
        //y2 value
        fin >> items[i][3];
    }
   
    for (int i = items[0][0]; i < items[0][2]; i++) {
        for (int j = items[0][1]; j < items[0][3]; j++) {
            locations[i+1000][j+1000] = true;
        }
    }
    for (int i = items[1][0]; i < items[1][2]; i++) {
        for (int j = items[1][1]; j < items[1][3]; j++) {
            locations[i+1000][j+1000] = true;
        }
    }
    for (int i = items[2][0]; i < items[2][2]; i++) {
        for (int j = items[2][1]; j < items[2][3]; j++) {
            locations[i+1000][j+1000] = false;
        }
    }
    
    int count = 0;
    for (int i = items[0][0]; i < items[0][2]; i++) {
        for (int j = items[0][1]; j < items[0][3]; j++) {
            if (locations[i+1000][j+1000] == true) {
                count++;
            }
        }
    }
    
    for (int i = items[1][0]; i < items[1][2]; i++) {
        for (int j = items[1][1]; j < items[1][3]; j++) {
            if (locations[i+1000][j+1000] == true) {
                count++;
            }
        }
    }
    
    fout << count << endl;
    return 0;
}
