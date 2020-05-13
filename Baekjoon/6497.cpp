#include <bits/stdc++.h>
using namespace std;

// Union Find: {rank, parent}
vector<pair<int, int> > mySet(200000, {0, -1});
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
    while (true) {
        fill(mySet.begin(), mySet.end(), make_pair(0, -1));
        edge = vector<tuple<int, int, int> >();
        int M, N, a, b, weight; cin >> M >> N;
        if (M == 0 && N == 0) { return 0; }
        int cnt = 0; int Min = 0, Max = 0;
        for (int i = 0; i < N; i++) {
            cin >> a >> b >> weight; Max += weight;
            edge.push_back({weight, a, b});
        }
        // MST: Kruskal's algorithm O (E * log(E))
        sort(edge.begin(), edge.end()); 
        for (int i = 0; i < N; i++) {
            int cost, v1, v2;
            tie(cost, v1, v2) = edge[i];
            if (Union(v1, v2)) { continue; }
            Min += cost;
            if (++cnt == M - 1) { break; }
        }
        cout << Max - Min << '\n';
    }
}