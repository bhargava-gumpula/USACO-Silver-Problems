// incomplete
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> changes(n);
    for (int i = 0; i < n; i++) {
        cin >> changes[i];
    }
    changes.push_back(0);


    // we have n ( the number of changes and the size of the number line)
    // we have changes (containing all the changes)
    
    string path = "";
    string fav = "R";
    int location = 0;

    while (true) {
        
        if (location == 0 && changes[location] == 0) {
            cout << path << endl;
            break;
        }
        
        while (changes[location] != 0) {
            path += "R";
            changes[location] --;
            location ++;
        }
        
        location --;
        
        while (location > 0) {
            
            if (changes[location] > 1) {
                path += "L";
                changes[location] --;
                if (changes[location-1] != 1) {
                    location --;
                }
                else {
                    break;
                }
            }
            
            else if (changes[location] == 1 && changes[location+1] == 0) {
                path += "L";
                changes[location] --;
                location --;
            }
            
            
            
        }
        
        if (changes[location] == 1 && changes[location+1] == 0) {
            path += "L";
            changes[location] --;
        }
    }  
}