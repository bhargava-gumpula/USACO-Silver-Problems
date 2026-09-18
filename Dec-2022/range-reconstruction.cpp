// incomplete
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<vector<int>> relate(n);

    for (int i = 0; i < n; i++) {
        vector<int> row(n-1-i);
        for (int j = 0; i < n-1-i; j++) {
            cin >> row[j];
        }
    }

    for (int i = 0; i < n; i++) {
        vector<int> row = relate[i];
        for (int j = 0; j < row.size(); j++) {
            cout << row[j];
        }
        cout << endl;
    }
}