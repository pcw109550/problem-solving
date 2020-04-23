#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<bool> opts; vector<int> nums;
    char opt; int num, result = 0;
    while (true) {
        cin >> num;
        if (cin.eof()) { break; }
        cin >> opt;
        nums.push_back(num);
        opts.push_back(opt == '+');
    }
    auto it = nums.begin();
    bool minus = false;
    result += *it++;
    for (auto op = opts.begin(); op != opts.end(); op++) {
        if (minus) {
            result -= *it;
        } else {
            if (*op) { result += *it; }
            else     { result -= *it; minus = true; }
        }
        it++;
    }
    cout << result; 
}