#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N * log(N))
    string temp; cin >> temp;
    vector<string> input;
    for (int i = 0; i < temp.size(); i++)
        input.push_back(temp.substr(i, temp.size()));
    sort(input.begin(), input.end());
    for (auto it : input)
        cout << it << '\n';
}