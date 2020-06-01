#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    pair<int, int> input[8]; int score;
    for (int i = 0; i < 8; i++) {
        cin >> score; input[i] = {score, i};
    }
    sort(input, input + 8);
    int sum = 0;
    vector<int> idx;
    for (int i = 7; i >= 3; i--) {
        sum += input[i].first;
        idx.push_back(input[i].second);
    }
    cout << sum << '\n'; 
    sort(idx.begin(), idx.end());
    for (auto it: idx) {
        cout << it + 1 << ' ';
    }   
}