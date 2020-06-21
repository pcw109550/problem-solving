#include <bits/stdc++.h>
using namespace std;
int mat[100][100] = {};
int N, M, trial;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

void printmat() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << mat[i][j] << ' ';
        } cout << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int r, c, k; cin >> r >> c >> k; r--; c--;
    N = M = 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat[i][j];
        }
    }
    while (mat[r][c] != k && trial <= 100) {
        trial++;
        if (N >= M) {
            int newM = -1;
            for (int i = 0; i < N; i++) {
                int count[101] = {};
                for (int j = 0; j < M; j++) {
                    count[mat[i][j]]++;
                }
                vector<pair<int, int> > pairs;
                for (int j = 1; j <= 100; j++) {
                    if (count[j]) { pairs.push_back({j, count[j]}); }
                }
                sort(pairs.begin(), pairs.end(), compare);
                newM = max(newM, static_cast<int>(pairs.size() << 1));
                if (newM > 100) { newM = 100; }
                int len = pairs.size() > 50 ? 50 : pairs.size();
                for (int j = 0; j < len; j++) {
                    mat[i][j * 2] = pairs[j].first;
                    mat[i][j * 2 + 1] = pairs[j].second;
                }
                for (int j = len << 1; j < 100; j++) { mat[i][j] = 0; }
            }
            M = newM;
        } else {
            int newN = -1;
            for (int j = 0; j < M; j++) {
                int count[101] = {};
                for (int i = 0; i < N; i++) {
                    count[mat[i][j]]++;
                }
                vector<pair<int, int> > pairs;
                for (int i = 1; i <= 100; i++) {
                    if (count[i]) { pairs.push_back({i, count[i]}); }
                }
                sort(pairs.begin(), pairs.end(), compare);
                newN = max(newN, static_cast<int>(pairs.size() << 1));
                if (newN > 100) { newN = 100; }
                int len = pairs.size() > 50 ? 50 : pairs.size();
                for (int i = 0; i < len; i++) {
                    mat[i * 2][j] = pairs[i].first;
                    mat[i * 2 + 1][j] = pairs[i].second;
                }
                for (int i = len << 1; i < 100; i++) { mat[i][j] = 0; }
            }
            N = newN;
        }
    }
    cout << (trial > 100 ? -1 : trial);
}