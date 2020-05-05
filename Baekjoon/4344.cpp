#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, N, acc, temp, cnt; cin >> T;
    double avg;
    while (T--) {
        acc = 0, cnt = 0;
        cin >> N; short score[N] = {};
        for (int i = 0; i < N; i++) {
            cin >> score[i]; acc += score[i];
        }
        double avg = (double)acc / (double)N;
        for (int i = 0; i < N; i++) {
            if (score[i] > avg) { cnt++; }
        }
        cout << fixed << setprecision(3) << (double)(100 * cnt) / N << "%\n";
    }
}