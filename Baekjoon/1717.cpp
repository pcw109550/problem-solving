#include <bits/stdc++.h>
using namespace std;

// Union Find
// {rank, parent}
// By maintaining rank, I get a balanced tree
vector<pair<int, int> > mySet(1000001, {0, -1});

int Find(int x) {
    if (mySet[x].second < 0) { return x; }
    // Path compression
    return mySet[x].second = Find(mySet[x].second);
}

void Union(int x, int y) {
    // O(invack(N))
    int X = Find(x);
    int Y = Find(y);
    if (X == Y) { return; }
    if (mySet[X].first < mySet[Y].first) {
        swap(X, Y);
    }
    mySet[Y].second = X;
    if (mySet[X].first == mySet[Y].first) {
        mySet[X].first++;
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, opt, x, y; cin >> N >> M;
    while (M--) {
        cin >> opt >> x >> y;
        if (opt) {
            cout << (Find(x) == Find(y) ? "YES\n" : "NO\n");
        } else {
            Union(x, y);
        }
    }
}