#include <bits/stdc++.h>
using namespace std;

// Union Find: {rank, parent}
vector<pair<int, int> > mySet(1001, {0, -1});
vector<tuple<int, int, int> > edge;

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
    int N, M, a, b, weight; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> weight;
        edge.push_back({weight, a, b});
    }
    // MST: Kruskal's algorithm O (E * log(E))
    sort(edge.begin(), edge.end()); 
    int cnt = 0; int result = 0;
    for (int i = 0; i < M; i++) {
        int cost, v1, v2;
        tie(cost, v1, v2) = edge[i];
        if (Union(v1, v2)) { continue; }
        result += cost;
        if (++cnt == N - 1) { break; }
    }
    cout << result;
}