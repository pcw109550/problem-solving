#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; int input[N][5] = {};
    int cnt[N] = {};
    for (int i = 0; i < N; i++) {
        for (int grade = 0; grade < 5; grade++) {
            cin >> input[i][grade];
        }
    }
    bool cl[N][N] = {};
    for (int grade = 0; grade < 5; grade++) {
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (!cl[i][j] && input[i][grade] == input[j][grade]) {
                    cnt[i]++; cnt[j]++; cl[i][j] = cl[j][i] = true;
                }
            }
        }
    }
    cout << (max_element(cnt, cnt + N) - cnt + 1);
}