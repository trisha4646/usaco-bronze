/*
 USACO 2016 February Contest, Bronze
 Problem 3. Load Balancing
 http://www.usaco.org/index.php?page=viewproblem2&cpid=617
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <cmath>
#include <iterator>
using namespace std;
 
struct point {
    int xvalue;
    int yvalue;
};
 
bool pointcompare(const point& a, const point& b) {
    if (a.xvalue == b.xvalue) {
        return(a.yvalue <= b.yvalue);
    }
    return(a.xvalue < b.xvalue);
}
 
set<point, decltype(&pointcompare)> points(&pointcompare);
 
int findhighestmax(int xline, int yline) {
    int Mvals[4] = {0};
    for (auto it = points.begin(); it != points.end(); it++) {
        if ((*it).xvalue < xline) {
            if ((*it).yvalue < yline) {
                Mvals[0]++;
            }
            else if ((*it).yvalue > yline) {
                Mvals[1]++;
            }
        }
        else if ((*it).xvalue > xline) {
            if ((*it).yvalue < yline) {
                Mvals[2]++;
            }
            else if ((*it).yvalue > yline) {
                Mvals[3]++;
            }
        }
    }
    
    int maxinnerM = Mvals[0];
    maxinnerM = max(maxinnerM, Mvals[1]);
    maxinnerM = max(maxinnerM, Mvals[2]);
    maxinnerM = max(maxinnerM, Mvals[3]);
    
    return maxinnerM;
}
 
 
int main() {
    
    ifstream fin ("balancing.in");
    ofstream fout ("balancing.out");
    int n, b;
    fin >> n >> b;
    set<int> xvalues;
    set<int> yvalues;
    
    for (int i = 0; i < n; i++) {
        point c;
        fin >> c.xvalue >> c.yvalue;
        xvalues.insert(c.xvalue);
        yvalues.insert(c.yvalue);
        points.insert(c);
    }
    
    int minM = n;
    for (auto xval:xvalues) {
        for (auto yval:yvalues) {
            int x = xval;
            int y = yval;
            x++;
            y++;
            minM = min(findhighestmax(x, y), minM);
        }
    }
    
    fout << minM;
    return 0;
}
