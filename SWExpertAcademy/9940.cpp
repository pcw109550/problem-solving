#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, temp;
        bool check = true;
        cin >> N;
        bool input[N + 1];
        fill(input, input + N + 1, false);
        for (int i = 0; i < N; i++) {
            cin >> temp;
            input[temp] = true;
        }
        for (int i = 1; i <= N; i++) {
            if (!input[i]) {
                check = false;
                break;
            }
        }
        cout << '#' << t << ' ';
        cout << (check ? "Yes\n" : "No\n");
    }
}