#include <bits/stdc++.h>
using namespace std;

// Union Find: {rank, parent}
vector<pair<int, int> > mySet(100, {0, -1});
vector<tuple<double, int, int> > edge;

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
    int N; cin >> N; double x, y; vector<pair<double, double> > Coord;
    for (int i = 0; i < N; i++) {
        cin >> x >> y; Coord.push_back({x, y});
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            x = Coord[i].first - Coord[j].first;
            y = Coord[i].second - Coord[j].second;
            edge.push_back({sqrt(x * x + y * y), i, j});
        }
    }
    // MST: Kruskal's algorithm O (E * log(E)) = O(N ** 2 * log(N))
    sort(edge.begin(), edge.end()); 
    int cnt = 0; double result = 0;
    for (int i = 0; i < N * (N - 1) / 2; i++) {
        double cost; int v1, v2;
        tie(cost, v1, v2) = edge[i];
        if (Union(v1, v2)) { continue; }
        result += cost;
        if (cnt == N - 1) { break; }
    }
    cout << result;
}