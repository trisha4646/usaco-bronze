/*
 USACO 2018 January Contest, Bronze
 Problem 2. Lifeguards
 http://www.usaco.org/index.php?page=viewproblem2&cpid=784
*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
 
void resetShifts(bool arr[]) {
    for (int i = 0; i < 1000; ++i) {
        arr[i] = false;
    }
}
 
int countbookedShifts(bool arr[]) {
    int bookedshifts = 0;
    for (int i = 0; i < 1000; ++i) {
        if (arr[i] == true) {
            bookedshifts++;
        }
    }
    return bookedshifts;
}
 
 
int main() {
    ifstream fin ("lifeguards.in");
    ofstream fout ("lifeguards.out");
    int n;
    fin >> n;
    int shifts[n][2];
    bool timeslots[1000];
    
    for (int i = 0; i < n; i++) {
        fin >> shifts[i][0] >> shifts[i][1];
    }
    
    int maxbookedshifts = 0;
    resetShifts(timeslots);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                for (int a = shifts[j][0]; a < shifts[j][1]; a++) {
                    timeslots[a] = true;
                }
            }
        }
        maxbookedshifts = max(maxbookedshifts, countbookedShifts(timeslots));
        resetShifts(timeslots);
    }
    
    fout << maxbookedshifts << endl;
    return 0;
}
