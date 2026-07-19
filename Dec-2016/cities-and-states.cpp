#include <stdio.h>
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int main() {

    ifstream fin("citystate.in");
    ofstream fout("citystate.out");

    int n;
    fin >> n;

    unordered_map<string, int> states;   // 

    int count = 0;
    for (int i = 0; i < n; i++) {
        string city;
        string state;
        fin >> city >> state;
        city = city.substr(0, 2);

        // first time city = "MI"
        //            state = "FL"
        
        
        if (states.count(state+city) == 1) {
            if (city != state) {
                count += states[state+city];
            } 
        }
        states[city+state] ++;     
    }

    fout << count << endl;

    fin.close();
    fout.close();
}