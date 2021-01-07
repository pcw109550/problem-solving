#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N log(N))
    int N, temp, result = 0;
    priority_queue<int> pos;
    priority_queue<int, vector<int>, greater<int> > nonpos;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp > 0)
            pos.push(temp);
        else
            nonpos.push(temp);
    }
    while (pos.size() > 1) {
        int a = pos.top(); pos.pop();
        int b = pos.top(); pos.pop();
        result += a * b > a + b ? a * b : a + b;
    }
    if (pos.size() != 0)
        result += pos.top();
    while (nonpos.size() > 1) {
        int a = nonpos.top(); nonpos.pop();
        int b = nonpos.top(); nonpos.pop();
        result += a * b;
    }
    if (nonpos.size() != 0)
        result += nonpos.top();
    cout << result;
}