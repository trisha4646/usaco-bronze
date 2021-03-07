/*
 USACO 2019 January Contest, Bronze
 Problem 3. Guess the Animal
 http://www.usaco.org/index.php?page=viewproblem2&cpid=893
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
 
struct animal {
    string name;
    int numofchars;
    vector<string> characteristics;
};
 
int main() {
    ifstream fin("guess.in");
    ofstream fout("guess.out");
    int n;
    fin >> n;
    
    animal animals[n];
    for (int i = 0; i < n; i++) {
        animal b;
        fin >> b.name >> b.numofchars;
        for (int j = 0; j < b.numofchars; j++) {
            string a;
            fin >> a;
            b.characteristics.push_back(a);
        }
        animals[i] = b;
    }
    int maxcount = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int count = 0;
            for (int a = 0; a < animals[i].numofchars; a++) {
                for (int b = 0; b < animals[j].numofchars; b++) {
                    if (animals[i].characteristics.at(a) == animals[j].characteristics.at(b)) {
                        count++;
                    }
                }
            }
            maxcount = max(maxcount, count);
        }
    }
    
    fout << (maxcount+1) << endl;
    return 0;
}
