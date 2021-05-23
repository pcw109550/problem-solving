#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    double result = 0.0;
    int N, M, temp; cin >> N >> M;
    unordered_map<int, vector<int> > Map;
    for (int i = 0; i < M; i++) {
        int size; cin >> size;
        for (int j = 0; j < size; j++) {
            cin >> temp;
            Map[temp].push_back(size);
        }
    }
    int min_max = INT_MIN;
    for (auto it : Map) {
        int Min = INT_MAX;
        for (auto c : it.second)
            Min = min(Min, c);
        min_max = max(min_max, Min);
    }
    result = min_max - 1;
    result /= min_max;
    cout << setprecision(10) << result;
}