#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, x, y; cin >> N; pair<double, double> points[N];
    for (int i = 0; i < N; i++) {
        cin >> x >> y; points[i] = {x, y};
    }
    double A = 0;
    for (int i = 0; i < N; i++) { // Green Theorem
        auto p1 = points[i], p2 = points[(i + 1) % N];
        A += p2.first * p1.second - p1.first * p2.second;
    }
    cout << fixed << setprecision(1) << abs(A) / 2;
}