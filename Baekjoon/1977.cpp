#include <bits/stdc++.h>
using namespace std;

inline int isSquare(int x) {
    int root = (int)sqrt(x);
    return root * root == x;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int M, N; cin >> M >> N; int Min; bool found = false;
    int sum = 0;
    for (int i = M; i <= N; i++) {
        if (isSquare(i)) {
            if (!found) { found = true; Min = i; }
            sum += i;
        }
    }
    if (found) { cout << sum << '\n' << Min; }
    else { cout << -1; }
}