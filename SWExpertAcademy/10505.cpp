#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, sum = 0, result = 0;
        cin >> N;
        int input[N];
        for (int i = 0; i < N; i++) {
            cin >> input[i];
            sum += input[i];
        }
        for (int i = 0; i < N; i++)
            if (sum >= N * input[i])
                result++;
        cout << '#' << t << ' ';
        cout << result << '\n';
    }
}