/*
 USACO 2020 January Contest, Bronze
 Problem 2. Photoshoot
 http://www.usaco.org/index.php?page=viewproblem2&cpid=988
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <set>
using namespace std;
 
int main() {
    ifstream fin ("photo.in");
    ofstream fout ("photo.out");
    int n;
    fin >> n;
    
    int input[n-1];
    int output[n];
    for (int i = 0; i < n-1; i++) {
        fin >> input[i];
    }
    
    for (int j = 1; j < input[0]; j++) {
        output[0] = j;
        set <int> values;
        values.insert(output[0]);
        for (int i = 1; i < n; i++) {
            output[i] = input[i-1] - output[i-1];
            if (output[i] < 1) {
                break;
            }
            values.insert(output[i]);
        }
        if (values.size() == n) {
            for (int i = 0; i < n-1; i++) {
                fout << output[i] << " ";
            }
            fout << output[n-1];
            return 0;
        }
    }
}
