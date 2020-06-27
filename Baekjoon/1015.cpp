#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, temp; cin >> N;
    vector<int> input, result;
    for (int i = 0; i < N; i++) {
        cin >> temp; input.push_back(temp);
    }
    result = input;
    sort(result.begin(), result.end());
    bool visited[N] = {};
    for (auto it : input) {
        for (int i = 0; i < N; i++) {
            if (result[i] == it && !visited[i]) {
                visited[i] = true; cout << i << ' ';
                break;
            }
        }
    }
}