#include<bits/stdc++.h>
using namespace std;

inline int task(void) {
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if (x1 == x2 && y1 == y2)
        return r1 == r2 ? -1 : 0;
    int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    if (dist == (r1 + r2) * (r1 + r2))
        return 1;
    if (dist > (r1 + r2) * (r1 + r2))
        return 0;
    if (dist == (r1 - r2) * (r1 - r2))
        return 1;
    if (dist < (r1 - r2) * (r1 - r2))
        return 0;   
    return 2;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        cout << task() << '\n';
}   