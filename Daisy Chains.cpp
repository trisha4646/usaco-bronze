/*
 USACO 2020 December Contest, Bronze
 Problem 2. Daisy Chains
 http://usaco.org/index.php?page=viewproblem2&cpid=1060
*/

#include <iostream>
using namespace std;
const int MAXN = 100;
int flowers[MAXN];

bool findflower(double avg, int i, int j) {
    for (int a = i; a <= j; a++) {
        if (flowers[a] == avg) {
            return true;
        }
    }
    return false;
}
 
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> flowers[i];
    }
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int a = i; a <= j; a++) {
                sum+= flowers[a];
            }
            double avg = double(sum)/double(j-i+1);
            if (findflower(avg, i, j) == true) {
                count++;
            }
        }
    }
    cout << count << endl;
}
