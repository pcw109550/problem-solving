#include<bits/stdc++.h>
using namespace std;
int result;

inline void task(void) {
    string s;
    cin >> s;
    stack<char> S;
    for (auto it : s){
        if (S.empty())
            S.push(it);
        else {
            if (S.top() != it) {
                S.push(it);
            } else {
                S.pop();
            }
        }
    }
    if (S.empty())
        result++;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    while (N--)
        task();
    cout << result;
}   