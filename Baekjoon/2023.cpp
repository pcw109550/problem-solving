#include<bits/stdc++.h>
using namespace std;
int N;

inline bool is_prime(int n) {
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

inline void iter(int n, int cnt) {
    if (cnt == N) {
        cout << n << '\n';
        return;
    }
    for (int i = 1; i < 10; i += 2) {
        int cand = n * 10 + i;
        if (is_prime(cand))
            iter(cand, cnt + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    iter(2, 1);
    iter(3, 1);
    iter(5, 1);
    iter(7, 1);
}   