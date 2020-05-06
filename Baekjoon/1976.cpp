#include <bits/stdc++.h>
using namespace std;

// Union Find: {rank, parent}
vector<pair<int, int> > mySet(200, {0, -1});

int Find(int x) {
    if (mySet[x].second < 0) { return x; }
    // Path compression
    return mySet[x].second = Find(mySet[x].second);
}

bool Union(int x, int y) {
    // O(invack(N))
    int X = Find(x);
    int Y = Find(y);
    if (X == Y) { return true; }
    if (mySet[X].first < mySet[Y].first) {
        swap(X, Y);
    }
    mySet[Y].second = X;
    if (mySet[X].first == mySet[Y].first) {
        mySet[X].first++;
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, temp; cin >> N >> M;
    bool possible = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> temp;
            if (temp) {
                Union(i, j);
            }
        }
    }
    int plan;
    cin >> temp; M--;
    while (M--) {
        cin >> plan;
        if (!Union(temp, plan)) {
            possible = false;
            break;
        }
        temp = plan;
    }
    cout << (possible ? "YES" : "NO");
}