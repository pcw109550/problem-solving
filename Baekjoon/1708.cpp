#include<bits/stdc++.h>
using namespace std;
struct Point {
    int x, y, p, q;
};

bool comp(const Point &A, const Point &B) {
    if (1LL * A.q * B.p != 1LL * A.p * B.q)
        return 1LL * A.q * B.p < 1LL * A.p * B.q;
    if (A.y != B.y)
        return A.y < B.y;
    return A.x < B.x;
}

bool ccw(const Point &A, const Point &B, const Point &C) {
    return 1LL * (A.x - B.x) * (C.y - B.y) < 1LL * (A.y - B.y) * (C.x - B.x);
}

int main(void) {
    // Convex Hull: Graham Scan: O(N log(N))
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, x, y, first, second; cin >> N;
    Point points[N] = {};
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        points[i].x = x;
        points[i].y = y;
    }
    sort(points, points + N, comp);
    for (int i = 1; i < N; i++) {
        points[i].p = points[i].x - points[0].x;
        points[i].q = points[i].y - points[0].y;
    }
    sort(points + 1, points + N, comp);
    stack<int> S;
    S.push(0); S.push(1);
    int next = 2;
    while (next < N) {
        while (S.size() >= 2) {
            second = S.top(); S.pop();
            first = S.top();
            if (ccw(points[first], points[second], points[next]) > 0) {
                S.push(second);
                break;
            }
        }
        S.push(next++);
    }
    cout << S.size();
}