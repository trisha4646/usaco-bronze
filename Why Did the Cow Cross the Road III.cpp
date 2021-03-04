/*
 USACO 2017 February Contest, Bronze
 Problem 3. Why Did the Cow Cross the Road III
 http://www.usaco.org/index.php?page=viewproblem2&cpid=713
*/

#include <iostream>
#include <fstream>
#include <set>
using namespace std;

struct cow {
    int arrival;
    int duration;
};

bool cowcompare(const cow& a, const cow& b) {
    if (a.arrival < b.arrival) {
        return true;
    }
    else if (a.arrival == b.arrival) {
        if (a.duration <= b.duration) {
            return true;
        }
    }
    return false;
}


int main() {
    
    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");
    int n;
    fin >> n;
    set<cow, decltype(&cowcompare)> cowqueue(&cowcompare);
        
    for (int i = 0; i < n; i++) {
        cow c;
        fin >> c.arrival >> c.duration;
        cowqueue.insert(c);
    }
    
    long long time = 0;
    for (auto c: cowqueue) {
        if (time < c.arrival) {
            time = c.arrival + c.duration;
        }
        else {
            time += c.duration;
        }
    }
    
    fout << time << endl;
    return 0;
}
