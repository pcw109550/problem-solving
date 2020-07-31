#include<bits/stdc++.h>
using namespace std;

inline void printResult(int trial, int result) {
    cout << '#' << trial << ' ';
    cout << result << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, result = 0;
        string s;
        cin >> N;
        int chset[N][26];
        fill(*chset, *chset + N * 26, NULL);
        for (int i = 0; i < 3; i++) {
            cin >> s;
            for (int j = 0; j < N; j++)
                chset[j][s[j] - 'a']++;
        }
        for (int i = 0; i < N; i++) {
            int Max = -1;
            for (int j = 0; j < 26; j++)
                Max = max(Max, chset[i][j]);
            if (Max != 0 && Max != 3)
                result += 3 - Max;
        }
        printResult(t, result);
    }
}