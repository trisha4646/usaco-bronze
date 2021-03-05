/*
 USACO 2016 January Contest, Bronze
 Problem 3. Mowing the Field
 http://www.usaco.org/index.php?page=viewproblem2&cpid=593
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct mowed {
    bool mowed;
    int time;
};

mowed grasses[1000][1000];
int beforetime[1000][1000];

int main() {
    ifstream fin("mowing.in");
    ofstream fout("mowing.out");
    int n;
    fin >> n;
    string direction;
    int amount;
    
    int xdir = 500;
    int ydir = 500;
    int time = 1;
    
    vector<int> xvalues;
    
    for (int i = 0; i < n; i++) {
        fin >> direction >> amount;
        for (int j = 0; j < amount; j++) {
            if (grasses[xdir][ydir].mowed == true) {
                beforetime[xdir][ydir] = grasses[xdir][ydir].time;
                xvalues.push_back((time - beforetime[xdir][ydir]));
            }
             
            grasses[xdir][ydir].mowed = true;
            grasses[xdir][ydir].time = time;
            
            if (direction == "N") {
                ydir = ydir + 1;
                time++;
            }
            if (direction == "S") {
                ydir = ydir - 1;
                time++;
            }
            if (direction == "E") {
                xdir = xdir + 1;
                time++;
            }
            if (direction == "W") {
                xdir = xdir - 1;
                time++;
            }
        }
    }
    
    if (xvalues.size() == 0) {
        fout << "-1" << endl;
    }
    else {
        int min = xvalues.at(0);
        for (int a = 0; a < xvalues.size(); a++) {
            if (xvalues.at(a) < min) {
                min = xvalues.at(a);
            }
        }
        fout << min << endl;
    }
}
