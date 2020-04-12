#include <bits/stdc++.h>
using namespace std;

inline void isPerfect(int N) {
    int acc = 0; vector<int> divisor;
    for (int i = 1; i < N; i++) {
        if (N % i == 0) {
            acc += i;
            divisor.push_back(i);
        }
    }
    if (acc == N) {
        cout << N << " =";
        auto it = divisor.begin();
        while (true) {
            cout << ' ' << *it; it++;
            if (it != divisor.end()) { cout << " +"; }
            else { cout << '\n'; break; }
        }
    } else {
        cout << N << " is NOT perfect.\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    while (true) {
        cin >> N; if (N == -1) { return 0; }
        isPerfect(N);
    }

}