/*
 USACO 2019 January Contest, Bronze
 Problem 1. Shell Game
 http://www.usaco.org/index.php?page=viewproblem2&cpid=891
*/

#include <iostream>
#include <set>
#include <fstream>
using namespace std;

int main() {
    ifstream fin ("shell.in");
    ofstream fout ("shell.out");
    int N;
    fin >> N;
    
    int beforelocation[N];
    int afterlocation[N];
    int guess[N];
    
    int b = 0, a = 0, g = 0;
    
    bool shell[3];
    bool temp;
    
    int correctguess[3];
    
    for (int i = 0; i < 3; i++) {
        correctguess[i] = 0;
    }
    
    int maxcorrectguess = 0;
    for (int i = 0; i < N; i++) {
        fin >> b >> a >> g;
        beforelocation[i] = b-1;
        afterlocation[i] = a-1;
        guess[i] = g-1;
    }
    
    for (int j = 0; j < 3; j++) {
        for (int c = 0; c < 3; c++) {
            shell[c] = false;
        }
        shell[j] = true;
        for (int a = 0; a < N; a++) {
            temp = shell[beforelocation[a]];
            shell[beforelocation[a]] = shell[afterlocation[a]];
            shell[afterlocation[a]] = temp;
            if (shell[guess[a]] == true) {
                correctguess[j] += 1;
            }
        }
    }
    maxcorrectguess = correctguess[0];
    for (int b = 0; b < 3; b++) {
        if (maxcorrectguess < correctguess[b]) {
            maxcorrectguess = correctguess[b];
        }
    }
    fout << maxcorrectguess << endl;
}
