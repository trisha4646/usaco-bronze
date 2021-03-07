/*
 USACO 2019 February Contest, Bronze
 Problem 1. Sleepy Cow Herding
 http://www.usaco.org/index.php?page=viewproblem2&cpid=915
*/

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;
 
int main() {
    ifstream fin ("herding.in");
    ofstream fout ("herding.out");
    multiset<int> orderedcows;
    
    int t;
    for (int i = 0; i < 3; i++) {
        fin >> t;
        orderedcows.insert(t);
    }
    
    vector <int> cows;
    cows.reserve (orderedcows.size ());
    copy (orderedcows.begin (), orderedcows.end (), back_inserter (cows));
    
    int dist[2];
    for (int i = 1; i < 3; i++) {
        dist[i-1] = cows[i] - cows[i-1];
    }
    
    int minmoves = -1, maxmoves = -1;
    if ((dist[0] == 1) && (dist[1] == 1)) {
        minmoves = 0;
        maxmoves = 0;
    }
    else if ((dist[0] == 2) || (dist[1] == 2)) {
        minmoves = 1;
    }
    else {
        minmoves = 2;
    }
    
    if ((dist[0] == 1) && (dist[1] == 1)) {
        maxmoves = 0;
    }
    else {
        int maxxerdist = max(dist[0], dist[1]);
        maxmoves = maxxerdist - 1;
    }
    
    fout << minmoves << endl << maxmoves << endl;
    return 0;
}
