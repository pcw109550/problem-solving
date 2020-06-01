#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N; int score[N + 1] = {};
    for (int i = 1; i <= N; i++) { cin >> score[i]; }
    sort(score + 1, score + N + 1);
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += (long long)abs(i - score[i]);
    }
    cout << sum;
}