#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin >> N >> K;
    bool visited[MAX] = {};
    queue<pair<int, int>> Q; int result = 0;
    Q.push({N, 0}); visited[N] = true;
    int trace[MAX] = {};
    while (!Q.empty()) {
        pair<int, int> current = Q.front();
        int out = current.first;
        int distance = current.second + 1;
        if (out == K) { result = current.second; break;}
        Q.pop();
        if (out + 1 <= MAX - 1 && !visited[out + 1]) {
            Q.push({out + 1, distance}); visited[out + 1] = true; trace[out + 1] = out;
        }
        if (out - 1 >= 0 && !visited[out - 1]) {
            Q.push({out - 1, distance}); visited[out - 1] = true; trace[out - 1] = out;
        }
        if (2 * out <= MAX - 1 && !visited[2 * out]) {
            Q.push({2 * out, distance}); visited[2 * out] = true; trace[2 * out] = out;
        }
    }
    cout << result << "\n";
    int track[result] = {}; track[0] = K;
    for (int i = 1; i < result + 1; i++) {
        track[i] = trace[track[i - 1]];
    }
    for (int i = result ; i >= 0; i--) {
        cout << track[i];
        if (i != 0) { cout << " "; }
    }
}