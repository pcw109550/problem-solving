#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, K, a, b, c, result = 0; cin >> N >> M >> K;
    vector<unordered_map<int, int> > score (N, unordered_map<int, int>());
    for (int i = 0; i < K; i++) {
        cin >> a >> b >> c;
        if (a > b)
            continue;
        a--; b--;
        score[b][a] = max(score[b][a], c);
    }
    vector<vector<int> > D(N, vector<int> (M, 0));
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            for (auto s : score[i]) {
                int start = s.first;
                int cost = s.second;
                if (D[start][j - 1] == 0) {
                    if (start != 0)
                        continue;
                    if (j > 1)
                        continue;
                }
                D[i][j] = max(D[i][j], D[start][j - 1] + cost);
            }
        }
    }
    for (int j = 0; j < M; j++)
        result = max(result, D[N - 1][j]);
    cout << result;
}