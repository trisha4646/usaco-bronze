/*
 USACO 2015 December Contest, Bronze
 Problem 2. Speeding Ticket
 http://www.usaco.org/index.php?page=viewproblem2&cpid=568
*/

#include <iostream>
#include <fstream>
using namespace std;
 
struct pairs {
    int distance;
    int limit;
};
 
int main() {
    ifstream fin ("speeding.in");
    ofstream fout ("speeding.out");
    int n, m;
    fin >> n >> m;
    pairs rules[n];
    pairs bessy[m];
    
    for (int i = 0; i < n; i++) {
        pairs c;
        fin >> c.distance >> c.limit;
        rules[i] = c;
    }
    for (int i = 0; i < m; i++) {
        pairs c;
        fin >> c.distance >> c.limit;
        bessy[i] = c;
    }
    
    int totalrules[100];
    int totalbessy[100];
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < rules[i].distance; j++) {
            totalrules[index] = rules[i].limit;
            index++;
        }
    }
    
    index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < bessy[i].distance; j++) {
            totalbessy[index] = bessy[i].limit;
            index++;
        }
    }
    
    int maxspeedlimit = 0;
    for (int i = 0; i < 100; i++) {
        if (totalrules[i] < totalbessy[i]) {
            maxspeedlimit = max((totalbessy[i] - totalrules[i]), maxspeedlimit);
        }
    }
    
    fout << maxspeedlimit << endl;
    return 0;
}
