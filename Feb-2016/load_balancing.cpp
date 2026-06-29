#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {

    ifstream fin("balancing.in");
    ofstream fout("balancing.out");


    vector<pair<int,int> > cows;
    int n; 
    int b;
    fin >> n >> b;
    for (int i = 0; i < n; i++){
        int x;
        int y;

        fin >> x >> y;
        cows.push_back({x, y});
    } 

    vector<pair<int,int>> cows_by_y = cows;
    sort(cows_by_y.begin(), cows_by_y.end(), [](auto& a, auto& b){
        return a.second < b.second;
    });


    int fence_x;
    int fence_y;

    int min_cows = 1e9;

    

    for (auto cow1 : cows) {
        fence_x = cow1.first+1;
        int below_count = 0;
        int left_below = 0;

        
        int total_left = 0;
        for (auto temp : cows_by_y) {
            if (temp.first < cow1.first) {
                total_left ++;
            }
        }

        
        for (auto cow2 : cows_by_y) {
            fence_y = cow2.second + 1;
            below_count ++;


            if (cow2.first < cow1.first) {
                left_below ++;
            }

            int q1 = total_left -  (left_below);
            int q2 = (n - total_left) - (below_count - left_below);
            int q3 = left_below;
            int q4 = below_count - left_below;

            min_cows = min(max(max(q1, q2), max(q3, q4)), min_cows);
        }

        

    }
    fout << min_cows << endl;

    fin.close();
    fout.close();
}