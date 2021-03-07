/*
 USACO 2017 December Contest, Bronze
 Problem 3. Milk Measurement
 http://www.usaco.org/index.php?page=viewproblem2&cpid=761
*/

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;

struct entry {
    int day;
    string name;
    int change;
};
 
bool entrycompare(entry a, entry b) {
    if (a.day < b.day) {
        return true;
    }
    return false;
}
 
#define BESSIE 0
#define MILRED 1
#define ELSIE  2
 
int main() {
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");
    
    int total = 0;
    int cows[3];
    set<int> cows_on_board;
    for (auto i: {0,1,2}) {
        cows[i] = 7;
    }
 
    int n;
    fin >> n;
    set<entry, decltype(&entrycompare)> entries(&entrycompare);
    for (int i = 0; i < n; i++) {
        entry c;
        fin >> c.day >> c.name >> c.change;
        entries.insert(c);
    }
    
    for (auto entry: entries) {
       if (entry.name == "Bessie") {
            cows[BESSIE] += entry.change;
        }
        else if (entry.name == "Mildred") {
            cows[MILRED] += entry.change;
        }
        else if (entry.name == "Elsie") {
            cows[ELSIE] += entry.change;
        }
        
        int max = cows[BESSIE];
        for (auto cow: cows) {
            if (cow > max) {
                max = cow;
            }
        }
        set<int> new_cows_on_board;
        for (int i = 0; i < 3; i++) {
            if (cows[i] == max) {
                new_cows_on_board.insert(i);
                cout << i;
            }
        }
        if (cows_on_board != new_cows_on_board) {
            total++;
            cows_on_board = new_cows_on_board;
        }
    }
    fout << total << endl;
}
