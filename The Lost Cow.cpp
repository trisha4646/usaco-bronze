/*
 USACO 2017 US Open Contest, Bronze
 Problem 1. The Lost Cow
 http://www.usaco.org/index.php?page=viewproblem2&cpid=735
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");
    
    int johnoriginalposition, bessieposition;
    int change = 1;
    int distance = 0;
    
    fin >> johnoriginalposition >> bessieposition;
    int johnposition = johnoriginalposition;

    while (johnposition != bessieposition) {
        distance += (0.5 * abs(change));
        johnposition = johnoriginalposition;
        
        for (int i = 0; i < abs(change); i++) {
            if (abs(change) == change) {
                johnposition += 1;
            }
            else {
                johnposition -= 1;
            }
            distance += 1;
            if (johnposition == bessieposition) {
                break;
            }
        }
       change *= -2;
    }
    fout << distance << endl;
}
