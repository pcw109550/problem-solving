#include <bits/stdc++.h>
using namespace std;
#define FIELD 1000000007

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long N; cin >> N;
    vector<long long> storage (N);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
    vector<long long> heights (N);
    vector<bool> visited (N, false);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
        Q.push({heights[i], i});
    }
    long long result = 1;
    while (!Q.empty()) {
        auto current = Q.top(); Q.pop();
        visited[current.second] = true;
        storage[current.second] = current.first;
        if (current.second - 1 >= 0 && visited[current.second - 1]) {
            long long Min = min(heights[current.second], heights[current.second - 1]);
            storage[current.second] = min(storage[current.second], Min);
        }
        if (current.second + 1 < N && visited[current.second + 1]) {
            long long Min = min(heights[current.second], heights[current.second + 1]);
            storage[current.second] = min(storage[current.second], Min);
        }
    }
    for (auto it : storage) {
        result *= it;
        result %= FIELD;
    }
    cout << result;
}